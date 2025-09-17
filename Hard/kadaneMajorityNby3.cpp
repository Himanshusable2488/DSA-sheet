#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
#include <algorithm>

using namespace std;

vector<int> majorityElement(vector<int>& arr){
    //it is the solution for n/2 majority elements
    // int ele1 = INT_MIN; int ele2 = -1;
    // int freqCnt = 0;
    // for(int i = 0; i < arr.size(); i++){
    //     if(freqCnt == 0){
    //         ele1 = arr[i];
    //         freqCnt++;
    //     }
    //     else if(ele1 == arr[i]){
    //         freqCnt++;
    //     }
    //     else freqCnt--;
    // }
    
    //better approach using hashing technique for n/3 elements
    vector<int> ls;
    int n = arr.size();
    int minVal = (int)(n/3)+1;
    map<int,int>mp;
    for(int i = 0; i<n; i++){
        mp[arr[i]]++;
        if(mp[arr[i]] == minVal){
            ls.push_back(arr[i]);
        }
        if(ls.size() == minVal-1)break;
    }
    sort(ls.begin(),ls.end());
    return ls;
}

vector<int> OptimalmajorityElement(vector<int>& arr){

    
    int ele1 = INT_MIN;
    int ele2 = INT_MIN;
    int freqCnt1 = 0;
    int freqCnt2 = 0;
    for(int i = 0; i < arr.size(); i++){
        if(freqCnt1 == 0 && arr[i] != ele2){
            ele1 = arr[i];
            freqCnt1++;
        }
        else if(freqCnt2 == 0 && arr[i] != ele1){
            ele2 = arr[i];
            freqCnt2++;
        }
        else if(ele1 == arr[i]){
            freqCnt1++;
        }
        else if(ele2 == arr[i]){
            freqCnt2++;
        }
        else {
            freqCnt1--; 
            freqCnt2--;
        }
    }

    int minVal = (int)(arr.size()/3)+1;

    freqCnt1 = 0; freqCnt2 = 0;
    for(int i = 0; i< arr.size(); i++){
        if(ele1 == arr[i])freqCnt1++;
        if(ele2 == arr[i])freqCnt2++;
    }

    return {freqCnt1 == minVal?ele1:-1, freqCnt2 == minVal?ele2:-1};
}



int main(){
    vector<int> arr = {5,5,5,-6,-6,3,3,-6,-6};
    // vector<int>ans = majorityElement(arr);       
    vector<int>ans = OptimalmajorityElement(arr);       
    cout << ans[0] << " "<< ans[1] << endl;
    
    return 0;
}