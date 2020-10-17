//wap to implement Bellman Ford Alogorithm in graph(Directed graph)

#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int> >adj[],int snode,int enode,int weight) {
	adj[snode].push_back(make_pair(enode,weight));
	
}
void bellman(vector<pair<int,int> >adj[],int vertices,int src) {
	int distance[vertices];
	for(int i=0; i<vertices; i++)
		distance[i]=INT_MAX;
	distance[src]=0;
	for(int itr=1; itr<=vertices-1; itr++) {
		for(int i=0; i<vertices; i++) {
			int u=distance[i];
			for(vector<pair<int,int> > :: const_iterator it=adj[i].begin(); it!=adj[i].end(); it++) {

				int edgeCost=it->second;
				if(u!=INT_MAX && u+edgeCost<distance[it->first])
					distance[it->first]=u+edgeCost;
			}
		}
	}
	//Detection of negative weight cycle
	for(int i=0; i<vertices; i++) {
		int u=distance[i];
		for(vector<pair<int,int> > :: const_iterator it=adj[i].begin(); it!=adj[i].end(); it++) {

			int edgeCost=it->second;
			if(u!=INT_MAX && u+edgeCost<distance[it->first]) {
				cout<<"\nThe Graph Contains Negative Weight Cycle";
				return;
			}
		}
	}
	cout<<"Vertex "<<"\t\tDistance From Source Vertex(0)";
	for(int i=0;i<vertices;i++)
	{
		
		cout<<"\n  "<<i<<"\t\t\t"<<distance[i];
		
	}
}
int main() {
	int vertices=6;
	vector<pair<int,int> > adj[vertices];
	addEdge(adj, 0, 1, 6);
	addEdge(adj, 0, 2, 4);
	addEdge(adj, 0, 3, 5);
	addEdge(adj, 1, 4, -1);
	addEdge(adj, 2, 1, -2);
	addEdge(adj, 2, 3, 60);
	addEdge(adj, 2, 4, 3);
	addEdge(adj, 3, 2, -2);
	addEdge(adj, 3, 5, -1);
	addEdge(adj, 4, 5, 3);
	
	bellman(adj,vertices,0);
	return 0;

}