//wap to perform topological sorting using DFS(Fepth First Search)-The Graph must be DAG-Directed Acylic graph

#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int> >adj[],int snode,int enode,int weight)
{
	adj[snode].push_back(make_pair(enode,weight));
	
}
void dfsTraverseRecur(stack<int>&Stack,bool visited[],vector<pair<int,int> >adj[],int v)
{
	
	visited[v]=true;
	//cout<<v<<"->";
	for(vector<pair<int,int> >::const_iterator it=adj[v].begin();it!=adj[v].end();it++)
	{
		if(visited[it->first]!=true)
			{
				dfsTraverseRecur(Stack,visited,adj,it->first);
			}
	}
	Stack.push(v);
	
}
void dfs(vector<pair<int,int> >adj[],int v)
{	
	stack<int>Stack;
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i]=false;
	for(int src=0;src<v;src++)	
		if(visited[src]==false)	
		dfsTraverseRecur(Stack,visited,adj,src);
	    while(Stack.empty()==false)
		{
			cout<<Stack.top();
			Stack.pop();
		}
		cout<<endl;
	
}

int main()
{	
	int vertices=6;
	vector<pair<int,int> > adj[vertices];
    /*addEdge(adj, 0, 1, 20); 
    addEdge(adj, 0, 5, 30);
	addEdge(adj, 1, 7, 20);
	addEdge(adj, 3, 2, 20);
	addEdge(adj, 3, 4, 20);
	addEdge(adj, 3, 8, 20);
	addEdge(adj, 3, 7, 20); 
	addEdge(adj, 4,8,20);
	addEdge(adj, 6, 0, 20);     
	addEdge(adj, 6, 1, 20); 
	addEdge(adj, 6, 2, 20);
	addEdge(adj, 8, 2, 20);
	addEdge(adj, 9, 4, 20);*/
	addEdge(adj, 5, 2, 20);
	addEdge(adj, 5, 0, 20);
	addEdge(adj, 4, 0, 20);         
	addEdge(adj, 4, 1, 20);
	addEdge(adj, 2, 3, 20);
	addEdge(adj, 3, 1, 20);   
    cout<<"\nTopological Sorting similar to DFS Traversal of the Graph\n";
    dfs(adj,vertices);
    return 0;
    
} 