#include <iostream>
#include <algorithm>

using namespace std;

void ascSort(int arr[],int n){
    sort(arr, arr+n);
}

void ascSort2(int arr[], int n){
    int low = 0, mid = 0, high = n-1;
    while(high >= mid){
        if(arr[mid] == 1)mid++;
        else if(arr[mid] > 1){
            swap(arr[mid], arr[high]);
            high--;
        }else{
            swap(arr[low],arr[mid]);
            low++; mid++;
        }
    }
}

int main(){
    int arr[] = {1, 0, 2, 0, 0, 1, 2, 2, 1, 0, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    // ascSort(arr,n);
    ascSort2(arr, n);
    for(int i = 0; i< n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}