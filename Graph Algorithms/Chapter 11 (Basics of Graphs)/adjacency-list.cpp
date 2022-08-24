#include <bits/stdc++.h>

using namespace std;

int n, m; // number of nodes and edges
vector<pair<int, int>> adj[10001]; // adjacency list where MAXN is max possible # of nodes
bool visited[10001]; // visited array of size MAXN as well (use MAXN for global,→ declaration)

int main(){
    cin >> n; // reads in number of nodes
    cin >> m; // reads in number of edges

    for(int i = 0; i < m; i++){ // reading in each of the m edges
        int a, b, w;
        cin >> a >> b >> w; // omit w if graph is unweighted
        a--; b--; // we subtract 1 because our array is zero-indexed
        adj[a].push_back({b, w}); // omit w and push_back(b) if graph is unweighted
        adj[b].push_back({a, w}); // omit this line if the graph is directed
    }
    return 0;
}