#include<iostream>
using namespace std;
const int MAX=10000;


string hall[MAX];
int m[MAX][MAX];
int dist[MAX];
bool visited[MAX];


int findindex(int s,string city)
{
	for(int i=0;i<s;i++)
	{
	 if(hall[i]==city)
	 {
	    return i;
	 }
	 }
	 return-1;

}


void  addedge(int n,int s,int d,int w)
{
    m[s][d]=w;
        m[d][s]=w;
}

void printm(int s)
{
    for(int i=0;i<s;i++)
    {
      cout<<"\t"<<hall[i];
      }
      for(int i=0;i<s; i++)
      {
      cout<<"\n"<<hall[i];
      for(int j=0;j<s;j++)
      {
        cout<<"\t"<<m[i][j];
        }
        
        }
        }
        
        
        
        
       void dijkstra(int n , int start)
       {
	       for(int i=0;i<n;i++)
	       {
	         dist[i]=MAX;
	         visited[i]=false;
	         }
	         dist[start]=0;
	         
	         for(int i=0;i<n;i++)
	         {
			int u=-1;
			int mindist=MAX;
			  
			  for(int j=0;j<n;j++)
			  {
			    if(!visited[j] && dist[j]<mindist)
			    {
			      mindist=dist[j];
			      u=j;
			      }
			      }
			      if(u==-1) break;
			        visited[u]=true;
		
			        for(int v=0;v<n;v++)
			        {
			           if(!visited[v]&&m[u][v]!=MAX)
			           {
			              if(dist[u]+m[u][v]<dist[v])
			              {
			                  dist[v]=dist[u]+m[u][v];
			                 }
			                 }
			                 }
			                 }
			                 }
			                 
			                        



int main()
{
string s,d;
int w;
int n,e;
cout<<"hello enter the no of halls: ";
cin>>n;
cout<<"enter the no of ways: ";
cin>>e;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
		if(i==j)
		{
		  m[i][j]=0;
		  }else
		  {
		  m[i][j]=-1;
		  }
		  }
	}
	    cout<<"enter the hall  names: ";
	for(int i=0;i<n;i++)
	{
	  cin>>hall[i];
	  }
	  int sindex=-1,dindex=-1;
	  cout<<"enter  source->destinetion->distance : ";
	  for(int i=0;i<e;i++)
	  {
	      cin>>s>>d>>w;
	      sindex=findindex(n,s);
	      dindex=findindex(n,d);
	       if(sindex!=-1&&dindex!=-1)
	      {
	      addedge(n,sindex,dindex,w);
	      }
	      
	    }
	    int start;
	    string current;
	    printm(n);
	    cout<<"\n enter the starting location::";
	    cin>>current;
	     start =findindex(n,current);
	     if(start!=-1)
	     {
	    dijkstra(n,start);
	     }
	     cout<<"shortest path from "<<current<<"  starting hall to:\n";
	     for(int i=0;i<n;i++)
	     {
	        cout<<hall[i]<<"->"<<dist[i]<<"\n";
	        }
	    }
	      
	    
	  
	
