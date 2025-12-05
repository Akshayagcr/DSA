#include<bits/stdc++.h>
using namespace std;

/**
 * https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1
 */
class Solution {

    public:
        vector<vector<int>> t;

        /**
         * *** VIMP : Read : dp_topdown_vs_bottomup_comparison.md
         */
        int minDifference(vector<int>& arr) {
            int n = arr.size();
            int sum = accumulate(arr.begin(), arr.end(), 0);
            int halfSum = sum / 2;
            t.assign(n + 1, vector<int>(halfSum + 1, -1));
            subsetBottomUp(n, arr, halfSum);
            for(int i = halfSum; i >= 0; i--){
                if(t[n][i] == 1){
                    return sum - 2 * i;
                }
            }
        }

        /**
         * *** VIMP : Read : dp_topdown_vs_bottomup_comparison.md
         */
        void subsetBottomUp(int n, vector<int>& arr, int target){
            for(int i = 0; i <= n;  i++){
                for(int j = 0; j <= target; j++){
                    if(j == 0){
                        t[i][j] = 1;
                    }else if(i == 0){
                        t[i][j] = 0;
                    } else if(arr[i - 1] <= j){
                        t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                    } else{
                        t[i][j] = t[i - 1][j];
                    }
                }
            }
        }


  };