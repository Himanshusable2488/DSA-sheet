// sir two sum problem is very classic problem this problems prerequisites are an array mostly sorted (1 ,2,5,6,8). and an integer target that we needs to find t = 10 if the target is present means the sum of any two element makes the sum equal to target that means target is present .

// the first approach that comes is collect all the pairs in the array and when we get a pair that is equal to target we will return either indexes or if the function is boolean we will return the true, and if the loop gets completed and no such pair we found that sum to the target then we will return either -1, -1 or false.

// int n = arr.size();
// for(int i = 0; i< n; i++){
//     for(j = i+1; j< n;j++){
//         if(arr[i] + arr[j] == k){
//             return true;
//         }
//     }
// }
// return false;

// time complexity here will be O[n2] as we are using nested loop one to iterate over the array elements and another one also to pair with the i index.

// space complexity will be O{1} as no extra space is used for calculating answer.

// we will use the concept of two pointers .

// two pointers says they will iterate over the array in o[n] and increment according to the specific condition suitable for the problem to solve.

// here we will use two pointers that is left and right , one will be at the beggining of the array and one will be at the last index of the array .
// we will run our loop until left < right.
// because when left becomes right they point to same element and we do not want any solution that has same index elements as an answer the indexes should be unique.

// the thought process is as follows .
// we will run a while loop inside while loop if the sum of left and right index element is equal to the target we will return true.
// if the sum is less than we need to increment the left index for greater values and if the sum becomes greater than the target we will decrement the right index.

// if return statement is not executed inside the while loop after termination of the loop we will return false as an indication that there is no pair such that their value after getting sum equals to target value

// int l = 0; int r = n-1;
// while(l<r){
//     if(arr[l] + arr[r] == t){
//         return true;
//     }else if(arr[l] + arr[r] > t){
//         r--;
//     }else{l++;}
// }
// return false;

//the time complexity after using the two pointer concept will be O[n] as we are solving the sol in one iteration only
//the space complexity is also constant as no extra space is used

// Variant 2 
// when the array is not sorted 
// the brute force will be o{n2}
// the better approach will be using hashing concept
// in hashing concept we will use a map and then check for every index element if there the complement or the another element is present in the map or not if present we will return the mp[i] and the i index as the pair 

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool twoSum(vector<int>& arr, int t){
    int n = arr.size();
    for(int i = 0; i< n; i++){
        for(int j = i+1; j< n;j++){
            if(arr[i] + arr[j] == t){
                return true;
        }
    }
}
return false;
}

string twoSum2(vector<int>& arr, int t){
    int n = arr.size();
    unordered_map<int, int> mpp;
    for(int i = 0; i< n; i++){
        int complement = t - arr[i];
        if(mpp.find(complement)!= mpp.end()){
            return "true";
        }
        mpp[arr[i]] = i;
    }
    return "false";
}

bool twoSum3(vector<int>& arr, int t){
    int n = arr.size();
    int l = 0; int r = n-1;
    while(l<r){
        if(arr[l] + arr[r] == t){
            return true;
        }else if(arr[l] + arr[r] > t){
             r--;
        }else{l++;}
}
return false;
}

int main(){
    vector<int> arr = {1, 2, 5, 6, 8};
    int target = 5;
    // bool ans = twoSum(arr, target); 
    string ans = twoSum2(arr, target); 
    // bool ans = twoSum3(arr, target);  
    // (ans==1)?cout << "True" : cout << "False";
    cout << ans << endl;
    return 0;
}
