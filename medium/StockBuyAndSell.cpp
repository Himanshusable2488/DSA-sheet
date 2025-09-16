#include <iostream>

using namespace std;

int Profit(int arr[], int n){
    int minBuy = arr[0];
    int maxProfit = 0;
    for(int i = 1; i < n; i++){
        minBuy = min(minBuy, arr[i]);
        maxProfit = max(maxProfit, arr[i] - minBuy);
    }
    return maxProfit;
}

int main(){
    int arr[] = {7,1,5,3,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);

    int ans = Profit(arr, n);
    cout << ans << endl;
    return 0;
}