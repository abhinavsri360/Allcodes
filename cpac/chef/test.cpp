// C++ program to print all paths from a source to destination. 
#include<iostream> 
#include <list> 
using namespace std; 

int cost[100000];
int quo=1;
// A directed graph using adjacency list representation 
class Graph 
{ 
	int V; // No. of vertices in graph 
	list<int> *adj; // Pointer to an array containing adjacency lists 

	// A recursive function used by printAllPaths() 
	int printAllPathsUtil(int , int , bool [], int [], int &); 

public: 
	Graph(int V); // Constructor 
	void addEdge(int u, int v); 
	int printAllPaths(int s, int d); 
}; 

int divisors(int n) 
{
	int c=0;
	for (int i=1;i<=n/2+1;i++) 
		if (n%i==0) 
			c++;
	return ++c;
}

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int u, int v) 
{ 
	adj[u].push_back(v); // Add v to u’s list. 
} 

// Prints all paths from 's' to 'd' 
int Graph::printAllPaths(int s, int d) 
{ 
	// Mark all the vertices as not visited 
	bool *visited = new bool[V]; 

	// Create an array to store paths 
	int *path = new int[V]; 
	int path_index = 0; // Initialize path[] as empty 

	// Initialize all vertices as not visited 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	// Call the recursive helper function to print all paths 
	return printAllPathsUtil(s, d, visited, path, path_index); 
} 

// A recursive function to print all paths from 'u' to 'd'. 
// visited[] keeps track of vertices in current path. 
// path[] stores actual vertices and path_index is current 
// index in path[] 
int Graph::printAllPathsUtil(int u, int d, bool visited[], int path[], int &path_index) 
{
	// Mark the current node and store it in path[] 
	visited[u] = true; 
	path[path_index] = u; 
	path_index++; 

	// If current vertex is same as destination, then print 
	// current path[] 
	if (u == d) 
	{ 
		for (int i = 0; i<path_index; i++) 
			quo*=cost[path[i]];
	} 
	else // If current vertex is not destination 
	{ 
		// Recur for all the vertices adjacent to current vertex 
		list<int>::iterator i; 
		for (i = adj[u].begin(); i != adj[u].end(); ++i) 
			if (!visited[*i]) 
				printAllPathsUtil(*i, d, visited, path, path_index); 
	} 

	// Remove current vertex from path[] and mark it as unvisited 
	path_index--; 
	visited[u] = false;
	return quo;
} 

// Driver program 
int main() 
{
	int t,n,u,q,v,d;
	cin>>t;
	while(t--)
	{
		cin>>n;
		Graph g(n+1);
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			g.addEdge(u,v);
		}
		for(int i=1;i<=n;i++)
			cin>>cost[i];
		cin>>q;
		while(q--)
		{
			cin>>u>>v;
			int d=g.printAllPaths(u,v);
			cout<<d<<endl;
			quo=1;
		}
	}
	return 0; 
} 
