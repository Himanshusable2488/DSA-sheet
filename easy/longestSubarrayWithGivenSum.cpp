// longest subarray with given sum k
#include <bits/stdc++.h>

using namespace std;

int count(vector<int>& arr, int t){
    int ans = 0;
    for(int i = 0; i< arr.size(); i++){
        for(int j = i; j<arr.size(); j++){
            int count = 0;
            for(int k = i; k<=j;k++){
                count += arr[k];
            }
            if(count == t)ans = max(ans, j-i+1);
        }
    }
return ans;
}

int optimal(vector<int>& array, int target){
    int left = 0; int right = 0;
    int maxLen = 0;
    int sum = array[0];
    while(right < array.size()){
        while(sum > target && left <= right){
            sum -= array[left];
            left++;
        }
        if(sum == target){
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        sum += array[right];
    }
return maxLen;
}

int main(){
    vector<int> arr = {2,3,5,1,1,9};
    int target = 10;
    // int ans = count(arr,target);
    int ans = optimal(arr,target);
    cout << ans << endl;
    return 0;
}

