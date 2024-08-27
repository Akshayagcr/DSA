#include<bits/stdc++.h>
using namespace std;

/**
 * https://www.geeksforgeeks.org/problems/minimum-number-of-deletions4610/1
 */
class Solution {
  public:

  vector<vector<int>> t;

    int lcsTabulation(const string& s1, const string& s2, int n){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s1[i - 1] == s2[j - 1]){
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else{
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
        return t[n][n];
    }

    int minDeletions(string &s) {
        int n = s.size();
        t.assign(n + 1, vector<int>(n + 1, 0));
        string rev = s;
        reverse(rev.begin(), rev.end());
        return n - lcsTabulation(s, rev, n);
    }
};