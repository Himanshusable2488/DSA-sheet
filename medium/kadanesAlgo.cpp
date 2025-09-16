#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int kadaneAlgo(vector<int>& arr){
    int ans = INT_MIN;
    int sum = 0;
    int start = 0;
    int sI = -1; 
    int lI = -1;
    
    for(int i = 0; i < arr.size();i++){

        if(sum == 0)start = i;
        sum+= arr[i];

        if(sum > ans){
            ans = sum;
           sI = start;
           lI = i;
        }

        if(sum < 0){
            sum = 0;
        }
        
    }

    for(int i = sI; i <= lI; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return ans;
}
int main(){
    vector<int> arr = {-2, -1,36,4,6,7,-16,-11};
    int ans = kadaneAlgo(arr);
    cout << ans << endl;
    return 0;
}