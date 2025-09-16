#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bruteRotate(vector<vector<int>>& matrix, int n, int m){            //2 * O[n*m]   //O[n*m]
    vector<int> ans;                                                    
    for(int j = 0; j < m; j++){                      
        for(int i = n-1; i>=0; i--){
            int val = matrix[i][j];
            ans.push_back(val);
        }
    }
    
    int idx = 0;                                     
    for(int i = 0; i< n;i++){
        for(int j = 0; j< m; j++){
            matrix[i][j] = ans[idx];
            idx++;
        }
    }
}

void optimalRotate(vector<vector<int>>& matrix, int n, int m){
    for(int i = 0; i< n; i++){
        for(int j = i; j < m; j++){
            if(i == j)continue;
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for(int i = 0; i <n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }

}

int main(){
    vector<vector<int>>matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12},{13,14,15,16}};
    int n = matrix.size();    // no. of rows
    int m = matrix[0].size();    //no. of cols
    // bruteRotate(matrix, n, m);
    optimalRotate(matrix, n, m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}