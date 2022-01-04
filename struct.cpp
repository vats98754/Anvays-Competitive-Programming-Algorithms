#include "bits/stdc++.h"
using namespace std;

struct P {
    int x, y;
    bool operator<(const P &p) {
        if (x!= p.x) return x < p.x;
        else return y < p.y;
    }
};

bool comp(string a, string b){
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int main(){
    string a = "bruh";
    string b = "brui";
    string c = "brua moment";
    vector <string> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < v.size(); i++){
        cout << v.at(i) << "\n";
    }

    return 0;
}