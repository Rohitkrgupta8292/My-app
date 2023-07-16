#include <bits/stdc++.h>
using namespace std;

//void swap(int arr[], int i, int j){
   // int temp = arr[i];
    //arr[i] = arr[j];
    //arr[j] = temp;
//}

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l-1;
    for(int j = l; j < r; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

void quicksort(int arr[], int l, int r){
    if(l < r){
        int p = partition(arr, l, r);
        quicksort(arr, l, p-1);
        quicksort(arr, p+1, r);
    }
}

int main(){
    int arr[] = {10,8,9,8,5,4,6,3,2,4,7,3,6,8,9,12,4,3,54,3,2,54,65};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"The Sorted Element: ";
    quicksort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}