#include <iostream>
#include <vector>
using namespace std;

int BruteCountSubarray(vector<int>& arr,int k){
    int count = 0;
    int n = arr.size();
    for(int i = 0;i < n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum += arr[j];
            if(k == sum){
                count += 1;

            }
        }
    }
    return count;
}

int BetterCountSubarray(vector<int>& arr, int k){
    for(int i = 0; i < arr.size(); i++){
        
    }
}

int main(){
    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};
    int k = 3;
    // int ans = BruteCountSubarray(arr, k);
    int ans = BetterCountSubarray(arr, k);
    // int ans = BruteCountSubarray(arr, k);
    cout << ans << endl;
    return 0;
}