#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> permutation;

void search(bool chosen[n]){
    if (permutation.size() == n){
        // process permutation
        for (int j = 0; j < n; j++){
            cout << permutation[j] << " ";
        }
        cout << "\n";
    } else {
        for (int i = 0; i < n; i++){
            if (chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search(chosen);
            chosen[i] = false;
            permutation.pop_back();
        }

    }

}

int main(){
    cin >> n;
    bool chosen[n];
    search(chosen);
    cout << "\n";

    vector<int> perm;
    for (int i = 0; i < n; i++){
        perm.push_back(i);
    }

    do {
        // process permutation
        for (int j = 0; j < n; j++){
            cout << perm[j] << " ";
        }
        cout << "\n";

    } while (next_permutation(perm.begin(), perm.end()));

    return 0;
}