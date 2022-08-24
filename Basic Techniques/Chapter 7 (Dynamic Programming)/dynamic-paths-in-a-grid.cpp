#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    int value[N+1][N+1], sum[N+1][N+1];

    for (int i = 1; i <= N; i++){
        // cout << "Enter the " << (i+1) << "th line: " << "\n";
        value[i][0] = 0;
        sum[i][0] = 0;
        for (int j = 1; j <= N; j++){
            cin >> value[i][j];
            value[0][j] = 0;
            sum[0][j] = 0;
        }
    }

    for (int y = 1; y <= N; y++){
        for (int x = 1; x <= N; x++){
            sum[y][x] = max(sum[y-1][x],sum[y][x-1]) + value[y][x];
        }
    }

    cout << sum[N][N] << " is the maximum sum" << "\n";

    return 0;
}