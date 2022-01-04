#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define REP(i,n) for(int i=0; i<n; i++)

int main(){
    int n = 7;
    int a[] = {1,3,5,2,-3,2,5};
    sort(a, a+n);
    REP(i,n){
        cout << a[i] << " ";
    }
    cout << "\n";

    vector<int> v(a,a+n);
    sort(v.begin(), v.end());
    REP(i,n){
        cout << v.at(i) << " ";
    }
    cout << "\n";

    sort(v.rbegin(), v.rend());
    REP(i,n){
        cout << v.at(i) << " ";
    }
    cout << "\n";

    string s = "monkey";
    sort(s.begin(), s.end());
    cout << s << "\n";

    vector< pair<int,int> > p;
    p.push_back(make_pair(1,5));
    p.push_back(make_pair(2,3));
    p.push_back(make_pair(1,2));
    sort(p.begin(),p.end());

    REP(i,p.size()){
        cout << p[i].first << ", " << p[i].second << "\n";
    }

    return 0;
}