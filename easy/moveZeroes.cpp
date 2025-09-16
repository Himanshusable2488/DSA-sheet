#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& a){
    vector<int> temp;       //O{N}
    int n = a.size();
    for(int i = 0; i< n; i++){            //O{N}
        if(a[i] != 0)temp.push_back(a[i]);
    }

    int t = temp.size();
    for(int i = 0; i< t; i++){       //O{T}
       a[i] =  temp[i];
    }

    for(int i = t; i < n; i++){     //O{N-T}
        a[i] = 0;
    }
}

void optimal(vector<int>& a){

    int i = 0;
    int p = -1;
    int n = a.size();

    while(a[i]!= 0 && i < n)i++;

    if(i >= n)return ;

    p = i;

    for( i = p+1; i < n; i++){
        if(a[i] != 0){
            swap(a[p], a[i]);
            p++;
        }
    }
}

void print(vector<int>& arr){
    for(auto it : arr){
        cout << it << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr = {1, 4, 0, 3, 4, 0, 0, 5, 6, 0, 7};

    // moveZeroes(arr);
    optimal(arr);
    print(arr);
    return 0;
}