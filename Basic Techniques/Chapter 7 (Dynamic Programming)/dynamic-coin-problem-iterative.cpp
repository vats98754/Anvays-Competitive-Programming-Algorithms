#include <iostream>
#include <algorithm>
#include <cmath>
#define REP(i,n) for(int i = 0; i < n; i++)
using namespace std;

// For an efficient solution, memoization is used, which means that the values of the function are stored in an array after 
// they have been calculated to increase efficiency by not having many many function calls.
// With memoization, the time complexity is O(nk), where n is the target sum and k is the number of coins.
// Without memoization and using the basic recursive algo below, the time complexity may be exponential based on k.

// Here, the iterative method is used, which is better than the recursive model because it is better: shorter, lower constant factors


// m is size of coins array (number of different coins)
int minCoins(int coins[], int first[], int m, int V)
{
    // table[i] will be storing the minimum number of coins required for the ith value.  So table[V] will have result
    int table[V+1];
 
    // Base case (If given value V is 0)
    table[0] = 0;
 
    // Initialize all table values as Infinite
    for (int i=1; i<=V; i++){
        table[i] = INFINITY;
    }

    // Compute minimum coins required for all values from 1 to V
    for (int i=1; i<=V; i++)
    {
        // Go through all coins smaller than i
        for (int j=0; j<m; j++){
          if (coins[j] <= i) // or 0 <= x-c
          {
            int sub_res = table[i-coins[j]]; // sub resolution
            if (sub_res != INFINITY && sub_res + 1 < table[i]){ // second condition is the same as min(value[x], value[x-c]+1)
                table[i] = sub_res + 1;
                first[i] = coins[j];
            }
          }
        }
    }
   
      if(table[V]==INT_MAX)
        return -1;
   
    return table[V];
}
 
// Driver program to test above function
int main()
{
    int m,V;
    cin >> m >> V;
    int coins[m];
    int first[V+1];

    REP(i,m){
        cin >> coins[i];
    }

    cout << "Minimum coins required is " << minCoins(coins, first, m, V) << "\n";

    while (V > 0) { // particular solution
        cout << first[V] << "\n"; // prints what the value[n]th coin was
        V -= first[V];
    }

    return 0;
}