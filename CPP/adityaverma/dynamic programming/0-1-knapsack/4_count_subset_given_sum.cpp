#include<bits/stdc++.h>
using namespace std;

/**
 * https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/0
 */
class Solution {
    public:
    vector<vector<int>> t;

      int perfectSum(vector<int>& arr, int target) {
          int n = arr.size();
          t.assign(n + 1, vector<int>(target + 1, -1));
          return perfectSumMemoized(n, arr, target);
      }

      int perfectSumRecursive(int n, vector<int>& arr, int target){
        if (n == 0) return (target == 0) ? 1 : 0; // VIMP: see countSubsetReadme.md
        if(arr[n - 1] <= target){
            int takeCurrentEle = perfectSumRecursive(n - 1, arr, target - arr[n - 1]);
            int notTakeCurrentEle = perfectSumRecursive(n - 1, arr, target);
            return takeCurrentEle + notTakeCurrentEle;
        }
        return perfectSumRecursive(n - 1, arr, target);
      }


      /**
       * ****VIMP : see countSubsetReadme.md
       */
      int perfectSumMemoized(int n, vector<int>& arr, int target){
        if (n == 0) return (target == 0) ? 1 : 0;// VIMP: see countSubsetReadme.md
        if(t[n][target] != -1){
            return t[n][target];
        }
        if(arr[n - 1] <= target){
            int takeCurrentEle = perfectSumMemoized(n - 1, arr, target - arr[n - 1]);
            int notTakeCurrentEle = perfectSumMemoized(n - 1, arr, target);
            return t[n][target] = takeCurrentEle + notTakeCurrentEle;
        }
        return t[n][target] = perfectSumMemoized(n - 1, arr, target);
      }

  };