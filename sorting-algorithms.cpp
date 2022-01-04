#include <iostream>
#include <cmath>
using namespace std;
#define REP(i,n) for(int i = 0; i < n; i++)


void bubble_sort (int n, int arr[]){
    REP(i,n){
        REP(j,n-1){
            if(arr[j] > arr[j+1]){
                int c = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = c;
            }
        }
    }
}

void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	int i = 0;

	int j = 0;

	int k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[],int l,int r){
	if(l>=r){
		return;
	}
	int m = l + (r-l)/2;
	mergeSort(arr,l,m);
	mergeSort(arr,m+1,r);
	merge(arr,l,m,r);
}

void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
    cout << "\n";
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int j = 0; j < n; j++){
        int a;
        cin >> a;
        arr[j] = a;
    }

    bubble_sort(n, arr); // O(n^2)
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    printArray(arr, n); 

    return 0;
}