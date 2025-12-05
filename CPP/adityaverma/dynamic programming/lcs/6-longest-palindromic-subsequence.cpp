#include<bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/longest-palindromic-subsequence/
 */
class Solution {
    public:

        int lcsTabulation(const string& s1, const string& s2, int n, vector<vector<int>>& t){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(s1[i - 1] == s2[j - 1]){
                        t[i][j] = 1 + t[i - 1][j - 1];
                    } else{
                        t[i][j] = max(t[i][j - 1], t[i - 1][j]);
                    }
                }
            }
            return t[n][n];
        }

        int longestPalindromeSubseq(string s) {
            vector<vector<int>> t(s.size() + 1, vector<int>(s.size() + 1, 0));
            string rev = s;
            reverse(rev.begin(), rev.end());
            return lcsTabulation(s, rev, s.size(), t);
        }
};