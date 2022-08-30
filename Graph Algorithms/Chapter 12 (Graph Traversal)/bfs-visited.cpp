#include <bits/stdc++.h>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 100001;

vector <int> adj[MAX_N];
unordered_set <int> nodes;
bool visited[MAX_N] = {false};
int dist[MAX_N];

int bfs(int node) {
    queue <int> bfsQueue;
    vector <bool> visited;
    int visCount = 0;

    visited[node] = true;
    bfsQueue.push(node);

    // process node

    while (!bfsQueue.empty()) {
        for (auto neighbour : adj[node]) {
            if (!visited[node]) {
                visited[node] = true;
                nodes.erase(node);
                dist[neighbour] = dist[node] + 1;
                bfsQueue.push(neighbour);
            }
        }
        bfsQueue.pop();
        visCount += 1;
    }
    return visCount;
}

int main() {
    int m, x;
    cin >> m; // reads in number of edges

    for(int i = 0; i < m; i++){ // reading in each of the m edges
        int a, b;
        cin >> a >> b;
        a--; b--; // we subtract 1 because our array is zero-indexed
        x = a;
        adj[a].push_back(b);
        adj[b].push_back(a); // symmetric indexing as graph is undirected
        nodes.insert(a);
        nodes.insert(b);
    }
    // BFS has a time-complexity of O(n + m) where n is the number of nodes and m is the number of edges
    dist[x] = 0; // assuming x is the starting node
    int numNodes = nodes.size(); // keeps count of number of nodes in each component
    vector <int> componentSize; // stores the size of each component, indexed from 0 to n-1, given there are n components
    int components = 0; // keeps count of number of separate components in the graph
    
    // assuming each component has at least 2 nodes as the adj list is defined using edges
    for (int x : nodes) {
        componentSize[components] = bfs(x);
        cout << "Component " << components << ": " << componentSize[components] << "\n";
        components += 1;
    }
    cout << numNodes << "\n";
    cout << components << "\n";

    return 0;
}