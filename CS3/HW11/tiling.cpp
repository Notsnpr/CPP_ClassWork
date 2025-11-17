#include "tiling.h"
#include "vertex.h"

using namespace std;


// Finds a (shortest according to edge length) augmenting path
// from s to t in a graph with vertex set V.
// Returns whether there is an augmenting path.
bool augmenting_path(Vertex* s, Vertex* t, 
        unordered_set<Vertex*> V, vector<Vertex*> &P)
{
        // Check that s and t aren't nullptr
        if (s == nullptr || t == nullptr)
	{
		cerr << "augmenting_path() was passed nullptr s or t." << endl;
		abort();
	}

        // Check that s and t are in the graph
        if (V.find(s) == V.end() || V.find(t) == V.end())
	{
		cerr << "augmenting_path() was passed s or t not in V." << endl;
		abort();
	}

	// Check that every vertex has valid neighs/weights.
	for (Vertex* v : V)
		for (Vertex* vn : v->neighs)
			if (v->weights.find(vn) == v->weights.end())
			{
				cerr << "augmenting_path() was passed invalid vertex." << endl;
				abort();
			}

        // Since augmenting paths should have the fewest edges,
	// not the minimum weight, run BFS.
	queue<Vertex*> Q;
	Q.push(s);

	unordered_set<Vertex*> R;
	R.clear(); 
	R.insert(s);

	unordered_map<Vertex*, Vertex*> prev;

	while (!Q.empty())
	{
		Vertex* cur = Q.front();
		Q.pop();

		for (Vertex* nei : cur->neighs)
		{
			// Must have positive edge weight
			if (cur->weights[nei] == 0)
				continue;

			if (R.find(nei) == R.end())
			{
				Q.push(nei);
				R.insert(nei);
				prev[nei] = cur; 
			}
		}
	}      

        // If BFS never reached t
        if (R.find(t) == R.end())
                return false;

        // Reconstruct shortest path backwards
        P.clear();
        P.push_back(t);
        while (P[P.size()-1] != s)
                P.push_back(prev[P[P.size()-1]]);

        // Reverse shortest path
        for (int i = 0; i < P.size()/2; ++i)
		swap(P[i], P[P.size()-1-i]);

        return true;
}

// Returns the maximum flow from s to t in a weighted graph with vertex set V.
// Assumes all edge weights are non-negative.
int max_flow(Vertex* s, Vertex* t, unordered_set<Vertex*> V)
{
	// If s or t is invalid.
        if (s == nullptr || t == nullptr)
	{
		cerr << "max_flow() was passed nullptr s or t." << endl;
		abort(); 
	}

	// If s or t is not in the vertex set.
        if (V.find(s) == V.end() || V.find(t) == V.end())
	{
		cerr << "max_flow() was passed s or t not in V." << endl;
		abort(); 
	}

	// Check that every vertex has valid neighs/weights.
	for (Vertex* v : V)
		for (Vertex* vn : v->neighs)
			if (v->weights.find(vn) == v->weights.end())
			{
				cerr << "max_flow() was passed invalid vertex." << endl;
				abort();
			}

        // Create a deep copy of V to use as the residual graph
        unordered_set<Vertex*> resV;
        unordered_map<Vertex*, Vertex*> C; // Maps vertices in V to copies in resV
        for (Vertex* vp : V)
        {
                Vertex* rp = new Vertex;
                resV.insert(rp);
                C[vp] = rp;
        }
        for (Vertex* vp : V)
                for (Vertex* np : vp->neighs)
                {
                        C[vp]->neighs.insert(C[np]);
                        C[vp]->weights[C[np]] = vp->weights[np];
                }
	// Add any missing necessary "back" edges. 
        for (Vertex* vp : V)
                for (Vertex* np : vp->neighs)
		{
			if (C[np]->neighs.find(C[vp]) == C[np]->neighs.end())
			{
				C[np]->neighs.insert(C[vp]);
				C[np]->weights[C[vp]] = 0;
			}
		}

        // Run Edmonds-Karp
        while (true)
        {
                // Find an augmenting path
                vector<Vertex*> P;
                if (!augmenting_path(C[s], C[t], resV, P))
                        break;  
                // Update residual graph
                for (int i = 0; i < P.size()-1; ++i)
                {
                        --((*(resV.find(P[i])))->weights[P[i+1]]);
                        ++((*(resV.find(P[i+1])))->weights[P[i]]);
                }
        }

        // Compute actual flow amount
        int flow = 0;
        for (Vertex* snp : C[s]->neighs)
                flow += 1 - C[s]->weights[snp];

        // Delete residual graph
        for (Vertex* vp : resV)
                delete vp;

        return flow;
}


bool has_tiling(string floor)
{
        // TODO
        // we turn the string into a array
        vector<string> lines;
        string current_line;
        for (char c : floor)
        {
                if (c == '\n')
                {
                        lines.push_back(current_line);
                        current_line = "";
                }
                else
                {
                        current_line += c;
                }
        }
        if (!current_line.empty())
        {
                lines.push_back(current_line);
        }
        if (lines.size() == 0)
                return false;
        int rows = lines.size();
        int cols = lines[0].size();
        int empty_space = 0;
        vector<vector<char>> grid(rows, vector<char>(cols));
        for (int r = 0; r <rows; r++){
            for( int c = 0; c < cols; c++){
                if (lines[r][c]== ' '){
                    empty_space++;
                    if ((r + c) % 2 == 0){
                        grid[r][c] = 'W'; // white
                    } else {
                        grid[r][c] = 'B'; // black
                    }
                } else {
                    grid[r][c] = '#'; // wall
                }
            }
        }
        if (empty_space % 2 != 0){
            return false; // odd number of empty spaces cannot be fully tiled
        }
        // cout << "Grid representation:\n";
        // for (const auto& row : grid) {
        //     for (char cell : row) {
        //         cout << cell << ' ';
        //     }
        //     cout << '\n';
        // }
        unordered_set<Vertex*> V;
        Vertex* source = new Vertex();
        Vertex* sink = new Vertex();
        V.insert(source);
        V.insert(sink);
        vector<vector<Vertex*>> nodes(rows, vector<Vertex*>(cols, nullptr));
        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (grid[r][c] == 'W' || grid[r][c] == 'B'){
                    nodes[r][c] = new Vertex();
                    V.insert(nodes[r][c]);
                }
            }
        }
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int r=0; r < rows; r++){
            for (int c=0; c < cols; c++){
                Vertex* v = nodes[r][c];
                if (!v) continue;
                if (grid[r][c] == 'W'){
                    // connect to source
                    source->neighs.insert(v);
                    source->weights[v] = 1;
                    v->neighs.insert(source);
                    v->weights[source] = 0;
                    // connect to adjacent black nodes
                    for (const auto& dir : directions){
                        int nr = r + dir.first;
                        int nc = c + dir.second;
                        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols){
                            if (grid[nr][nc] == 'B'){
                                Vertex* nb = nodes[nr][nc];
                                v->neighs.insert(nb);
                                v->weights[nb] = 1;
                                nb->neighs.insert(v);
                                nb->weights[v] = 0;
                            }
                        }
                    }
                } else if (grid[r][c] == 'B'){
                    // connect to sink
                    v->neighs.insert(sink);
                    v->weights[sink] = 1;
                    sink->neighs.insert(v);
                    sink->weights[v] = 0;
                }
            }
        }
        int flow = max_flow(source, sink, V);
        // Clean up allocated memory
        for (Vertex* vp : V)
                delete vp;
        // TODO: Implement the tiling logic here.

        return flow * 2 == empty_space;
}



