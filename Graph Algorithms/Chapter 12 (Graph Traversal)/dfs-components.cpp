#include <bits/stdc++.h>
#include <iostream>
using namespace std;

const int MAXN = 1e5+10;
int m, n;

bool visited[MAXN];
vector <int> adj[MAXN];
int connections[MAXN];

void dfs(int node) {
    visited[node] = true;
    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            dfs(neighbour);
        }
    }
}

int count_components() {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (visited[i]) continue;
        connections[count++] = i;
        dfs(i);
    }
    return count;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = count_components(); // stores the number of components using DFS
    cout << ans-1 << " Bridges to make\n";
    cout << "Connections:\n";
    for (int i = 1; i < ans; ++i) {
        cout << connections[i-1] << "->" << connections[i] << "\n";
    }
    return 0;
}