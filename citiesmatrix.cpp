#include<iostream>
using namespace std;
const int MAXC=100;
void create(int mt[MAXC][MAXC],int v)
{
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            if(i==j)
            {
              mt[i][j]=0;  
            }else{
                mt[i][j]=-1;
            }
        }  
    }
}
void addedge(int m[MAXC][MAXC],int s_index,int d_index,int weight)
{
  m[s_index][d_index]=weight;
  m[d_index][s_index]=weight;
}

void printmt(int m[MAXC][MAXC],int v,string cities[MAXC])
{
    for(int i=0;i<v;i++)
    {
        cout<<"  "<<cities[i]<<" "; 
    }
    cout<<endl;
    for(int i=0;i<v;i++)
    {
        cout<<cities[i]<<" ";
        for(int j=0;j<v;j++)
        {
            if(m[i][j]==-1)
            {
                cout<<"NA"<<" ";
            }
            else{
                cout<<m[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
}

int main()
{
    int numc,nume;
    int m[MAXC][MAXC];
    cout<<"enter thye no of cities:";
    cin>>numc;
    cout<<"enter the no of edges:";
    cin>>nume;
    create(m,numc);
     
    string cities[MAXC];
    cout<<"enter the name of cities:";
    for(int i=0;i<numc;i++)
    {
        cin>>cities[i];

    }

    string s_city,d_city;
    int distance;
    for(int i=0;i<nume;i++)
    {
        cout<<"enter the source->destination->distance:";
        cin>>s_city>>d_city>>distance;

        int s_index=-1,d_index=-1;
        for(int i=0;i<numc;i++)
        {
            if(cities[i]==s_city)
            {
                s_index=i;
            }
            if(cities[i]==d_city)
            {
                d_index=i;
            }
        }
        if(s_index!=-1&&d_index!=-1)
        {
            addedge(m,s_index,d_index,distance);
        }else{
            cout<<"invalid city name!";
        }
    }

     printmt(m,numc,cities);

     return 0;

}
