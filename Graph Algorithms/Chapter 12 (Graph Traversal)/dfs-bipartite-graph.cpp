#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int MAXN = 1e5+10;
vector <int> adj[MAXN];
bool visited[MAXN];
bool group[MAXN];
int m,n;
bool impossible = false;

void dfs(int node = 1, bool color = 0) {
    visited[node] = true;
    group[node] = color;
    for (int neighbour : adj[node]) {
        if (visited[neighbour]) {
            if (group[neighbour] == color) {
                impossible = true;
            }
        } else {
            dfs(neighbour, !color);
        }
    }
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b; --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a); // assuming the graph is undirected since we are checking for bipartite
    }
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    if (impossible) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 1; i <= n; ++i) {
            cout << "Node " << i << ": Group " << group[i] << "\n";
        }
    }
    return 0;
}