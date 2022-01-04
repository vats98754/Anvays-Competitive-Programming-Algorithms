#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void sum(){
    cout << "n : ";
    int n;
    cin >> n;
    int a[n], s[n];
    cin >> a[0];
    s[0] = a[0];
    
    for (int i = 1; i < n; i++){
        cin >> a[i];
        s[i] = a[i] + s[i-1];
    }
    int lower, upper;
    cout << "Input range: ";
    cin >> lower >> upper;

    if (lower == 0){
        cout << s[upper];
    } else cout << s[upper] - s[lower-1] << "\n";

}

void twoDsum(){
    int x;
    cin >> x;
    int A[x][x], S[x][x];

    for (int j = 0; j < x; j++){
        if (j==0){
            cin >> A[0][0];
            S[0][0] = A[0][0];
        } else {
            cin >> A[0][j];
            S[0][j] = A[0][j] + S[0][j-1];
        }
    }
    // for (int i = 1; i < x; i++){
    //     cin >> A[i][0];
    //     S[i][0] = A[i][0] + S[i-1][0];
    // }

    for (int i = 1; i < x; i++){
        for (int j = 0; j < x; j++){
                if (j==0){
                    cin >> A[i][0];
                    S[i][0] = A[i][0] + S[i-1][0];
                } else {
                    cin >> A[i][j];
                    S[i][j] = A[i][j] + S[i][j-1] + S[i-1][j] - S[i-1][j-1];
                }
        }
    }

    cout << "Enter the top-left and bottom-right (i,j) pairs, separated by spaces: \n";
    int li, lj, ui, uj;
    cin >> li >> lj >> ui >> uj;
    int finalsum = 0;
    if (lj == 0){
        finalsum = S[ui][uj] - S[li-1][uj];
    } else if (li == 0){
        finalsum = S[ui][uj] - S[ui][lj-1];
    } else finalsum = S[ui][uj] - S[ui][lj-1] - S[li-1][uj] + S[li-1][lj-1];

    cout << finalsum << "\n";
}

int main(){
    // sum();
    twoDsum();

    return 0;
}