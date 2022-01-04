#include <iostream>
#include <vector>
using namespace std;

int n;
int c = 0;
vector <int> column (0,n);
vector <int> diag1 (0,n);
vector <int> diag2 (0,n);

void search(int y){
    if (y==n){
        c++;
        return;
    }
    for (int x = 0; x < n; x++){
        if (column[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1);
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }

}

int main(){
    cin >> n;
    search(0);
    cout << c << "\n";

    return 0;
}