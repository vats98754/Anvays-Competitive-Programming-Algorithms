#include <iostream>
#include <algorithm>
using namespace std;

int f(int x){
    if (x >= 1000) return 2000 - x;
    else return x;
}

int main() {
    int x = -1;
    for (int b = 10000; b >= 1; b/=2){
        while(f(x+b) < f(x+b+1)) x+=b;
        cout << x << " " << b << "\n";
    }
    int k = x+1;
    cout << k << "\n";

    return 0;
}