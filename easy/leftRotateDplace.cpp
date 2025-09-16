#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotateLeft(vector<int>& arr, int d){
    d = d % arr.size();
    reverse(arr.begin(), arr.begin()+d);
    reverse(arr.begin()+d, arr.end());
    reverse(arr.begin(), arr.end());

    cout << "left rotated array:" << endl;
    for(auto it : arr){
        cout << it << " ";
    }
    cout << endl;
}

void rotateRight(vector<int>& arr1, int d){
    d = d % arr1.size();
    reverse(arr1.begin(), arr1.end()-d);
    reverse(arr1.end()-d, arr1.end());
    reverse(arr1.begin(), arr1.end());

    cout << "right rotated array:" << endl;
    for(auto it : arr1){
        cout << it << " ";
    }
}

int main(){
    vector<int> arr = {1, 3, 5, 6, 6, 7, 8};
    vector<int> arr1 = {1, 3, 5, 6, 6, 7, 8};
    int d = 7;
    rotateLeft(arr, d);
    rotateRight(arr1, d);
    return 0;
}