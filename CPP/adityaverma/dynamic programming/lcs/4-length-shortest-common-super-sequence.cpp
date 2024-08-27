#include<bits/stdc++.h>
using namespace std;

/**
 * https://www.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
 */
class Solution {
    public:

      int lcsTabulation(const string& s1, const string& s2, int n, int m, vector<vector<int>>& t){
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

      int shortestCommonSupersequence(string &s1, string &s2) {
          vector<vector<int>> t(s1.size() + 1, vector<int>(s2.size() + 1, 0)); // Initialize with base case value of Zero
          return s1.size() + s2.size() - lcsTabulation(s1, s2, s1.size(), s2.size(), t);
      }
      
};