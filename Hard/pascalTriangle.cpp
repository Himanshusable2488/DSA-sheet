#include <iostream>
#include <vector>

using namespace std;

//printing the specific element at the given col and row
int ncr(int n, int r){
    long long res = 1;
    for(int i = 0; i< r; i++){
        res *= n-i;
        res /= i+1;
    }
    return res;
}

//printing the row which is stated to print
vector<int> printRow(int n){
    vector<int>res;

    int ans = 1;
    res.push_back(ans);

    for(int i = 1; i < n; i++){
        ans *= n-i;
        ans /= i;
        res.push_back(ans);
    }
    return res;
}

//printing the pascal triangle till given row
vector<vector<int>> pascalTriangle(int n ){
    vector<vector<int>> ans;
    for(int i = 1; i <= n; i++){
        ans.push_back(printRow(i));
    }
    return ans;
}

int main(){
    int row = 5;
    int col = 3;

    int ans = ncr(row-1, col-1);    //6
    vector<int>ans2 = printRow(row); // 1 4 6 4 1
    vector<vector<int>> ans3 = pascalTriangle(row); //1 1 1 1 2 1 1 3 3 1 1 4 6 4 1
    for(auto it : ans3){
        for(auto i: it){
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}