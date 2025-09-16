#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// time and space complexity for the problem statement NEXT_PERMUTATION
//   T.C - O[n],  S.C - O[1]
vector <int> nP(vector<int>& arr){
    int n = arr.size();
    int pivot = -1;
    
    // loop to find the pivot element from last 
    for(int i = n-2; i >= 0; i--){
        if(arr[i]<arr[i+1]){
            pivot = i;
            break;
        }
    }

    // it means the permutation is the last permutation
    if(pivot == -1){      
        reverse(arr.begin(), arr.end());
        cout << " if statement called" << endl;
        return arr;
    }
    
    //arranging the after pivot part by finding the smallest element that is larger than the pivot element and swaping them and sorting the after pivot subarray in ascending order
    for(int i = n-1; i > pivot ; i--){
        if(arr[pivot] < arr[i]){
            swap(arr[pivot], arr[i]);
            break;
        }
    }
    
    sort(arr.begin() + pivot + 1, arr.end());

    cout << "last return is called " << endl;

    //returning the original array with changes in itself
    return arr;

}

//main function - from where the function starts
int main(){
    vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
    vector<int> ans = nP(arr);
    for(auto it: ans){
        cout << it << " " ;
    }

    cout << endl;
    return 0;
}