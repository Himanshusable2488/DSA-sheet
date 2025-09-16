#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//11 2 3 111 22 3 222 1111 2 33

int find(vector<int>& arr){
    int n = arr.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            int j = i;
            int count = 0;
            while(arr[j] == 1 && j < n){
                j++;
                count ++;
            }
            ans = max(count, ans);
        }
    }
    return ans;
}

int optimal(vector<int>& arr){
    int ans = 0;
    int count = 0;
    for(int i = 0; i < arr.size(); i++){
        
        if(arr[i] == 1){
            count++;
        }else{
            count = 0;
        }
        ans = max(ans,count);
    }
    return ans;
}
 
int main(){
    vector<int> arr = {1, 1, 0, 1, 1, 1};
    // int ans = find(arr);
    int ans = optimal(arr);
    cout << ans << endl;
    return 0;
}

