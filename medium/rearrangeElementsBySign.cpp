#include <iostream>
#include <vector>
using namespace std;

//rearrange function works when no. of positive and negative elements are not equal and optimal function works when the elements are same in quantity

void reArrange(vector<int>& arr){
    vector<int> pos;
    vector<int> neg;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > 0)pos.push_back(arr[i]);
        if(arr[i] < 0)neg.push_back(arr[i]);
    }

    if(neg.size() > pos.size()){
        for(int i = 0; i < pos.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = pos.size()*2;
        for(int i = pos.size(); i< neg.size(); i++){
            arr[index] = neg[i];
            index++;
        }
    }else{
        for(int i = 0; i < neg.size(); i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = neg.size()*2;
        for(int i = neg.size(); i< pos.size(); i++){
            arr[index] = pos[i];
            index++;
        }
    }
}

void optimal(vector<int>& arr){
    int n = arr.size();

    int posInd = 0;
    int negInd = 1;

    vector<int> a(n,0);

    for(int i = 0; i< n; i++){
        if(arr[i] > 0){
            a[posInd] = arr[i];
            posInd += 2;
        }else{
            a[negInd] = arr[i];
            negInd += 2;
        }
    }

    for(int i = 0; i< n; i++){
        arr[i] = a[i];
    }

}

int main(){
    vector<int>arr = {1,2,-3,-1,-2,3,-9,-4,-1};
    reArrange(arr);
    // optimal(arr);
    for(auto it: arr){
        cout << it << " ";
    }
    cout << endl;
    return 0;
}