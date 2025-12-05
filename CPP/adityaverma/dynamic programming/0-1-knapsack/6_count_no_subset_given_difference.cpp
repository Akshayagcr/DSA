#include<bits/stdc++.h>
using namespace std;

/**
 * https://www.geeksforgeeks.org/problems/partitions-with-given-difference/0
 * 
 * s1 - s2 = d
 * s1 + s2 = total
 * s2 = total - s1
 * 
 * s1 - total + s1 = d
 * 2s1 = d + total
 * 
 * s1 = (d + total) / 2
 * 
 */
class Solution {
    public:


    vector<vector<int>> t;

    /**
     * *** VIMP : below code works only for non zero input.
     * Read : Subset_Sum_DP_Zero_Handling_.md
     */
    int countPartitions(vector<int>& arr, int d) {
    int n = arr.size();
    int total = accumulate(arr.begin(), arr.end(), 0);
    int target = (d + total) / 2;

    t.assign(n + 1, vector<int>(target + 1, -1));
        return subsetCount(n, arr, target);
    }

    int subsetCount(int n, vector<int>& arr, int target){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= target; j++){
                if(j == 0){
                    t[i][j] = 1;
                } else if(i == 0){
                    t[i][j] =  0;
                }else if(arr[i - 1] <= j){
                    int include = t[i - 1][j - arr[i - 1]];
                    int exclude = t[i - 1][j];
                    t[i][j] =  include + exclude;
                } else{
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return t[n][target];
    }


    /**
     * Working solution for the problem
     */
    int countPartitions(vector<int>& arr, int d) {
            int n = arr.size();
            int total = accumulate(arr.begin(), arr.end(), 0);
        
            if (total < d || (total + d) % 2 != 0) return 0;
        
            int target = (total + d) / 2;
            t.assign(n + 1, vector<int>(target + 1, 0));
        
            // Correct base case
            t[0][0] = 1;
        
            // Full DP logic in a single nested loop
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= target; j++) {
                    if (arr[i - 1] <= j) {
                        t[i][j] = t[i - 1][j] + t[i - 1][j - arr[i - 1]];
                    } else {
                        t[i][j] = t[i - 1][j];
                    }
        
                    // Special fix: ensure t[i][0] is handled dynamically
                    if (j == 0 && arr[i - 1] == 0) {
                        t[i][j] = 2 * t[i - 1][j];  // double ways if we see a zero
                    }
                }
            }
        
            return t[n][target];
    
        }



  };