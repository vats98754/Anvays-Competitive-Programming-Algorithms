#include <iostream>
#include <algorithm>
using namespace std;

int n;

int sum(int BITree[], int k){
    int s = 0;
    while (k >= 1){
        s += BITree[k];
        k -= k&-k;
    }
    return s;
}

void add(int k, int x, int BITree[]){
    while (k <= n){
        BITree[k] += x;
        k += k&-k;
    }
}

void updateBIT(int BITree[], int n, int index, int val)
{
    // index in BITree[] is 1 more than the index in arr[]
    index = index + 1;
  
    // Traverse all ancestors and add 'val'
    while (index <= n)
    {
    // Add 'val' to current node of BI Tree
    BITree[index] += val;
  
    // Update index to that of parent in update View
    index += index & (-index);
    }
}
  
// Constructs and returns a Binary Indexed Tree for given
// array of size n.
int *constructBITree(int arr[], int n)
{
    // Create and initialize BITree[] as 0
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;
  
    // Store the actual values in BITree[] using update()
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
  
    // Uncomment below lines to see contents of BITree[]
    for (int i=1; i<=n; i++)
        cout << BITree[i] << " ";
  
    return BITree;
}

int main(){
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int *BITree = constructBITree(arr, n);

    cout << "Input the upper bound for the sum: ";
    int upper;
    cin >> upper;

    cout << sum(BITree, upper) << ". Increment an index by delta: ";
    
    int index, delta;
    cin >> index >> delta;
    add(index,delta,BITree);
    cout << "Updated sum = " << sum(BITree, upper) << "\n";

    return 0;
}