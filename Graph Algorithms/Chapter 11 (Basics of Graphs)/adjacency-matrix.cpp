#include <bits/stdc++.h>

using namespace std;

int n, m; // number of nodes and edges
int adj[MAXN][MAXN]; // adj matrix of size MAXN by MAXN in order to globally,→ declare

int main(){

    cin >> n >> m;
    for(int i = 0; i < m; i++){ // read in each of the m edges
        int a, b;
        int w = 1;
        cin >> a >> b >> w; // omit w if unweighted

        a--; b--; // we subtract 1 because our array is zero-indexed
        adj[a][b] = w; // or set equal to 1 if graph is unweighted
        adj[b][a] = w; // omit this line if graph is directed
    }

    return 0;
}