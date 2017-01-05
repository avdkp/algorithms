#include<iostream>

#define INF 0x00ff0000

using namespace std;


struct node{

	int wt;
	int parent;
	int visited;

};


int find_min(node adj1[],int v);
void prims(int *adj,node adj1[],int v);

int main()
{
	int i,j,v,cost=0;
	//cout<<INF;
	cout<<"No of vertices :";
	cin>>v;
	
	int adj[v][v];
	node adj1[v];

	cout<<"\nEnter lower triangle of adj matrix :"<<endl;


	for(i=0;i<v;++i)
		for(j=0;j<=i;++j)
			{
				cin>>adj[i][j];
				adj[j][i]=adj[i][j];
				
				
			}

	for(i=0;i<v;++i)
	{
		adj1[i].wt=INF;
		adj1[i].visited=-1;
		adj1[i].parent=-1;

	}
adj1[0].wt=0;
	prims(&adj[0][0],adj1,v);
	
	//for(i=0;i<v;++i)
	//cout<<i<<adj1[i].parent<<endl;

	for(i=0;i<v;++i)
	{
	if(adj1[i].parent!=-1)
	cout<<i<<"<-"<<adj1[i].parent<<endl;
		cost +=adj1[i].wt;	
	}
	cout<<"\ncost:"<<cost<<endl;
}

void prims(int *adj,node adj1[],int v)
{

	int i,t,j,k;
	for(t=0;t<v;++t)
	{	
		i=find_min(adj1,v);
		//cout<<"v "<<i<<endl;
		if(i==-1)
			break;
		adj1[i].visited=1;
		for(j=0;j<v;++j)
		{
			//cout<<*(adj+i*v+j);
			if(*(adj+i*v+j)!=0)
			{
				//cout<<*(adj+i*v+j);
				if(adj1[j].wt>*(adj+i*v+j))
				{
					adj1[j].wt=*(adj+i*v+j);
					adj1[j].parent=i;
				}				
			}
		}
	}
}
/*find min can also be done using heap but there is not much difference in complexity

*/
int find_min(node adj1[],int v)				
{
	int i,min=-1,min_val=INF;
	for(i=0;i<v;++i)
	{
		if(adj1[i].wt<min_val && adj1[i].visited==-1)
		{
			//cout<<"\nfsgdsdfghh"<<i;
			min=i;
			min_val=adj1[i].wt;
		}	
	}
return min;
}










