#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector <int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(5);

    for (auto x:v){
        cout << x << " ";
    }
    // v.pop_back();
    cout << v.back();
    cout << "\n";

    vector <int> a(10,5);
    for (auto x:a){
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}