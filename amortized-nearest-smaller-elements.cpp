#include <iostream>
#include <iterator>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    stack <int> s;
    
    for (int i = 0; i < n; i++){
        while (!s.empty() && s.top() >= a[i]){
            s.pop();
        }
        if (s.empty()){
            cout << "_, ";
        } else cout << s.top() << ", ";

        s.push(arr[i]);
    }

    return 0;
}