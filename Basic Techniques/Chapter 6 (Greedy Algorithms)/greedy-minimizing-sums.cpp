#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Consider the sum |A1 −x|^c +|A2 −x|^c +···+|An −x|^c, where the list of numbers a = {A1, A2, ... , An} is provided
// The question is to minimize the above sum for a given c-value, by finding the optimal x value.
// For this, there are two main cases (c = 1, and c = 2):

// For c = 1, x is equal to the median of list a [or the middle number at index floor(n/2)].
// The median is an optimal choice, because if x is smaller than the median, the sum becomes smaller by increasing x, 
// and if x is larger then the median, the sum becomes smaller by decreasing x. 
// Hence, the optimal solution is that x is the median.
// If n is even and there are two medians, both medians and all values between them are optimal choices.
// Find total by using conditionals and adding the numbers up

// For c = 2, x is equal to the mean of list a [equal to (A1+A2+...+An)/n = s/n]
// This result can be derived by just expanding all the terms to get a quadratic as follows:
// n * x^2 - 2*(A1+A2+...+An) * x + (A1^2 + A2^2 + ... + An^2) = n*x^2 - 2s*x + (A1^2 + A2^2 + ... + An^2)
// total = n*(s/n)^2 - 2s*(s/n) + sq
// Thus, total = sq - 2s^2/n
// Since this is a parabola, min(x) = -b/2a = -(-2s)/2n = s/n or the mean

// In either case, the values of c, n, and list elements are input
// and the minimum value(s) for x are printed, followed by the total sum for c=1 or c=2

int main(){
    int c,n, s = 0, total = 0;
    long long sq = 0;
    double x;
    cin >> c >> n; // input c first, then n, the number of values in the list
    int a[n];

    for (int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
        sq += a[i] * a[i];
    }

    if (c==1) {
        sort(a,a+n);
        if (!(n%2)){
            x = a[n/2-1];
            cout << "x = " << x << " or x = " << a[n/2] << "\n";
        } else {
            x = a[(n-1)/2];
            cout << "x = " << x << "\n";
        }

        for (int i = 0; i < n; i++){
            if (x > a[i]){
                total += x - a[i];
            } else total += a[i] - x;
        }

    } else if (c==2) {
        x = s/n;
        cout << "x = " << x << "\n";
        total = sq - s*s/n;
    }

    cout << "Total is: " << total << "\n";

    return 0;
}