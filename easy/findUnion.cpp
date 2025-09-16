#include <set>
#include <iostream>
#include <vector>

using namespace std;

vector<int> setApproach(vector<int>& arr1, vector<int>& arr2, int n, int m){
    set<int>st;
    vector<int>Union;
    for(int i =0; i< n; i++){
        st.emplace(arr1[i]);
    }
    for(int i =0; i< m; i++){
        st.emplace(arr2[i]);
    }
    for(auto it: st){
        Union.push_back(it);
    }
    return Union;
}

vector<int> optimalApproach(int arr1[], int arr2[], int n, int m){
    vector<int>Union;
    int p1 = 0;
    int p2 = 0;
    while(p1< n && p2 <m){
        if(arr1[p1] <= arr2[p2]){
            if(Union.size() == 0 || Union.back() != arr1[p1]){
            Union.push_back(arr1[p1]);
        }
        p1++;
        }else{
            if(Union.size()==0 || Union.back() != arr2[p2]){
                Union.push_back(arr2[p2]);
            }
            p2++;
        }
        
    }
    while(p1<n){
        if(Union.size() == 0 || Union.back() != arr1[p1]){
            Union.push_back(arr1[p1]);
            p1++;
        }
    }
    while(p2<m){
        if(Union.size() == 0 || Union.back() != arr2[p2]){
            Union.push_back(arr2[p2]);
            p2++;
        }
    }
    return Union;
}

int main(){
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12}; 
  vector < int > Union = optimalApproach(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is  " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}