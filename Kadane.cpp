#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int kadane(ll n, ll bruh[]){
    ll global_sum = bruh[0], local_sum = bruh[0];

    for (ll i = 1; i < n; i++){
        local_sum = max(bruh[i], local_sum+bruh[i]);
        global_sum = max(global_sum,local_sum);
    }

    return global_sum;
}

int main(){
    ll n;
    cin >> n;
    ll bruh[n];
    for (ll j = 0; j < n; j++){
        ll a;
        cin >> a;
        bruh[j] = a;
    }

    cout << kadane(n, bruh) << "\n"; // O(n)
    return 0;
}