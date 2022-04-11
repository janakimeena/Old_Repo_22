/*
6
0 16 13 0 0 0 
0 0 10 12 0 0
0 4 0 0 14 0
0 0 9 0 0 20
0 0 0 7 0 4
0 0 0 0 0 0*/
/*
6
0 10 0 10 0 0
0 0 4 2 8 0
0 0 0 0 0 10
0 0 0 0 9 0
0 0 6 0 0 10
0 0 0 0 0 0
*/
#include <iostream>
#include <limits.h>
#include <queue>
#include <string.h>
#include<vector>
using namespace std;
void print_graph(vector<vector<int> >);
/* Returns true if there is a path from source 's' to sink
't' in residual graph. Also fills path to store the
path */
bool find_Path_From_Source_BFS(vector<vector<int> > residual_graph, int s, int t, int parents[])
{
	// Create a visited array and mark all vertices as not
	// visited
	int num_vertices = residual_graph.size();
	vector<bool> visited(false,num_vertices);
	

	// Create a queue, enqueue source vertex and mark source
	// vertex as visited
	queue<int> q;
	cout<<"BFS called"<<endl;
	cout<<s<<" ";
	q.push(s);
	visited[s] = true;
	parents[s] = -1;

	// Standard BFS Loop
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int v = 0; v < num_vertices; v++) {
			if (visited[v] == false && residual_graph[u][v] > 0) {
				// If we find a connection to the sink node,
				// then there is no point in BFS anymore We
				// just have to set its parent and can return
				// true
				if (v == t) {
					parents[v] = u;
					cout<<endl;
					return true;
				}
				cout<<v<<" ";
				q.push(v);
				parents[v] = u;
				visited[v] = true;
			}
		}
	}

	// We didn't reach sink in BFS starting from source, so
	// return false
	cout<<endl;
	return false;
}

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(vector<vector<int> > graph)
{
	int s, t,i,j,u,v,num_vertices;
	s = 0;
	t = graph.size()-1;
	// Create a residual graph and invoke copy constructor
	// to fill the residual graph
	// with given capacities in the original graph as
	// residual capacities in residual graph
	vector<vector<int> > residual_graph(graph);
	num_vertices = residual_graph.size();
	//cout<<"residual_graph"<<endl;
	//print_graph(residual_graph);
	// Residual graph indicates residual capacity of edge
	

	int parents[num_vertices]; // This array is filled by BFS and to
				// store path

	int max_flow = 0; // There is no flow initially

	// Augment the flow while there is path from source to
	// sink
	while (find_Path_From_Source_BFS(residual_graph, s, t, parents)) {
		// Find minimum residual capacity that is bottleneck 
		// of the edges along the path filled by BFSa
		int path_flow = INT_MAX;
		
		for (v = t; v != s; v = parents[v]) {
			cout<<v<<" ";
			u = parents[v];
			path_flow = min(path_flow, residual_graph[u][v]);
		}
		cout<<endl;
		// update residual capacities of the edges and
		// reverse edges along the path
		for (v = t; v != s; v = parents[v]) {
			u = parents[v];
			residual_graph[u][v] -= path_flow;
			residual_graph[v][u] += path_flow;
		}

		// Add path flow to overall flow
		max_flow += path_flow;
	}

	// Return the overall flow
	return max_flow;
}

// read_graph function
void read_graph(vector<vector<int> > &graph, int num_vertices)
{
	int i,j,wt;
	for(i=0;i<num_vertices;i++)
	{
		vector<int> vertex;
		for(j=0;j<num_vertices;j++)
		{
			cin>>wt;
			vertex.push_back(wt);
		}
		graph.push_back(vertex);
	}
}
void print_graph(const vector<vector<int> > graph)
{
	int i,j,num_vertices;
	num_vertices = graph.size();
	for(i=0;i<num_vertices;i++)
	{
		for(j=0;j<num_vertices;j++)
		{
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	// Let us create a graph shown in the above example
	int num_vertices;
	vector<vector<int> > graph;
	
	cin>>num_vertices;
	read_graph(graph,num_vertices);
	//print_graph(graph);
	cout << "The maximum possible flow is "<<fordFulkerson(graph);

	return 0;
}

