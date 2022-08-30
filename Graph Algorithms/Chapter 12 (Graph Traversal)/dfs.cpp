// #include <bits/stdc++.h>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> adj[10001]; // the adjacency list describing the graph being traversed
bool visited[10001]; // stores true if the node is visited; index is equal to node (hash map can be used)

// Recursive method for Depth-First Search
void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;

    // process node s

    for (int u: adj[s]) {
        dfs(u);
    }
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
    }
    // DFS has a time-complexity of O(n + m) where n is the number of nodes and m is the number of edges
    dfs(x); // assuming x is the starting node
    return 0;
}