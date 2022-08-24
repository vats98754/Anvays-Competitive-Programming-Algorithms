#include <iostream>
#include <algorithm>
using namespace std;

//Let us now consider a problem where we are given n tasks with durations and deadlines and our task is to choose an order to
//perform the tasks. For each task, we earn d − x points where d is the task’s deadline and x is the moment when we finish the task. 
//What is the largest possible total score we can obtain?

// Basically, this depends solely on sumx, and we minimize sumx by sorting x[n] and doing tasks in increasing order of x[i]
// sumx = n*x[0] + (n-1)*x[1] + ... + (n-i)*x[i] + ... + x[n-1] has to be minimized by minimizing x[0] most, x[1] the next, and so on.

int main(){
    int n, d = 0;
    cin >> n; // enter number of tasks
    int x[n];

    for (int i = 0; i < n; i++){
        int a = 0;
        cin >> x[i] >> a; // enter duration followed by deadline
        d += a;
    }

    sort(x,x+n);
    int sumx = 0;
    for (int i = 0; i < n; i++){
        sumx += (n-i)*x[i];
    }
    cout << "The total minimum score is: " << d-sumx << "\n";
    return 0;

    //Surprisingly, the optimal solution to the problem does not depend on the deadlines at all, but a correct greedy strategy 
    //is to simply perform the tasks sorted by their durations in increasing order. 
    //The reason for this is that if we ever perform two tasks one after another such that the first task takes longer than 
    //the second task, we can obtain a better solution if we swap the tasks.
}