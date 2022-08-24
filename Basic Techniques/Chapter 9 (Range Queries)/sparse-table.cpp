#include <bits/stdc++.h>

using namespace std;

int n;

vector<vector <int> > ST(const vector<int>& A) {
    vector <vector <int> > ST(__builtin_popcount(n), vector<int>(n));
    ST[0] = A;
    for (int len = 1; len < ST.size(); ++len) {
        for (int i = 0; i < n - (1 << len) + 1; ++i) {
            ST[len][i] = max(ST[len - 1][i], ST[len - 1][(i + 1) << (len - 1)]);
        }
    }
    return ST;
}

int rangeMinimum(const vector<vector <int> >& table, int L, int R) {
    int len = R - L;
    int ans = 1e9;
    for (int i = table.size() - 1; i >= 0; --i) {
        if (len & (1 << i)) {
            ans = min(ans, table[i][L]);
            L += 1 << i;
        }
    }
    return ans;
}

int main(){
    int q;
    cin >> n >> q;
    vector <int> a;

    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        a.push_back(x);
    }

    vector <vector <int> > sparse_table = ST(a);

    while (q--){
        int l, r;
        cin >> l >> r;
        cout << rangeMinimum(sparse_table, l, r) << "\n";
    }

    return 0;
}