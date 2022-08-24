#include <bits/stdc++.h>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> adj[100001];
bool visited[100001];
int distance[100001];

int main() {
    queue <int> q;

    distance[adj[0][0]] = 0;
    visited[adj[0][0]] = true;
    q.push(adj[0][0]);

    while (!q.empty()) {
        int s = q.front();
        q.pop();
        visited[s] = true;

        // process node s
        
        for (auto child : adj[s]) {
            if (visited[child]) return;
            visited[child] = true;
            distance[child] = distance[s] + 1;
            q.push(child);
        }
    }
    return 0;
}