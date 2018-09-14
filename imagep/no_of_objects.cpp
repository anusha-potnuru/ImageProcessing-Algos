#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace std;
using namespace cv;

#include <algorithm>
#include <list>

Mat im=imread("/Users/Anusha/Desktop/ip/a.jpg",0);

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(pair<int,int> v, pair<int,int> w); // to add an edge to graph
    void DFS();  
    void DFSUtil(int s, vector<bool> &visited);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(pair<int,int> v, pair<int,int> w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFSUtil(int s, vector<bool> &visited)
{
    // Create a stack for DFS
    stack<int> stack;
 
    // Push the current source node.
    stack.push(s);
 
    while (!stack.empty())
    {
        // Pop a vertex from stack and print it
        s = stack.top();
        stack.pop();
        if (!visited[s])
        {
            cout << s << " ";
            visited[s] = true;
        }
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
            if (!visited[*i])
                stack.push(*i);
    }
}
 
int Graph::DFS()
{
    vector<bool> visited(V, false);
    int k=0;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
        	k++;
            DFSUtil(i, visited);
        }
    }
    return k;
}

int main()
{
	



	return 0;
}