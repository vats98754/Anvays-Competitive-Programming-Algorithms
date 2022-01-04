#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, k;
    int count = 0;
    cin >> n >> k;
    int coins[k];

    for (int i = 0; i < k; i++){
        cin >> coins[i];
    }
    sort(coins, coins + k);
    cout << "\n";
    
    for (int j = k-1; j >= 0; --j){
        while (n/coins[j] > 0){
            ++count;
            cout << coins[j] << " ";
            n -= coins[j];
        }
    }
    cout << "\n" << count << "\n";

    return 0;
}