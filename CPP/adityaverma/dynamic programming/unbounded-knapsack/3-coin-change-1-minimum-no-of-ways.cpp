#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

/**
 * https://leetcode.com/problems/coin-change-ii/description/
 * Improvement made
 * 1: t[i][0] should be 1 (Refer : DP_Table_Initialization)
 * 2: need to add include and exclude count i.e. include + exclude not max(include, exclude)
 * 3: Removed add +1 when include coins (Refer : DP_Plus_One_vs_Not)
 * 4: used unsigned long long as there was overflow issue event with long long
 */
class Solution {
    public:

        vector<vector<ull>> t;

        int change(int amount, vector<int>& coins) {
            int n = coins.size();
            t.assign(n + 1, vector<ull>(amount + 1, 0));
            return coinChange(coins, n, amount);
        }

        int coinChange(vector<int>& coins, int n, int amount){
            // ***** there is one way to get amount 0 is by choosing no coins i.e. 1 way
            for(int i = 0; i <= n; i++){
                t[i][0] = 1;
            }
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= amount; j++){
                    if(coins[i - 1] <= j){
                        ull include = t[i][j - coins[i - 1]];
                        ull exclude = t[i - 1][j];
                        t[i][j] = include +  exclude;
                    } else {
                        t[i][j] = t[i - 1][j];
                    }
                }
            }
            return t[n][amount];
        }

};