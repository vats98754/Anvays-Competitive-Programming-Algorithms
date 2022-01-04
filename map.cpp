#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
    map<string,int> m;
    m["a"] = 1;
    m["b"] = 1;
    m["c"] = 3;
    cout << m["bruh"] << "\n";

    if (m.count("a")){
        cout << m.count("a") << "\n";
        m.erase("a");
    }

    for (auto x:m){
        cout << x.first << " " << x.second << "\n";
    }

    unordered_map<string, int> p;
    p["a"] = 1;
    p["b"] = 1;
    p["c"] = 3;
    for (auto x:p){
        cout << x.first << " " << x.second << "\n";
    }

    return 0;
}