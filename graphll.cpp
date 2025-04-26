#include<iostream>
using namespace std;

const int MAXI = 100;

class node {
public:
    string city;
    int distance;
    node* next;

    node(string c, int d) {
        city = c;
        distance = d;
        next = NULL;
    }
};

class graph {
public:
    string cities[MAXI]; 
    node* adjList[MAXI]; 

   
    graph() {
        for (int i = 0; i < MAXI; i++) {
            adjList[i] = NULL;
        }
    }

    void addcities(int size) {
        string city;
        for (int i = 0; i < size; i++) {
            cout << "Enter city " << i + 1 << ": ";
            cin >> city;
            cities[i] = city;
        }
    }

    int findindex(string fcity, int size)
     {
        for (int i = 0; i < size; i++) {
            if (cities[i] == fcity) {
                return i;
            }
        }
        return -1; 
    }

    void addedge(int e, int size)
     {
        string source, dest;
        int dist;

        for (int i = 0; i < e; i++) 
        {
            cout << "Enter edge " << i + 1 << " (source city -> destination city -> distance): ";
            cin >> source >> dest >> dist;

            int srcIndex = findindex(source, size);
            int destIndex = findindex(dest, size);

            if (srcIndex != -1 && destIndex != -1)
             {
                
                node* newNode = new node(dest, dist);
                newNode->next = adjList[srcIndex];
                adjList[srcIndex] = newNode;

                
                newNode = new node(source, dist);
                newNode->next = adjList[destIndex];
                adjList[destIndex] = newNode;
            } else {
                cout << " cities not found!" << endl;
            }
        }
    }

    void displayGraph(int size) {
        for (int i = 0; i < size; i++) {
            cout << "City: " << cities[i] << " is connected to: "<<endl;
            node* temp = adjList[i];
            while (temp != NULL) {
                cout << temp->city << " (" << temp->distance << " km) "<<endl;
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    graph g;
    int numc, nume;

    cout << "Enter the number of cities: ";
    cin >> numc;
    g.addcities(numc);

    cout << "Enter the number of edges: ";
    cin >> nume;
    g.addedge(nume, numc);

    
    g.displayGraph(numc);

    return 0;
}
