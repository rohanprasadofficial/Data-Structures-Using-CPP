//wap to perform graph colouring

#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<pair<int,int> >adj[],int snode,int enode,int weight) {
	adj[snode].push_back(make_pair(enode,weight));
	adj[enode].push_back(make_pair(snode,weight));
}
void graphColoring(vector<pair<int,int> >adj[],int vertices)
{
	int vertexCol[vertices];
	bool availColor[vertices];
	for(int i=0;i<vertices;i++)
		availColor[i]=true;  //true represent that initially all colors are available
	vertexCol[0]=0; //Assigned color'0' to vertex 0
	for(int i=1;i<vertices;i++)
		vertexCol[i]=-1;	 //All other vertices are vertices except 0 has not been assigned any color so -1
	
	
	for(int i=1;i<vertices;i++)
	{
		for(vector<pair<int,int> >::const_iterator it=adj[i].begin();it!=adj[i].end();it++)
		{
			if(vertexCol[it->first]!=-1)
				availColor[vertexCol[it->first]]=false;			
		}	
		
		int cr;		
		for(cr=0;cr<vertices;cr++)
		{
			if(availColor[cr]==true)
					break;
		}
		vertexCol[i]=cr;
		for(int i=0;i<vertices;i++)
			availColor[i]=true;
	}	
	cout<<"Vertex\t\t\tColor Assigned";
	for(int i=0;i<vertices;i++)
	{
		cout<<"\n  "<<i<<"\t\t\t  "<<vertexCol[i];
	}
}
int main() {
	int vertices=5;
	vector<pair<int,int> > adj[vertices];
	addEdge(adj, 0, 1, 6);
	addEdge(adj, 0, 2, 4);
	addEdge(adj, 1, 2, 5);
	addEdge(adj, 1, 3, -1);
	addEdge(adj, 2, 3, -2);
	addEdge(adj, 3, 4, 60);
	
	graphColoring(adj,vertices);
	return 0;

}