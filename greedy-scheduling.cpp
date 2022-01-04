#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

// Many scheduling problems can be solved using greedy algorithms. A classic problem is as follows: 
// Given n events with their starting and ending times, find a schedule that includes as many events as possible. 
// It is not possible to select an event partially.

// Basically, sort in increasing order of e[i] the end times, and then check if the end time of the event being currently
// considered is less than or equal to the start time of the next event. Now, make sure to repeat this and start with
// the ending time of the 0th event.

int main(){
    int n; // number of events
    int c = 0;
    cin >> n;
    deque<pair <int,int> > x; // ending and starting times as a pair to keep corresponding pairs together after sorting

    int a,b;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        pair <int,int> p = make_pair(b,a);
        x.push_back(p); // enter starting times first but assign to second element and vice versa with ending times
    }

    sort(x.begin(), x.end());
    c++;
    int j = 0;
    int s[n], e[n];

    for (int i = 0; i < n; i++){
        e[i] = x[i].first;
        s[i] = x[i].second;
    }

    for (int i = 1; i < n; i++){
        if (e[j] <= s[i]){
            c++;
            j = i;
        }
    }

    cout << c << "\n";

    return 0;

    //The idea is to always select the next possible event that ends as early as possible.
    //It turns out that this algorithm always produces an optimal solution. 
    //The reason for this is that it is always an optimal choice to first select an event that ends as early as possible. 
    //After this, it is an optimal choice to select the next event using the same strategy, etc., until we cannot select any more events.
    //One way to argue that the algorithm works is to consider what happens if we first select an event that ends later than the event that ends as early as possible. 
    //Now, we will have at most an equal number of choices how we can select the next event. Hence, selecting an event that ends later can never yield a better solution, and the greedy algorithm is correct.
}