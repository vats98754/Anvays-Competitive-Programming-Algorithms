#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int MAXN = 1e5+10;
vector <int> adj[MAXN];
bool visited[MAXN];
bool cycle = false;
int m,n;

void dfs (int node) {
    visited[node] = true;
    for (int x : adj[node]) {
        if (!visited[x]) {
            dfs(x);
        } else {
            cycle = true;
            break;
        }
    }
}

int count_components() {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;
        ++count;
        dfs(i);
    }
    return count;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a); // assuming the graph is undirected since we are checking for bipartite
    }
    dfs(0); // assuming the nodes are from 1 to n; they are 0-indexed by us, hence dfs(0)
    int numComponents = count_components(); // stores number of components; if any component with k nodes has more than 
    // k-1 edges, there is a cycle in the graph;

    cout << cycle << "\n";
    return 0;
}