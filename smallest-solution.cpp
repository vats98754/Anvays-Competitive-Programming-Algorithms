#include <iostream>
#include <algorithm>
using namespace std;

bool ok(int x){
    if (x >= 100) return true;
    else return false;
}

int main() {
    int x = -1;
    for (int b = 10000; b >= 1; b/=2){
        while(!ok(x+b)) x+=b;
        cout << x << " " << b << "\n";
    }
    int k = x+1;
    cout << k << "\n";

    return 0;
}