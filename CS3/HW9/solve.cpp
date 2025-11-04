#include "solve.h"
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solve(string maze) {
    // convert the maze into a 2d array/grid
    vector<string> grid;
    string line = "";
    for (char ch : maze) {
        if (ch == '\n') {
            if (!line.empty()) {
                grid.push_back(line);
                line.clear();
            }
        } else {
            line += ch;
        }
    }
    if (!line.empty()) grid.push_back(line); // we are making sure that if the last line doesnt have \n then we can add it 

    // find and queue all the edges
    int rows = grid.size();
    int cols = grid[0].size();

    // find start and goal on the border (two open spaces)
    pair<int,int> start = {-1, -1};
    pair<int,int> goal = {-1, -1};
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < (int)grid[r].size(); c++) {
            if ((r == 0 || r == rows - 1 || c == 0 || c == (int)grid[r].size() - 1) && grid[r][c] == ' ') {
                if (start.first == -1)
                    start = {r, c};
                else
                    goal = {r, c};
            }
        }
    }

    // safety check in case start/goal not found
    if (start.first == -1 || goal.first == -1) {
        // no path to solve
        string result = "";
        for (int r = 0; r < rows; r++) {
            result += grid[r];
            result += '\n';
        }
        return result;
    }

    // BFS stuff (shortest path)
    queue<pair<int,int>> q;
    q.push(start);

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    visited[start.first][start.second] = true;

    unordered_map<int, pair<int,int>> parent;

    int dr[4] = {-1, 1, 0, 0}; // up, down
    int dc[4] = {0, 0, -1, 1}; // left, right

    bool found = false;

    while (!q.empty() && !found) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // check bounds and if it's a valid open space
            if (nr >= 0 && nr < rows && nc >= 0 && nc < (int)grid[nr].size() && grid[nr][nc] == ' ' && !visited[nr][nc]) {
                visited[nr][nc] = true;
                parent[nr * cols + nc] = {r, c};
                q.push({nr, nc});

                if (make_pair(nr, nc) == goal) {
                    found = true;
                    break;
                }
            }
        }
    }

    // rebuild the maze with the optimal path
    if (found) {
        pair<int,int> cur = goal;
        while (cur != start) {
            grid[cur.first][cur.second] = 'o';
            cur = parent[cur.first * cols + cur.second];
        }
        grid[start.first][start.second] = 'o'; // mark the start too
    }

    // rebuild the maze into a single string again
    string results = "";
    for (int r = 0; r < rows; r++) {
        results += grid[r];
        results += '\n'; // each line ends with newline to match expected format
    }

    return results;
}
