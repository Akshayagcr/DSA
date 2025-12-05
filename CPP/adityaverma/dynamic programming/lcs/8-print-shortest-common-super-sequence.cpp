#include<bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/shortest-common-supersequence/
 * 
 * *** Learning content
 * why-loop-when-i-or-j-zero.md
 * refined-explanation-on-lcs-path-choice.md
 */
class Solution {
    public:

        vector<vector<int>> t;

        void lcsTabulation(const string& s1, const string& s2){
            for(int i = 1; i <= s1.size(); i++){
                for(int j = 1; j <= s2.size(); j++){
                    if(s1[i - 1] == s2[j - 1]){
                        t[i][j] = 1 + t[i - 1][j - 1];
                    } else {
                        t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                    }
                }
            }
        }

        string scss(const string& s1, const string& s2){
            string res = "";
            int i = s1.size();
            int j = s2.size();
            while(i > 0 && j > 0){
                if(s1[i - 1] == s2[j - 1]){
                    res.push_back(s1[i - 1]);
                    i--; j--;
                } else {
                    if(t[i - 1][j] > t[i][j - 1]){
                        res.push_back(s1[i - 1]);
                        i--;
                    } else {
                        res.push_back(s2[j - 1]);
                        j--;
                    }
                }
            }
            while(i > 0){
                res.push_back(s1[i - 1]);
                i--;
            }
            while(j > 0){
                res.push_back(s2[j - 1]);
                j--;
            }
            reverse(res.begin(), res.end());
            return res;
        }

        string shortestCommonSupersequence(string str1, string str2) {
            t.assign(str1.size() + 1, vector<int>(str2.size() + 1, 0));
            lcsTabulation(str1, str2);
            return scss(str1, str2);
        }
};