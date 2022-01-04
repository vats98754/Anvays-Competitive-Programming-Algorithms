#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string a = "hatti";
    string b = a + a;
    cout << b << "\n";
    b[5] = 'v';
    cout << b << "\n";
    string c = b.substr(3,8); // starts at index 3 and has length 6
    cout << c << "\n";

    return 0;
}