#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main(){
    int n, x;
    cin >> x >> n;
    int arr[n];
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    int sum = arr[0];
    int l = 0;
    int r = 0;

    while (l <= r) {
        if (sum == x) {
            cout << "Positions {" << (l+1) << ", " << (r+1) << "}, so subtract one from each for the indices\n";
            break;
        } else if (sum > x){
            sum -= arr[l];
            l++;
        } else {
            r++;
            sum += arr[r];
        }
    }
    if (r==n && sum != x){
        cout << "No such sum found\n";
    }

    return 0;
}