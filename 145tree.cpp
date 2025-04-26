#include<iostream>
using namespace std;
   int count;
    int leaf=0;
class b{
public:
int data;
b *left;
b *right;

b(int x)
{
data=x;
left=NULL;
right=NULL;
}
      void create();
      void insert(b *root,b *next);
       void preorder(b *root);
             void postorder(b *root);
             void inorder(b *root);
       }*next,*root;
       
       
       
       
       
       
      void insert(b* root1,b *next1)
      {
      char s;
        cout<<"\nleft insert or right?\n"<<endl;
        cin>>s;
      if(s=='l'||s=='L')
      {
      if(root1->left==NULL)
      {
         root1->left=next1;
      }
      else
      {
      insert(root1->left,next1);
      }
      }
      
      if(s=='r'||s=='R')
      {
       if(root1->right==NULL)
       {
       root1->right=next1;
       }
       else
       {
           insert(root1->right,next1);
           }
           }
       }
       
       
       
       
       
       
      
      void create()
      {
      int val;
      char c;
      do{
      cout<<"\nenter the value to node\n";
      cin>>val;
      count++;
      b *next=new b(val);
      if(root==NULL)
      {
      root=next;
      }
      else
      {
       insert(root,next);
      }
      cout<<"\n\ndo you want to continue(y/n)";
      cin>>c;
      }while(c=='y'||c=='Y');
      }
      
      
      
      
      
      
      
      
      void preorder(b *root)
      {
         if(root==NULL)
         {
        return;
         }
         else{
         cout<<root->data<<endl;
        preorder(root->left);
         preorder(root->right);
         }
         }
         
         
         
         
        void postorder(b *root)
      {
         if(root==NULL)
         {
        return;
         }
         else{
         postorder(root->left);
         postorder(root->right);
         cout<<root->data<<endl;
         }
         } 
         
         
         
         
         
         
         void inorder(b *root)
      {
         if(root==NULL)
         {
        return;
         }
         else{
         inorder(root->left);
         cout<<root->data<<endl;
         inorder(root->right);
         }
         }
         
         
int leafnode(b *root1)
  {
    if (root1 == NULL)
    {
     return 0;
    }
    
    if (root1->left == NULL && root1->right == NULL) {
        
        leaf++; 

    }
    
    leafnode(root1->left);
    leafnode(root1->right);
    
  return leaf;
}





         
  int heightof(b *root)
  {
  if(root==NULL)
  { 
    return -1;
     }
     return 1+max(heightof(root->left),heightof(root->right));
      }

         
         
       void ancester( b *root)
       {
         if(root==NULL)
        {
          return;
           }
             cout<<"\nancester of all nodes:"<<root->data;
              }
        
    
      
        void search(b *root,int key)
          {
            
            if(root==NULL)
             {
         
                return; 
               }
              if(root->data==key)
               {
                  cout<<"!!!!!element is present in tree!!!!"<<endl;
                  return;
                  }
                 if(root->data!=key)
                 {
                   search(root->left,key);
                  }else
                  if(root->data!=key)
                   {
                     search(root->right,key);
                    }
        
         cout<<"*****element not found*****\t";
   
        
         
         
         }
         
       
       
       
       int main()
       {
        int ch;
        root=NULL;
        do{
        cout<<"\n\n\n*******enter the choice*******\n1:add a node: \n2:display in preorder:\n3:display in postorder:\n4:display in inorder:\n5:total nodes:\n6:leaf nodes \n7:height of tree:\n8:ancester\n9:searching:\n10:exit"<<endl;
        cin>>ch;
        switch(ch)
        {
        
        case 1:
        create();
        break;
        
        case 2:
        preorder(root);
        break;
        
        case 3:
        postorder(root);
        break;
        
        case 4:
        inorder(root);
        break;
        
        case 5:
        cout<<"\n total nodes are:"<<count;
        break;
        
        case 6:
        cout<<"\ntotal leaf nodes"<<leafnode(root);
        break;
        
        case 7:
        cout<<"\nheight of tree :"<<heightof(root);
        break;
         case 8:
        ancester(root);
        break;
        case 9:
        int key;
        cout<<"enter the key to search:"<<endl;
        cin>>key;
        search(root,key);
        break;
       case  10:
        ch=0;
       break;
        default:
        cout<<"\nenter valid choice:\n";
        }
         }while(ch>0);
         return 0;
         }
