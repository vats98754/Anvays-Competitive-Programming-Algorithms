#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

// To calculate a value of length(k), we should find a position i < k for which array[i] < array[k] and length(i) is as large as
// possible. Then we know that length(k) = length(i) + 1, because this is an optimal way to add array[k] to a subsequence.
// However, if there is no such position i, then length(k) = 1, which means that the subsequence only contains array[k].

int main(){
    ll n;
    cin >> n;
    ll a[n];
    ll length[n];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int k = 0; k < n; k++){
        length[k] = 1;
        for (int i = 0; i < k; i++){
            if (a[i] < a[k]){
                length[k] = max(length[k], length[i]+1);
            }
        }
    }

    cout << *max_element(length,length+n) << "\n"; // time complexity is O(n^2), but is possible to have O(nlogn) with another method

    return 0;
}