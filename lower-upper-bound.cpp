#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x, n;
    int arr[] = {1,6,-2,5,5,5,5,4,-12,3};
    n = 10;
    sort(arr,arr+n);
    cin >> x;

    auto a = lower_bound(arr,arr+n,x)-arr;
    auto b = upper_bound(arr,arr+n,x)-arr;
    cout << "Lower bound: " << a << "\n";
    cout << "Upper bound: " << b << "\n";
    cout << "Number of values equal to x: " << b-a << "\n";
    auto c = equal_range(arr,arr+n,x);
    cout << "Same as: " << c.second - c.first << "\n";


    return 0;
}