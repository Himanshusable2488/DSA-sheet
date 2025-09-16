#include <iostream>
using namespace std;

bool linearSearch(int arr[],int n, int ele){
    for(int i = 0; i < n; i++){
        if(arr[i] == ele)return true;
    }
    return false;
}

int main(){
    int arr[] = {4,5,6,1,2,8,7,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ele = 27;
    bool flag = linearSearch(arr, n, ele);

    flag == true ? cout << "true" : cout << "false" ;
    cout << endl;

    return 0;
}