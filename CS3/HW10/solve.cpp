#include<iostream> //for print testing 
#include "solve.h"
#include "vertex.h"


//Runtime : O(s*log(s))
//Parsing and graph creation : O(s)
//Dijsktra's : O(log s)
string solve(string maze) {

    //graph structure via vertex class -- now with portals 
    vector<vector<Vertex*>> matrixMaze; 
    unordered_map<char, vector<Vertex*>> portals; //portal map | '0' - '9'

    //get strlen to parse 
    int inputLen = maze.length();

    //make row and col -- for graph
    int row = 0;
    int col = 0;

    matrixMaze.push_back(vector<Vertex*>()); // add first row to start   

    //Step 1 :: make graph with string input parsing 
    for(int i=0;i<inputLen;i++) {     //through each char  - O(s)

    //first check if newline char -- move to next row 
    if (maze[i] == '\n') {
       if (i < inputLen - 1) { //if not last '\n' 
       row++;
       col = 0; //restart cols 
       matrixMaze.push_back(vector<Vertex*>()); // add a new row 
       }
       continue; //avoid extra col  
    }
   
    //create location in graph 
    matrixMaze[row].push_back(nullptr); //- push next [][col]

    if(maze[i]==' ') 
        matrixMaze[row][col] = new Vertex(row,col); //traversable vertex 

    if(maze[i]=='#') 
        matrixMaze[row][col] = nullptr; //cant travsere -- wall 

     
    if(maze[i] >= '0' && maze[i] <='9') {   //check for portal
        //make a vertex + add to portal map 
        matrixMaze[row][col] = new Vertex(row,col); //traversable portal
        portals[maze[i]].push_back(matrixMaze[row][col]); //map portal as the current vertex 

    }
            
    col++; //update to move to next col 
    }

    //Step 2 :: fill neigh vectors -- traverse matrix
    row = matrixMaze.size();
    col = matrixMaze[0].size();  //reuse vars -> update because held indexes (off by 1)

    //make vars for start/end 
    Vertex* start = nullptr;
    Vertex* exit = nullptr;

    //collect traverable vertexes 
    vector<Vertex*> vertices;

    for(int r=0;r<row;r++) { // O(r) - shouldnt affect runtime 
        for(int c=0;c<col;c++){  //O(c) --- O(r*c) can simplify to O(s)
            //check if traverable spot 
            Vertex* temp = matrixMaze[r][c];
            if(!temp) continue; //ignore walls - no neighbors we care ab 

            //add to traverable vector 
            vertices.push_back(temp);

            //find exits -- first space should be start 
            if(r==0||r==row-1||c==0||c==col-1){ //checks edge borders only 
                if(!start) start=temp;
                else if(!exit) exit=temp; 
            }
                                //given [r][c]
            //above (r-1)
            if(r>0&&matrixMaze[r-1][c]) temp->neighs.push_back({matrixMaze[r-1][c],1});
            //below (r+1)
            if(r<row-1&&matrixMaze[r+1][c]) temp->neighs.push_back({matrixMaze[r+1][c],1});
            //left (c-1)
            if(c>0&&matrixMaze[r][c-1]) temp->neighs.push_back({matrixMaze[r][c-1],1});
            //right (c+1)
            if(c<col-1&&matrixMaze[r][c+1]) temp->neighs.push_back({matrixMaze[r][c+1],1});

        }
    } 

    //cout << "Start: (" << start->row << "," << start->col << ")\n";
    //cout << "Exit:  (" << exit->row << "," << exit->col << ")\n";

    //cout << "Neighbors of exit:\n";
    //for (auto [v, w] : exit->neighs) {
    //    cout << "  (" << v->row << "," << v->col << ") weight " << w << '\n';
    //}


    //Step 3:: connect portals to one another 
    for(const auto& [weight,portConnect] : portals) {
        if(portConnect.size()==2) { //make sure portals were mapped correctly 
            Vertex* pStart = portConnect[0];
            Vertex* pEnd = portConnect[1];

            pStart->neighs.push_back({pEnd,weight - '0'});
            pEnd->neighs.push_back({pStart,weight - '0'});
        }

    }

    //Step 4:: find shortest path ...YAYA DIJKSTRA 
    MinPriorityQueue<Vertex*> findShortestPath; 
    unordered_map<Vertex*,int> pathDistance; //holds path distance (shortest)
    unordered_map<Vertex*,Vertex*> parents; //my breadcrumbs 

    //insert all vertices into the minQueue 
    for(Vertex* v: vertices) {
        if(v==start){
            pathDistance[start] = 0; //start distace is zero 
            findShortestPath.push(start,0); //push with weight/cost zero 
        }else{
            pathDistance[v]= INT_MAX;
            //findShortestPath.push(v,INT_MAX);
        }
    }


    //after I insert all vertices w/ dist infinity 
    while(findShortestPath.size()!=0) { //while PQ not empty 
        Vertex* temp = findShortestPath.front(); //extractMin() idea 
        findShortestPath.pop(); //since front does not remove it 


        //now "relax" all neighbors of temp (curr vertex) 
        for(int i=0;i<temp->neighs.size();i++) {
            Vertex* neigh= temp->neighs[i].first; //get vertex obj of curr neigh (pair so .first)
            int w = temp->neighs[i].second; //get curr. vet. obj. weight (pair so .second)
            
            if(pathDistance[temp]+ w < pathDistance[neigh]) {
                bool firstTime = (pathDistance[neigh] == INT_MAX);
                pathDistance[neigh] = pathDistance[temp]+w;

                parents[neigh] = temp; 

                if (firstTime)
                    findShortestPath.push(neigh, pathDistance[neigh]);
                else
                    findShortestPath.decrease_key(neigh, pathDistance[neigh]);
                
                //findShortestPath.decrease_key(neigh, pathDistance[neigh]);
            }
        }
    }
    
    Vertex* curr = exit;
    while(curr!=nullptr) {
        //retrase path
        int index = curr->row * (col + 1) + curr->col; //forumla from matrix 
        //debug line
        //cout << "Marking (" << curr->row << "," << curr->col << ") at maze[" << index << "]\n";
        maze[index] = 'o';
        //go back through path 
        curr = parents[curr];
    }

    return maze; 
}