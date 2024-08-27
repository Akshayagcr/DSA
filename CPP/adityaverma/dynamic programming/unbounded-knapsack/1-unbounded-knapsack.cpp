#include<bits/stdc++.h>
using namespace std;

/**
 * https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
 */
class Solution {
    public:

        vector<vector<int>> memo;
        vector<vector<int>> t;

        int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
            int n = val.size();
            memo.assign(n + 1, vector<int>(capacity + 1, -1)); // Initialize memoization table with -1
            t.assign(n + 1, vector<int>(capacity + 1, 0)); // Initialize table with base case value 0;
            return knapSackTabulation(val, wt, n, capacity);
        }

        int knapsackRecursive(vector<int>& val, vector<int>& wt, int n, int capacity){
            if(n == 0 || capacity == 0){
                return 0;
            }
            if(wt[n - 1] <= capacity){
                int include = val[n - 1] + knapsackRecursive(val, wt, n, capacity - wt[n - 1]); // * here we can include n number of same items
                int exclude = knapsackRecursive(val, wt, n - 1, capacity);
                return max(include, exclude);
            }
            return knapsackRecursive(val, wt, n - 1, capacity);
        }

        int knapSackMemozised(vector<int>& val, vector<int>& wt, int n, int capacity){
            if(n == 0 || capacity == 0){
                return 0;
            }
            if(memo[n][capacity] != -1){
                return memo[n][capacity];
            }
            if(wt[n - 1] <= capacity){
                int include = val[n - 1] + knapSackMemozised(val, wt, n, capacity - wt[n - 1]); // * here we can include n number of same items
                int exclude = knapSackMemozised(val, wt, n - 1, capacity);
                return memo[n][capacity] = max(include, exclude);
            }
            return memo[n][capacity] = knapSackMemozised(val, wt, n - 1, capacity);
        }

        int knapSackTabulation(vector<int>& val, vector<int>& wt, int n, int capacity){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= capacity; j++){
                    if(wt[i - 1] <= j){
                        int include = val[i - 1] + t[i][j - wt[i - 1]];
                        int exclude = t[i - 1][j];
                        t[i][j] = max(include, exclude);
                    }
                    else{
                        t[i][j] = t[i - 1][j];
                    }
                }
            }
            return t[n][capacity];
        }

  };