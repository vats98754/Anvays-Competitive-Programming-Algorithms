#include <iostream>
#include <algorithm>
#include <cmath>
typedef long long ll;
#define REP(i,n) for(ll i = 0; i < n; i++)
using namespace std;

// For an efficient solution, memoization is used, which means that the values of the function are stored in an array after 
// they have been calculated to increase efficiency by not having many many function calls.
// With memoization, the time complexity is O(nk), where n is the target sum and k is the number of coins.
// Without memoization and using the basic recursive algo below, the time complexity may be exponential based on k.

// Here, the iterative method is used, which is better than the recursive model because it is better: shorter, lower constant factors
// The sum of the count is: count(x) = sum(count(x-c)) for all c, as this counts every possibility of coins up to the total x
// If x < 0, count(x) = 0 as there are no solutions.
// If x = 0, count(x) = 1, as there is only one way to form an empty sum
// If x > 0, count(x) = sum(count(x-c)) for all c, as this counts every possibility of coins up to the total x


int main()
{
    ll m,V;
    ll k = (1e+9) + 7;
    cin >> m >> V;
    ll coins[m], count[V+1];

    REP(i,m){
        cin >> coins[i];
    }

    count[0] = 1;
    
    for(ll x = 1; x <= V; x++){
        count[x] = 0;
        for (ll c : coins){
            if (x-c >= 0){
                count[x] += count[x-c];
                count[x] %= k; // to modulo by some constant k, so as to avoid count[x] getting very large
            }
        }
    }

    cout << "The total number of permutations for a total of " << V << " is " << count[V] << "\n";

    return 0;
}