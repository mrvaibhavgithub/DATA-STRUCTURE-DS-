#include <iostream>
#include <climits>
#include <string>
using namespace std;

const int MAX_CITIES = 100;

void create(int mt[MAX_CITIES][MAX_CITIES], int v) {
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (i == j) {
                mt[i][j] = 0;
            } else {
                mt[i][j] = -1;
            }
        }
    }
}

void addedge(int m[MAX_CITIES][MAX_CITIES], int s_index, int d_index, int weight) {
    m[s_index][d_index] = weight;
    m[d_index][s_index] = weight;
}

void printmt(int m[MAX_CITIES][MAX_CITIES], int v, string cities[MAX_CITIES]) {
    for (int i = 0; i < v; i++) {
        cout << cities[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < v; i++) {
        cout << cities[i] << " ";
        for (int j = 0; j < v; j++) {
            if (m[i][j] == -1) {
                cout << "NA ";
            } else {
                cout << m[i][j] << " ";
            }
        }
        cout << endl;
    }
}

void findMST(int graph[MAX_CITIES][MAX_CITIES], int vertices, string cities[MAX_CITIES]) {
    int parent[MAX_CITIES];    
    int key[MAX_CITIES];        
    bool inMST[MAX_CITIES];   

    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        inMST[i] = false;
    }

    key[0] = 0;    
    parent[0] = -1; 

    for (int count = 0; count < vertices - 1; count++) {
        int minKey = INT_MAX, u;
        for (int v = 0; v < vertices; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        inMST[u] = true;

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] != -1 && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Minimum Spanning Tree (MST):\n";
    for (int i = 1; i < vertices; i++) {
        cout << cities[parent[i]] << " - " << cities[i] << " (Weight: " << graph[i][parent[i]] << ")\n";
    }
}

int main() {
    int numc, nume;
    int m[MAX_CITIES][MAX_CITIES];
    cout << "Enter the number of cities: ";
    cin >> numc;
    cout << "Enter the number of edges: ";
    cin >> nume;

    create(m, numc);

    string cities[MAX_CITIES];
    cout << "Enter the names of cities: ";
    for (int i = 0; i < numc; i++) {
        cin >> cities[i];
    }

    string s_city, d_city;
    int distance;
    for (int i = 0; i < nume; i++) {
        cout << "Enter the source -> destination -> distance: ";
        cin >> s_city >> d_city >> distance;

        int s_index = -1, d_index = -1;
        for (int i = 0; i < numc; i++) {
            if (cities[i] == s_city) {
                s_index = i;
            }
            if (cities[i] == d_city) {
                d_index = i;
            }
        }
        if (s_index != -1 && d_index != -1) {
            addedge(m, s_index, d_index, distance);
        } else {
            cout << "Invalid city name!" << endl;
        }
    }

    printmt(m, numc, cities);

    findMST(m, numc, cities);

    return 0;
}
