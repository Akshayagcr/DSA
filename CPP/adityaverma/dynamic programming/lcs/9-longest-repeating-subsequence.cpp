#include<bits/stdc++.h>
using namespace std;

/**
 * https://www.naukri.com/code360/problems/longest-repeating-subsequence_1118110
 */
int longestRepeatingSubsequence(string st, int n){
	vector<vector<int>> t(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(st[i - 1] == st[j - 1] && i != j){
                t[i][j] = 1 + t[i -1][j - 1];
            } else {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    return t[n][n];
}