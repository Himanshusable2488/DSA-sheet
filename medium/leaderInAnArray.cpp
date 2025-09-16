#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

vector<int> leaders(vector<int>& arr){
    vector<int> A ;

    int n = arr.size();
    for(int i = n-2; i >= 0; i--){
        int flag = 1;
        for(int j = i+1; j< n; j++){
            if(arr[j] > arr[i]){
                flag = 0;
                break;
            }
        }
        if(flag == 1)A.push_back(arr[i]);
    }
    A.push_back(arr[n-1]);
    sort(A.begin(), A.end(),std::greater<int>());

    return A;
}

vector<int> optimal(vector<int>& arr){
    int n = arr.size();
    vector<int> ans;
    int greater = INT_MIN;
    for(int i = n-1;i>= 0; i--){
        if(arr[i] > greater){
            greater = arr[i];
            ans.push_back(greater);
        }
    }

    sort(ans.begin(), ans.end(), std::greater<int>());
    return ans;
}

int main(){
    vector<int> arr = {10, 22, 12, 3, 0, 6};
    // vector<int>ans = leaders(arr);
    vector<int>ans = optimal(arr);
    for(auto it: ans){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}

