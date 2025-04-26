#include<iostream>
using namespace std;
    const int   n=10;
class music{
public:
    int trackid;
    string song;
    string singer;
    
    
    void accept()
    {
        cout<<"enter the track id of song: ";
        cin>>trackid;
        cout<<"enter the name of song: ";
        cin>>song;
        cout<<"enter the singer name: ";
        cin>>singer;
        cout<<endl;
        }
        
        void displaym()
        {
           cout<<"\nid:"<<trackid;
           cout<<"\nsong name: "<<song;
           cout<<"\nsinger: "<<singer;
        
        }
        
    };
    
    
    class hashing{
    public:
            music m[n];
            int status[n];
            hashing()
            {
            for(int i=0;i<n;i++)
            {
            status[i]=-1;
            }
            
            }
        
            
            void insert( music s)
            {
                 int index=s.trackid % n;
                 int count=0;
                 while(status[index]!=-1&&count<n)
                 {
                 cout<<"!!!!!collision occure at index "<<index<<" !!!!!"<<endl;
                 index=index+1;
                 
                 }
                 if(status[index]!=1)
                 {
		         m[index]=s;
		         status[index]=1;
		         cout<<"  <-------------inserted at index "<<index<<"------------->"<<endl;
		        
                 }
                
                 
                     
                 }
                 
                 
                
                 
              void display(music s)
              {
		      for(int i=0;i<n;i++){
				if(status[i]==1){
				cout<<"\n\ndisplaying from index "<<i<<endl;
				   m[i].displaym();
				}
		      }
              }
            };
            
            
            
    
int  main()
    {
    music s;
    hashing h;
       for(int i=0;i<2;i++)  {
    s.accept();
    h.insert(s);
    }
    h.display(s);
    
    return 0;
    }
