#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

#define REP(i,n) for (int i = 1; i<=n; i++)

// The edit distance or Levenshtein distance is the minimum number of editing operations needed to transform a string into 
// another string. The allowed editing operations are as follows:
//• insert a character (e.g. ABC → ABCA) 
//• remove a character (e.g. ABC → AC)
//• modify a character (e.g. ABC → ADC)


// Suppose that we are given a string x of length n and a string y of length m, and we want to calculate the edit distance between x and y. 
// To solve the problem, we define a function distance(a,b) that gives the edit distance between prefixes x[0...a] and y[0...b]. 
// Thus, using this function, the edit distance between x and y equals distance(n − 1, m − 1).

// We can calculate values of distance as follows:
// distance(a, b) = min(distance(a, b − 1) + 1, distance(a − 1, b) + 1,
// distance(a − 1, b − 1) + cost(a, b)).

// Here cost(a,b) = 0 if x[a] = y[b], and otherwise cost(a,b) = 1. 
// The formula considers the following ways to edit the string x:
// • distance(a, b − 1): insert a character at the end of x
// • distance(a−1,b): remove the last character from x
// • distance(a−1,b−1): match or modify the last character of x

// In the two first cases, one editing operation is needed (insert or remove). 
// In the last case, if x[a] = y[b], we can match the last characters without editing, and otherwise one editing operation is needed (modify).
// An (n+1)x(m+1) table or 2D array can be used to store all the values for distance(a,b), 0<=a<=n, 0<=b<=m.

int main(){
    string x,y; // CAPS strings - x to y, find edit distance
    cin >> x >> y;
    int n = x.length();
    int m = y.length();
    int distance[n+1][m+1];

    distance[0][0] = 0;
    REP(i,n){
        distance[i][0] = i;
    }
    REP(j,m){
        distance[0][j] = j;
    }

    REP(i,n){
        REP(j,m){
            if (x[i-1] == y[j-1]){
                distance[i][j] = min(min(distance[i-1][j] + 1, distance[i][j-1] + 1), distance[i-1][j-1]);
            } else distance[i][j] = min(min(distance[i-1][j] + 1, distance[i][j-1] + 1), distance[i-1][j-1] + 1);
        }
    }
    
    cout << "The edit distance is: " << distance[n][m] << "\n";
    
    return 0;
}