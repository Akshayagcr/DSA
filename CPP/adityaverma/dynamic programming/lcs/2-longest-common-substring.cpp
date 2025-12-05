#include<bits/stdc++.h>
using namespace std;

/**
 * https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
 */
class Solution {
    public:
    vector<vector<int>> t;

    /**
     * *** Not able to figure out initially
     * Study and analyze it well
     */
    int lcsRecursive(const string& s1, const string& s2, int n, int m, int count){
        // Base case
        if(n == 0 || m == 0){
            return count;
        }
        int currentCount = count;
        // Choice diagram
        if(s1[n - 1] == s2[m - 1]){
            currentCount = lcsRecursive(s1, s2, n - 1, m - 1, count + 1);
        }

        int c1 = lcsRecursive(s1, s2, n, m - 1, 0);
        int c2 = lcsRecursive(s1, s2, n - 1, m - 1, 0);

        return max({currentCount, c1, c2});
    }

    /**
     * Tabulation is much more intituative rather than Recursive approach !!!
     */
    int lcsTabulation(const string& s1, const string& s2){
        int maxLen = INT_MIN;

        int n = s1.size();
        int m = s2.size();

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i - 1] == s2[j - 1]){
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else{
                    t[i][j] = 0;
                }
                maxLen = max(maxLen, t[i][j]);
            }
        }

        return maxLen;
    }

    int longestCommonSubstr(string& s1, string& s2) {
        // Recursive
        // return lcsRecursive(s1, s2, s1.size(), s2.size(), 0);

        // Tabulation
        t.assign(s1.size() + 1, vector<int>(s2.size() + 1, 0)); // Filling with zero, As if a string is empty then it substring size will be zero
        return lcsTabulation(s1, s2);
    }
};