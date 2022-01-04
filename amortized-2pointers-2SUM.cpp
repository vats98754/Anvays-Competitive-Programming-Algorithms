#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, x;
    cin >> x >> n;
    int arr[n];
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    sort(arr,arr+n);
    int l = 0;
    int r = n-1;
    int sum = arr[l] + arr[r];

    while (l <= r) {
        if (sum == x) {
            cout << "Elements: {" << arr[l] << ", " << arr[r] << "}\n";
            break;
        } else if (sum > x){
            --r;
        } else {
            ++l;
        }
        sum = arr[l] + arr[r];
    }
    if (sum != x){
        cout << "No such sum found\n";
    }

    return 0;
}