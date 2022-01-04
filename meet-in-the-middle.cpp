#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int n, x;
    cin >> x >> n;

    vector <int> sumsa;
    vector <int> sumsb;

    int l = floor(n/2);
    int m = ceil(n/2);
    int a[l];
    int b[m];

    for (int i = 0; i < l; i++){
        cin >> a[i];
    }
    for (int j = 0; j < m; j++){
        cin >> b[j];
    }

    for (int c = 0; c < (1<<l); c++){
        vector <int> suba;
        for (int i = 0; i < l; i++){
            if (c&(1<<i)) 
                suba.push_back(a[i]);
        }
        int suma = 0;
        for (int x:suba){
            suma += x;
        }
        sumsa.push_back(suma);
    }

    for (int c = 0; c < (1<<m); c++){
        vector <int> subb;
        for (int i = 0; i < m; i++){
            if (c&(1<<i)) 
                subb.push_back(b[i]);
        }
        int sumb = 0;
        for (int x:subb){
            sumb += x;
        }
        sumsb.push_back(sumb);
    }

    for (int A:sumsa){
        for (int B:sumsb){
            if (A+B == x){
                cout << "Found a match: " << A << " + " << B << " = " << x << "\n";
            }
        }
    }

    return 0;
}