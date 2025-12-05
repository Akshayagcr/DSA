#include<bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/coin-change/description/
 * 
 * Improvement made : 
 * 1: Final return statement : added check if INT_MAX then return -1
 * 2: Added overflow check before adding 1 to INT_MAX
 * 3: Initialize with INT_MAX rather than zero. As it correctly represents Unrechable states
 *  Refer : coin_change_dp_INT_MAX_vs_minus1.md
 * 
 */
class Solution {
    public:

        vector<vector<int>> t;

        int coinChange(vector<int>& coins, int amount) {
            int n = coins.size();
            t.assign(n + 1, vector<int>(amount + 1, INT_MAX));
            return coinChangeTabulation(coins, n, amount);
        }

        int coinChangeTabulation(vector<int>& coins, int n, int amount){
            /*
                Base case 
                1: n == 0 and amount == 0 return 0
                2: n == 0 and amount > 0 return INT_MAX
                3: n > 0 and amount == 0 return 0
            */
           for(int i = 1; i <= n; i++){
            t[i][0] = 0;
           }
 
           for(int i = 1; i <= n; i++){
            for(int j = 1; j <= amount; j++){
                if(coins[i - 1] <= j && t[i][j - coins[i - 1]] != INT_MAX){
                    int include = 1 + t[i][j - coins[i - 1]];
                    int exclude = t[i - 1][j];
                    t[i][j] = min(include, exclude);
                } else{
                    t[i][j] = t[i - 1][j];
                }
            }
           }
           return t[n][amount] == INT_MAX ? -1 : t[n][amount];
        }

};