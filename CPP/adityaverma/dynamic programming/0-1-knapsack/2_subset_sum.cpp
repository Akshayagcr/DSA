#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> t;

/**
 * https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
 */
bool isSubsetSumRecursive(int n, vector<int>& arr, int target) {
    // base condition
    if(target == 0){
        return true;
    }
    if(n == 0){
        return false;
    }
    // Choice diagram
    if(arr[n - 1] <= target){
        // We have two choices to include element or not
        bool weTakeEle = isSubsetSumRecursive(n - 1, arr, target - arr[n - 1]);
        bool weDontTakeEle = isSubsetSumRecursive(n - 1, arr, target);
        return weTakeEle || weDontTakeEle;
    }
    return isSubsetSumRecursive(n - 1, arr, target);
}

bool isSubsetSumMemoized(int n, vector<int>& arr, int target) {
    if(target == 0){
        return true;
    }
    if(n == 0){
        return false;
    }
    if(t[n][target] != -1){
        return t[n][target];
    }
    // Choice diagram
    if(arr[n - 1] <= target){
        // We have two choices to include element or not
        bool weTakeEle = isSubsetSumMemoized(n - 1, arr, target - arr[n - 1]);
        bool weDontTakeEle = isSubsetSumMemoized(n - 1, arr, target);
        return t[n][target] = weTakeEle || weDontTakeEle;
    }
    return t[n][target] = isSubsetSumMemoized(n - 1, arr, target);
}

bool isSubsetSumBottomUp(int n, vector<int>& arr, int target) {
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= target; j++){
            if(j == 0){
                t[i][j] = true;
            }else if(i == 0){
                t[i][j] = false;
            } else if(arr[i - 1] <= j){
                bool weTakeEle = t[i - 1][j - arr[i - 1]];
                bool weDontTakeEle = t[i - 1][j];
                t[i][j] = weTakeEle || weDontTakeEle;
            } else{
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][target];
}

bool isSubsetSum(vector<int>& arr, int target) {
    int n = arr.size();
    t.assign(n + 1, vector<int>(target + 1, -1));
    return isSubsetSumBottomUp(n, arr, target);
}