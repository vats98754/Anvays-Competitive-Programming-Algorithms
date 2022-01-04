#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

int main(){
    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(5);
    cout << s.count(3) << "\n"; // all set elements are unique, so count is either 0 or 1
    cout << s.count(4) << "\n";
    s.erase(3);
    s.insert(4);
    cout << s.count(3) << "\n";
    cout << s.count(4) << "\n";

    // set<int> k = {2,4,5,6}; // correct syntax, but the compiler is old
    set<int> k;
    k.insert(2);
    k.insert(4);
    k.insert(5);
    k.insert(6);
    cout << k.size() << "\n";
    for (auto x : k){
        cout << x << "\n";
    }


     // declaring set for storing string data-type
    unordered_set <string> stringSet ;
 
    // inserting various string, same string will be stored
    // once in set
 
    stringSet.insert("code") ;
    stringSet.insert("in") ;
    stringSet.insert("c++") ;
    stringSet.insert("is") ;
    stringSet.insert("fast") ;
 
    string key = "slow" ;
 
    //  find returns end iterator if key is not found,
    //  else it returns iterator to that key
 
    if (stringSet.find(key) == stringSet.end())
        cout << key << " not found" << endl << endl ;
    else
        cout << "Found " << key << endl << endl ;
 
    key = "c++";
    if (stringSet.find(key) == stringSet.end())
        cout << key << " not found\n" ;
    else
        cout << "Found " << key << endl ;
 
    // now iterating over whole set and printing its
    // content
    cout << "\nAll elements : ";
    unordered_set<string> :: iterator itr;

    for (auto x : stringSet){
        cout << x << endl;
    }

    // for (itr = stringSet.begin(); itr != stringSet.end(); itr++){
    //     cout << (*itr) << endl;
    // } // Another way to do this

    multiset<int> a;
    a.insert(5);
    a.insert(5);
    a.insert(5);
    cout << a.count(5) << "\n"; // 3

    s.erase(s.find(5)); // erases only one instance of 5
    s.erase(5); //erases all instances of 5
    
    return 0;
}