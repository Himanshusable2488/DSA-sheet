#include <iostream>
#include <algorithm>
using namespace std;

//12356789  //4
//432675     //1

int missing(int arr[], int n){
    sort(arr,arr+n);
    for(int i = 0; i < n-1; i++){
        if(arr[i+1] != arr[i]+1)return arr[i]+1;
    }
}


int main(){
    int arr[] = {1,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int a = missing(arr, n);
    cout << a << endl;
    return 0;
}