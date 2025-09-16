#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// we need to find the second largest element in the array
int main(){
    vector<int> arr = {2,4,67,47,2,1};

    int largest = 0;
    int sLargest = 0;
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] > arr[largest])largest = i;
        if(arr[i] > arr[sLargest] && arr[i] < arr[largest]){
            sLargest = i;
        }
    }
    cout << " largest is: "<<arr[largest] << endl;
    cout << "second largest is: "<<arr[sLargest];
    
    return 0;
}