#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

void rD(vector<int>& a){
    vector<int> temp;  //O{N} 
    temp.push_back(a[0]);
    for(int i = 1; i < a.size(); i++){             //O{2N}
        if(a[i] != a[i-1])temp.push_back(a[i]);
    }
    for(int i = 0; i < temp.size(); i++){
        a[i] = temp[i];
    }
    for(int i = 0; i < temp.size(); i++){
        cout << a[i] << endl;
    }
}

void optimal(vector<int>& a){
    int p = -1;
    for(int i = 1; i < a.size(); i++){
        if(a[i] == a[i-1])p = i;break;
    }

    for(int i = p+1; i<a.size(); i++){
        if(a[i]!=a[i-1]){
            a[p] = a[i];
            p++; 
        }
    }
}
int main(){
    vector<int> arr = {1,3,4,5,5,5,6,7,7,8};   // output- 1,3,4,5,6,7,8
    rD(arr);













    // unordered_set<int>st;

    // for(auto it: arr){
    //     st.emplace(it);
    // }

    // auto it = st.begin();
    // for(int i = 0; i< st.size(); i++){
    //     arr[i] = *it;
    //     it++;
    // }

    // for(int i = 0; i< st.size(); i++){
    //     cout << arr[i] << " " ;
    // }
    return 0;
}