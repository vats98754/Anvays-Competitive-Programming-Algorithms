#include <bits/stdc++.h>

using namespace std;

struct Edge{
    int a, b, w;
    Edge(int start, int end, int weight):
    a(start), b(end), w(weight)
    {
    }
    bool operator<(const Edge & e) const { // sort order is ascending, by weight
    // to sort in descending order, just negate the value of the compare function.
    return w < e.w;
    }
};

int n, m; // number of nodes and edges
vector<Edge> edges;

int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){ // for each of the m edges
        int a, b, w;
        cin >> a >> b >> w;
        a--; b--; // subtract 1 to maintain zero-indexing of vertices
        edges.push_back(Edge(a, b, w)); // add the edge to the list
    }
    sort(edges.begin(), edges.end()); // sorted in ascending order of weight

    return 0;
}