#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findOne(vector<int>& arr){
    unordered_map<int, int>mp;
    for(int i = 0; i< arr.size(); i++){
        mp[arr[i]]++;
    }
    for(auto it: mp){
        if(it.second == 1)return it.first;
    }
}

int optimal(vector<int>& arr){
    int xorr = 0;
    for(int i = 0; i< arr.size(); i++){
        xorr = xorr ^ arr[i];
    }
    return xorr;
}

int main(){
    vector<int> arr = {1,2,1,2,3};
    // int ans = findOne(arr);
    int ans = optimal(arr);

    cout << ans << endl;
}