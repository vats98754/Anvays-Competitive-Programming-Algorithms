#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int i;
    deque <int> Qi;
    cout << "{";

    for (i = 0; i < k; ++i)
    {
     
        // For every element, the previous
        // smaller elements are useless so
        // remove them from Qi
        while ((!Qi.empty()) && arr[i] <= arr[Qi.back()])
           
             // Remove from rear
            Qi.pop_back();
 
        // Add new element at rear of queue
        Qi.push_back(i);
    }
    // Process rest of the elements,
    // i.e., from arr[k] to arr[n-1]
    for (; i < n; ++i)
    {
     
        // The element at the front of
        // the queue is the largest element of
        // previous window, so print it
        cout << arr[Qi.front()] << ", ";
 
        // Remove the elements which
        // are out of this window
        while ((!Qi.empty()) && Qi.front() <= i - k)
            // Remove from front of queue
            Qi.pop_front();
 
        // Remove all elements
        // smaller than the currently
        // being added element (remove
        // useless elements)
        while ((!Qi.empty()) && arr[i] <= arr[Qi.back()])
            Qi.pop_back();
 
        // Add current element at the rear of Qi
        Qi.push_back(i);
    }
 
    // Print the maximum element
    // of last window
    cout << arr[Qi.front()] << "}\n";

    return 0;
}