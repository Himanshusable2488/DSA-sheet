#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// we need to find the largest element in the array
int main(){
    vector<int> arr = {2,4,67,47,2,1};
    int p = 0;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] > arr[p])p = i;
    }

    cout << arr[p] << endl;
    return 0;
}