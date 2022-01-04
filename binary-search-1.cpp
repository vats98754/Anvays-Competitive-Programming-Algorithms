#include "bits/stdc++.h"
using namespace std;

int main(){
    int x, n, a, b;
    cin >> x >> n;
    int arr[n];
    a = 0;
    b = n-1;
    for(int i=0; i<n; i++){
        int s;
        cin >> s;
        arr[i] = s;
    }

    sort(arr,arr+n);

    while(a <= b){
        int k = (a+b)/2;
        if(arr[k] == x){
            cout << k << "\n";
        }
        if(arr[k] > x) b=k-1;
        else a = k+1;
    }

    int k = 0;
    for (int c=n/2; c>=1; c/=2){
        while(k+c<n && arr[k+c]<=x) k+=c;
    }
    if (arr[k] == x) cout << k << "\n";

    return 0;
}