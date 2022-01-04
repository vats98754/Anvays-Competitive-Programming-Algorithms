#include <iostream>
using namespace std;

int main() {
    int x, n;
    int arr[] = {1,6,-2,5,-3,5,12,4,-12,3};
    n = 10;
    sort(arr,arr+n);
    cin >> x;
    
    int k = 0;
    for (int b = n/2; b >= 1; b/= 2){
        while(k+b<n && arr[k+b]<=x) k+=b;
    }
    if (arr[k] == x){
        cout << k << "\n";
    }
    return 0;
}