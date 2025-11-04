#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class directedGraph
{
private:
	class vertex
	{
	public:
		string data;
		vector<vertex*> neighbors;

		vertex(string x)
		{
			data = x;
		}
	};

	unordered_map<string, vertex*> vertexMap;

	void breadthFirstSearch(vertex* s, unordered_map < vertex*, vertex*> &bc)
	{
		//step -1:
		unordered_set<vertex*> marked;
		queue<vertex*> Q;

		//step 0:
		marked.insert(s);
		Q.push(s);

		//step 1: BFS loop
		while (!Q.empty())
		{
			//step 1.1: get item x from Q
			vertex* x = Q.front();
			Q.pop();

			//step 1.2: visit x's unmarked neighbors
			for (auto y : x->neighbors)
			{
				if (marked.find(y) == marked.end())  //y is not marked)
				{
					marked.insert(y);
					Q.push(y);

					//augmentation for shortest path
					bc[y] = x;
				}
			}
		}
	}

public:

	directedGraph()
	{
	}

	//run time: a.c. O(1)
	void addVertex(string x)
	{
		vertexMap[x] = new vertex(x);
	}

	void addDirectedEdge(string x, string y)
	{
		vertex* xVert = vertexMap[x];
		vertex* yVert = vertexMap[y];

		xVert->neighbors.push_back(yVert);
	}

	void addBasicEdge(string x, string y)
	{
		addDirectedEdge(x, y);
		addDirectedEdge(y, x);
	}

	string shortestPath(string start, string dest)
	{
		//step 0: get the start and end vertices
		vertex* s = vertexMap[start];
		vertex* d = vertexMap[dest];

		//step 1: call BFS
		unordered_map<vertex*, vertex*> breadCrumbs;
		breadthFirstSearch(s,breadCrumbs);

		//step 2: Trace breadcrumb trail back
		// from d to s
		string path;
		vertex* current = d;
		while (current != s)
		{
			path = current->data + ", " + path;
			current = breadCrumbs[current];
		}
		path = s->data + ", " + path;

		//step 3:
		return path;
	}

	void testDisplay()
	{
		for (auto x : vertexMap)
		{
			cout << x.first << ": ";
			for (auto y : x.second->neighbors)
			{
				cout << y->data << ", ";
			}
			cout << endl;
		}
	}

};