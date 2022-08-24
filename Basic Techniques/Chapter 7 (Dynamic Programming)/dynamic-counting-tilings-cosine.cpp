#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 1; i <= n; i++)

int main(){
    ull n,m; // for n x m grid, calculating the number of solutions for which a number of 1 x 2 tiles can fit in the grid completely
    cin >> n >> m;
    double prodb = 1.0;

    REP(a,ceil(n/2)){
        REP(b,ceil(m/2)){
            prodb *= 4*(cos(M_PI*a/(n+1))*cos(M_PI*a/(n+1)) + cos(M_PI*b/(m+1))*cos(M_PI*b/(m+1))); // O(mn) approach
        } // however,  since the answer is a product of real numbers, a problem when using the formula is how to store the intermediate results accurately.
    }
    
    cout << prodb << "\n";

    return 0;
}