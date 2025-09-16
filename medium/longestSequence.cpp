#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <unordered_set>


using namespace std;

bool linearSearch(vector<int>& arr, int num){
    for(int i = 0; i< arr.size(); i++){
        if(num == arr[i])return true;
    }
    return false;
}

int subSeq(vector<int>& arr){
    int n = arr.size();
    int ans = 1;
    for(int i = 0; i< n; i++){
        int x = arr[i];
        int cnt = 1;

        while(linearSearch(arr, x+1) == true){
            x += 1;
            cnt += 1;
        }

        ans = max(cnt, ans);
    }

    return ans;
}

int better(vector<int>& arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int smallNum = INT_MIN;
    int cnt = 0;
    int ans = 1;

    for(int i = 0; i < n; i++){
        if(arr[i]-1 == smallNum){
            cnt += 1;
            smallNum = arr[i];

        }else if(arr[i] != smallNum){
            cnt = 1;
            smallNum = arr[i];
        }

        ans = max(cnt, ans);
    }
    return ans;

}

int optimal(vector<int>& arr){
    unordered_set<int>st;
    int n = arr.size();
    
    int longest = 1;

    for(int i = 0; i <n; i++){
        st.emplace(arr[i]);
    }

    for(auto it: st){
        if(st.find(it-1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1)!= st.end()){
                x+= 1;
                cnt += 1;
            }
            longest =max(longest, cnt);
        }
    }
    return longest;
}
int main(){
    vector<int> arr = {100, 200, 1, 2, 3, 4};
    subSeq(arr);
    better(arr);
    int ans = optimal(arr);

    cout << " longest subsequence is: "<<  ans << endl;
    return 0;
}