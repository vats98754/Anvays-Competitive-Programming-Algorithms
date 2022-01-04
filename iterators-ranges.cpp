#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

int main(){
    vector<int> v;
    auto itr = v.begin(); // same as above but shorter
    v.push_back(1);
    v.push_back(-2);
    v.push_back(12);
    v.push_back(1);
    v.push_back(4);

    set<string> s1;
    s1.insert("bruh");
    s1.insert("bob");
    s1.insert("bobbert");

    for (auto i = s1.begin(); i!= s1.end(); ++i){
        cout << *i << "\n";
    }

    for (vector<int>::iterator it = v.begin(); it!=v.end(); ++it){
        cout << *it << "\n"; //same as above
    }

    unordered_map <string, int> m;
    m["Anvay"] = 5;
    m["C++"] = 2;
    // since we can't traverse this unordered map with regular indices, we use an iterator
    for(auto it = m.begin(); it != m.end(); ++it){
        auto& key = it->first;
        auto& value = it->second;

        cout << key << " = " << value << "\n";
    }
    //same as:
    for (auto k : m){
        auto& key = k.first;
        auto& value = k.second;

        cout << key << " = " << value << "\n";
    }
    // the following is an even cleaner way to do this with C++17
    // for (auto [key,value] : m){
    //     cout << key << " = " << value << "\n";
    // }

    auto a = s1.end(); --a;
    cout << *a << "\n"; // returns the largest element in a set, sorted in ascending order by default

    //find(x) returns the iterator pointing to the first element with value x, otherwise it points to end
    auto b = s1.find("jeff");
    if (b==s1.end()){
        cout << "1 not found" << "\n";
    }
    //none of these are supported by unordered_set
    auto ia = s1.lower_bound("boy"); //returns an iterator to the smallest element in the set whose value is at least x
    auto ib = s1.upper_bound("boy"); //returns an iterator to the smallest element in the set whose value is larger than x
    auto ic = s1.equal_range("boy");

    //the following code finds the element closest to x in a defined
    set <int> s;
    s.insert(1);
    s.insert(-12);
    s.insert(3);
    s.insert(4);
    s.insert(43);
    s.insert(23);

    auto l = s.lower_bound(10);
    if (l == s.begin()){
        cout << *l << "\n"; // in the case that x is smaller than the very first element
    } else if (l == s.end()){
        --l;
        cout << *l << "\n"; // in the case that x is larger than the very last element
    } else {
        int a = *l; --l;
        int b = *l;
        if (10-b < a-10) cout << b << "\n"; // basic comparison of absolute different between x and a and x and b
        else cout << a << "\n";
    }
    
    return 0;
}