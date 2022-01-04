#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// The term knapsack refers to problems where a set of objects is given, and subsets with some properties have to be found. 
// Knapsack problems can often be solved using dynamic programming. In this section, we focus on the following problem: 
// Given a list of weights [w1,w2,...,wn], determine all sums that can be constructed using the weights.

int main(){  
    // The following is the 2D array solution with time complexity O(nW)

    // possible[0][0] = true;
    // for (int k = 1; k <= n; k++) {
    //     for (int x = 0; x <= W; x++) {
    //        if (x-w[k] >= 0) possible[x][k] |= possible[x-w[k]][k-1];
    //        possible[x][k] |= possible[x][k-1];
    //     } 
    // }

    int n, A;
    int W = 0;
    cin >> n >> A;
    int w[n];

    for (int i = 0; i < n; i++){
        cin >> w[i];
        W += w[i];
    }

    sort(w,w+n);
    bool possible[W+1];

    // By going from right to left in the array of weights w[n], since it is sorted in ascending order, from right to left it 
    // is in descending order. This means that since this algorithm tests whether a weight from a knapsack is needed to form part
    // of the total sum A that is input, it is better to go from right to left.

    possible[0] = true;
    for (int k = 0; k < n; k++) {
        for (int x = W; x >= 0; x--) { // Since if all the weights are selected, we can start from right to left, where x=W
            cout << "x = " << x << ", k = " << k << ", possible[x] = " << possible[x] << ", possible[x+w[k]] = " << possible[x+w[k]] << "\n";
            if (possible[x]) {
               possible[x+w[k]] = true; // once x = W - w[k], possible[x+w[k]] = true if any k of the weights satisfy this equation, hence the OR || operator in the other algorithms
               // however, for some given x, if possible[x] values for all k are all false, then possible[x] is false for sure
            }
        }
    }

    cout << possible[A] << "\n";

    return 0;
}