#include<bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/palindrome-partitioning-ii/
 * 
 * ***** This solution is correct but gives still gives TLE !!
 * Refer : palindrome_partitioning_explained.md
 */
class Solution {
    public:

        vector<vector<int>> dp;

        bool isPalindrome(const string& s, int i, int j){
            while(i < j){
                if(s[i] != s[j]){
                    return false;
                }
                i++; j--;
            }
            return true;
        }

        int solve(const string& s, int i, int j){
            if(dp[i][j] != -1){
                return dp[i][j];
            }
            if(isPalindrome(s, i , j)){
                return 0;
            }
            int minCost = INT_MAX;
            for(int k = i; k < j; k++){
                int firstHalf = (dp[i][k] != -1) ? dp[i][k] : (dp[i][k] = solve(s, i, k));
                int secondHalf = (dp[k + 1][j] != -1) ? dp[k + 1][j] : (dp[k + 1][j] = solve(s, k + 1, j));
                int currentCost = 1 + firstHalf + secondHalf;
                minCost = min(minCost, currentCost);
            }
            return dp[i][j] = minCost;
        }

        int minCut(string s) {
            dp.assign(s.size(), vector<int>(s.size(), -1));
            return solve(s, 0, s.size() - 1);
        }
};