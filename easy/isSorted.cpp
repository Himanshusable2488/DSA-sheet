//need to check this also
// how to check a descending order sorted array

#include <iostream>
#include <vector>
using namespace std;

bool isSorted(vector<int>& arr){

    int asc = true;
    int desc = true;
    for(int i = 1; i<arr.size(); i++){
        if(arr[i] < arr[i-1])asc = false;
        if(arr[i] > arr[i-1])desc = false;
    }
    return asc || desc;
}

int main(){
    vector<int> arr = {1,2,8,4,6,7};
    bool ans = isSorted(arr);
    cout << ans << endl;
    return 0;
}