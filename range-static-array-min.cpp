#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    int log[N+1];
    int array[N];

    log[1] = 0;
    for (int i = 2; i <= N; i++){
        log[i] = log[i/2] + 1;
    }

    int K = floor(log2(N));
    int st[N][K + 1];

    for (int i = 0; i < N; i++){
        cin >> array[i];
        st[i][0] = array[i];
    }

    for (int j = 1; j <= K; j++){
        for (int i = 0; i + (1 << j) <= N; i++){
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    int L,R;

    cout << "Input the range: ";
    cin >> L >> R;

    int j = log[R - L + 1];
    int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
    cout << minimum << "\n";

    return 0;
}