#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define REP(i,n) for (int i = 1; i<=n; i++)

int main(){
    int n, wt;
    cin >> n >> wt;
    int weights[n+1], values[n+1], valuetable[n+1][wt+1]; // assume input is sorted by weight
    vector < pair <int, int> > m;

    // m[0].first = 0; // assume input is sorted by weight
    // m[0].second = 0; // assume input is sorted by weight

    // REP(i,n){ // assume input is sorted by weight
    //     int a,b;
    //     cin >> a >> b;
    //     m.push_back(make_pair(a,b));
    // }

    // sort(m.begin(), m.end()); // assume input is sorted by weight

    // REP(i,n){ // assume input is sorted by weight
    //     weights[i] = m[i].first;
    //     values[i] = m[i].second;
    // }

    weights[0] = 0;
    values[0] = 0;

    REP(i,n){
        cin >> weights[i] >> values[i];
    }

    for (int j = 0; j <= wt; j++){
        valuetable[0][j] = 0;
    }

    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= wt; j++){
            if (j < weights[i]){
                valuetable[i][j] = valuetable[i-1][j];
            } else {
                valuetable[i][j] = max(values[i]+valuetable[i-1][j-weights[i]], valuetable[i-1][j]);
            }
        }
    }

    int opt = valuetable[n][wt];
    cout << opt << " is the maximum value possible, with weights: \n";

    while (opt > 0){
        if (valuetable[n][wt] > valuetable[n-1][wt]){
            cout << weights[n] << "\n";
            opt -= values[n];
            wt -= weights[n];
            n -= 1;
        } else n-=1;
    }

    return 0;
}