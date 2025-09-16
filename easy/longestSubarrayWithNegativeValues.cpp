#include <iostream>
#include <vector>
#include <map>

using namespace std;

int subarraySum(vector<int>& arr,int k){
    int maxLen = 0;
    map<long long, int>mp;
    int sum =0;
    for(int i = 0; i < arr.size(); i++){
        sum+= arr[i];
        if(sum == k)maxLen = i + 1;
        int rem = sum - k;
        if(mp.find(rem) != mp.end()){
            int len = i - mp[rem];
            maxLen = max(len, maxLen);
        }
        if(mp.find(sum) == mp.end()){
            mp[sum] = i;
        }
    }
    return maxLen;
}

int main(){
    vector<int> arr = {1, 0, 0, 3};
    int k = 3;
    int ans = subarraySum(arr, k);
    cout << "maxLen is: " << ans << endl;
    return 0;
}