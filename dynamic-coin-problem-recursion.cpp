#include <iostream>
#include <algorithm>
#include <cmath>
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

// A recursive, foolproof solution to the greedy coin problem that prints the min number of coins = {c1,c2,...,cn} 
// required to sum to x, both of which are provided as input.
// This uses dynamic programming, a combination of the efficiency of greedy algorithms with the correctness of complete search.
// Dynamic programming can be applied if the problem can be divided into overlapping subproblems that can be solved independently.

// For an efficient solution, memoization is used, which means that the values of the function are stored in an array after 
// they have been calculated to increase efficiency by not having many many function calls.
// With memoization, the time complexity is O(nk), where n is the target sum and k is the number of coins.
// Without memoization and using the basic recursive algo below, the time complexity may be exponential based on k.

int main(){
    int x, n;
    cin >> n >> x;
    int coins[n];
    int value[x+1]; // for a particular value of N (maybe x+1), this array stores the value for solve(x) in index x
    bool ready[x+1]; // this array stores whether the value for solve(x) or value[x] has already been found for index x

    REP(i,n){
        cin >> coins[i];
    }
    
    cout << solve(x, ready, value, coins) << "\n";

    return 0;
}

int solve(int x, bool ready[], int value[], int coins[]){
    if (x < 0) return INFINITY;
    if (x == 0) return 0;
    if (ready[x]) return value[x];
    int best = INFINITY;
    for (int c = 0; c < n; c++){
        best = min(best, solve(x-c, ready, value, coins) + 1);
    }
    ready[x] = true;
    value[x] = best;
    return best;
}