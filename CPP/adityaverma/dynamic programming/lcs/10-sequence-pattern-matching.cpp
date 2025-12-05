#include<bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/is-subsequence/
 * 
 * *** This is not recommended method. Preferred way to solve this problem is using two pointers approach.
 */
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        if(n - dp[n][m] == 0){
            return true;
        }
        return false;
    }
};