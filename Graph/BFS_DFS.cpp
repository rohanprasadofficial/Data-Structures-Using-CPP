//wap to implement BFS and DFS  in graph
#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int> >adj[],int snode,int enode,int weight) {
	adj[snode].push_back(make_pair(enode,weight));
	adj[enode].push_back(make_pair(snode,weight));
}
void showList(vector<pair<int,int> >adj[],int vertices) {
	for(int i=0; i<vertices; i++) {
		cout<<"\nThe adjacent node of the Node "<<i<<":\n";

		for(vector < pair<int,int> >::const_iterator it = adj[i].begin() ; it!=adj[i].end(); it++)
			cout<<"\t\tNode "<<it->first<<" with weight:"<<it->second<<endl;
	}
}
void bfsTraverse(vector<pair<int,int> >adj[],int src) {
	queue<int> q;
	map<int,bool> visited;
	q.push(src);
	visited[src]=true;
	while(!q.empty()) {
		int num=q.front();
		cout<<num<<"->";
		q.pop();
		for(vector < pair<int,int> >::const_iterator it = adj[num].begin() ; it!=adj[num].end(); it++) {
			if(visited[it->first]!=true) {
				q.push(it->first);
				visited[it->first]=true;
			}

		}
	}

}
void dfsTraverseRecur(bool visited[],vector<pair<int,int> >adj[],int v) {

	visited[v]=true;
	cout<<v<<"->";
	for(vector<pair<int,int> >::const_iterator it=adj[v].begin(); it!=adj[v].end(); it++) {
		if(visited[it->first]!=true) {
			dfsTraverseRecur(visited,adj,it->first);
		}
	}

}
void dfs(vector<pair<int,int> >adj[],int src,int v) {
	bool visited[v];
	for(int i=0; i<v; i++)
		visited[i]=false;
	dfsTraverseRecur(visited,adj,src);
}

int main() {
	int vertices=4;
	vector<pair<int,int> > adj[vertices];
	addEdge(adj, 0, 1, 10);
	addEdge(adj, 0, 2, 20);
	addEdge(adj, 1, 2, 30);
	addEdge(adj, 2, 3, 50);
	showList(adj,vertices); //If you want to display the adjency list then remove the comment from function
	cout<<"\nBFS Traversal Of the Graph\n";
	bfsTraverse(adj,0);
	cout<<"\nDFS Traversal of the Graph\n";
	dfs(adj,0,vertices);
	return 0;

}