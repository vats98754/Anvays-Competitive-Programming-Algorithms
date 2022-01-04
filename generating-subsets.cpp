#include <iostream>
#include <vector>
using namespace std;

vector <int> sub;
int n;

void search(int k) {
    if (k == n) {
        for (int i = 0; i < sub.size(); ++i){
            cout << sub[i] << " ";
        }
        cout << "\n";
    } else {
        search(k+1);
        sub.push_back(k);
        search(k+1);
        sub.pop_back();
    }
}

int main(){
    cin >> n;
    
    search(0);

    // the code below compares b's bit sequence with that of 2^i where i is between 0 and n-1 and b is between 0 and 2^n-1 (or (1<<n))
    // b basically has one subset corresponding to it and thus is compared with 2^i's bit sequence to make sure that every
    // subset ending with the element i is accounted for, wherein 2^i <= b < 2^(i+1)
    // this means that for i=2, 4 <= b < 8, and so b = 100,101,110,111 and (1<<i) = 2^i = 4 = 100
    // so now b&(1<<i) == 1 or TRUE for all b given above.
    // Therefore, i becomes a representation of every element to occur in a given subset, and b becomes the filter
    // allowing only its bit representation's 1s to emerge in each subset.

    for (int b = 0; b < (1<<n); ++b){
        vector <int> subset;
        for (int i = 0; i < n; i++){
            if (b & (1<<i)) {
                subset.push_back(i);
                cout << i << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}