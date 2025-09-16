#include <iostream>
#include <vector>
#include <map>
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

int OptimalCountSubarray(vector<int>& arr, int k){
    map<int, int>mp;
    mp[0] = 1;
    int preSum = 0; int cnt = 0;
    for(int i = 0; i < arr.size(); i++){
        preSum += arr[i];
        int remove = preSum - k;
        cnt += mp[remove];
        mp[preSum] += 1;
    }
    return cnt;
}

int main(){
    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};
    int k = 3;
    // int ans = BruteCountSubarray(arr, k);
    int ans = OptimalCountSubarray(arr, k);
    cout << ans << endl;
    return 0;
}