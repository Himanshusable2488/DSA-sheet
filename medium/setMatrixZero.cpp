#include <bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>>& mat, int n){
    int m = mat[0].size();
    for(int i = 0; i< m; i++){
        if(mat[n][i] != 0){
            mat[n][i] = -1;
        }
    }
}

void markCol(vector<vector<int>>& mat, int m){
    int n = mat.size();
    for(int i = 0; i<n; i++){
        if(mat[i][m] != 0){
            mat[i][m] = -1;
        }
    }
}

void setMatrix(vector<vector<int>>& mat){
    int n = mat.size();   //row
    int m = mat[0].size();  //col

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(mat[i][j] == 0){
                markRow(mat,i);
                markCol(mat,j);
            }
        }
    }

    for(int i = 0; i< n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == -1)mat[i][j] = 0;
        }
    }
}

void betterMatrix(vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<int> row(n,0);
    vector<int> col(m,0);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
                
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(row[i] == 1 || col[j] == 1){
                mat[i][j] = 0;
            }
        }
    }
}

void optimal(vector<vector<int>>& mat){
    //row -> mat[0][]
    //col -> mat[][0]  
    int col0 = 1;
    int n = mat.size();
    int m = mat[0].size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 0){
                mat[i][0] = 0;
                if(j!=0){
                    mat[0][j] = 0;
                }else{
                    col0 = 0;
                }
            }
        }
    }

    for(int i = 1; i <n;i++){
        for(int j = 1; j<m; j++){
            if(mat[i][0] == 0 || mat[0][j]==0){
                mat[i][j] = 0;
            }
        }
    }

    if(mat[0][0] == 0){
        for(int j = 0; j < m; j++){
            mat[0][j] = 0;
        }
    }

    if(col0 == 0){
        for(int i = 0; i < n; i++){
            mat[i][0] = 0;
        }
    }
}

int main(){
    vector<vector<int>>matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    // setMatrix(matrix);
    // betterMatrix(matrix);
    optimal(matrix);
    for(auto it: matrix){
        for(auto i : it){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}