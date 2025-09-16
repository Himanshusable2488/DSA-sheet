#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int majEle(vector<int>& arr){
    int n = arr.size();
    unordered_map<int, int>mpp;
    for(int i =0; i< n; i++){
        mpp[arr[i]]++;
    }
    for(auto it: mpp){
        if(it.second > n/2)return it.first;
    }
}

int majEle2(vector<int>& arr){
    int n = arr.size();
    int freqEle = arr[0];
    int freqCount = 1;
    for(int i = 1; i < n; i++){
        if(freqCount == 0){
            freqCount = 1;
            freqEle = arr[i];
        }else if(freqEle == arr[i])freqCount++;
        else freqCount--;
    }
    freqCount = 0;
    for(int i = 0; i< n; i++){
        if(arr[i]==freqEle)freqCount++;
    }

    if(freqCount > n/2)return freqEle;
    else return -1;
}
int main(){
    vector<int> arr = {3,3,1,3,2,3,2,2,3,3};
    // int ans = majEle(arr);
    int ans = majEle2(arr);
    cout << ans;
    return 0;
}