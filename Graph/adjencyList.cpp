//wap to represent the adjacency list of a graph using vector and pair STL
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int> >adj[],int snode,int enode,int weight)
{
	adj[snode].push_back(make_pair(enode,weight));
	adj[enode].push_back(make_pair(snode,weight));
}
void showList(vector<pair<int,int> >adj[],int vertices)
{
	for(int i=0;i<vertices;i++)
	{
		cout<<"\nThe adjacent node of the Node "<<i<<":\n";
		
		for(vector < pair<int,int> >::const_iterator it = adj[i].begin() ; it!=adj[i].end();it++)
			cout<<"\t\tNode "<<it->first<<" with weight:"<<it->second<<endl;
	}
	
	
}
int main()
{	
	int vertices=5;
	vector<pair<int,int> > adj[vertices];
	addEdge(adj, 0, 1, 10); 
    addEdge(adj, 0, 4, 20); 
    addEdge(adj, 1, 2, 30); 
    addEdge(adj, 1, 3, 40); 
    addEdge(adj, 1, 4, 50); 
    addEdge(adj, 2, 3, 60); 
    addEdge(adj, 3, 4, 70); 
    showList(adj,vertices);
    return 0;
    
} 