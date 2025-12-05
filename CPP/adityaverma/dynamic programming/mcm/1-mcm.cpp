#include<bits/stdc++.h>
using namespace std;

/**
 * https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
 */
class Solution {

    public:
    vector<vector<int>> memo;

      int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        memo.assign(n, vector<int>(n, -1));
        return mcmMemoized(arr, 1, n - 1);
      }


      int mcmRecursive(vector<int> &arr, int start, int end){
        if(start == end)
            return 0;
        int minCost = INT_MAX;
        for(int k = start; k < end; k++){
            int firstPart = mcmRecursive(arr, start, k);
            int secondPart = mcmRecursive(arr, k + 1, end);
            int cost = firstPart + secondPart + (arr[start - 1] * arr[k] * arr[end]);
            minCost = min(minCost, cost);
        }
        return minCost;
      }

      int mcmMemoized(vector<int> &arr, int start, int end){
        if(start == end){
            return 0;
        }
        if(memo[start][end] != -1){
            return memo[start][end];
        }
        int minCost = INT_MAX;
        for(int k = start; k < end; k++){
            int firstPart = mcmMemoized(arr, start, k);
            int secondPart = mcmMemoized(arr, k + 1, end);
            int cost = firstPart + secondPart + (arr[start - 1] * arr[k] * arr[end]);
            minCost = min(minCost, cost);
        }
        return memo[start][end] = minCost;
      }

  };