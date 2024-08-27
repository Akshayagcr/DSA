#include<bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/longest-common-subsequence/
 */
class Solution {
    public:
        vector<vector<int>> memo;
        vector<vector<int>> t;

        int lcsRecursive(const string& s1, const string& s2, int n, int m){
            // Base case
            if(n == 0 || m == 0){
                return 0;
            }
            // choice diagram
            if(s1[n - 1] == s2[m - 1]){
                return 1 + lcsRecursive(s1, s2, n - 1, m - 1);
            }
            return max(lcsRecursive(s1, s2, n, m - 1), lcsRecursive(s1, s2, n - 1, m));
        }

        int lcsMemoized(const string& s1, const string& s2, int n, int m){
            // Base case
            if(n == 0 || m == 0){
                return 0;
            }
            // Check Memoization table 
            if(memo[n][m] != -1){
                return memo[n][m];
            }
            // choice diagram
            if(s1[n - 1] == s2[m - 1]){
                return memo[n][m] = 1 + lcsMemoized(s1, s2, n - 1, m - 1);
            }
            return memo[n][m] = max(lcsMemoized(s1, s2, n, m - 1), lcsMemoized(s1, s2, n - 1, m));
        }

        int lcsTabulation(const string& s1, const string& s2){

            int n = s1.size();
            int m = s2.size();

            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                    if(s1[i - 1] == s2[j - 1]){
                        t[i][j] = 1 + t[i - 1][j - 1];
                    } else{
                        t[i][j] = max(t[i][j - 1], t[i - 1][j]);
                    }
                }
            }

            return t[n][m];
        }


        int longestCommonSubsequence(string text1, string text2) {
            // Recursive
            // return lcsRecursive(text1, text2, text1.size(), text2.size());

            // Memoized
            // memo.assign(text1.size() + 1, vector<int>(text2.size() + 1, -1));
            // return lcsMemoized(text1, text2, text1.size(), text2.size());

            // Tabulation
            t.assign(text1.size() + 1, vector<int>(text2.size() + 1, 0)); // Fill tabulation table with base case value
            return lcsTabulation(text1, text2);
        }
};