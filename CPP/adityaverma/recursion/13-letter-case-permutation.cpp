#include<bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/letter-case-permutation/
 */
class Solution {
    public:

    vector<string> res;

    void permute(string ip, string op){
        if(ip.empty()){
            res.push_back(op);
            return;
        }
        char c = ip.back(); ip.pop_back();
        if(isdigit(c)){
            op.push_back(c);
            permute(ip, op);
            return;
        }
        op.push_back(toupper(c));
        permute(ip, op);
        op.pop_back();
        op.push_back(tolower(c));
        permute(ip, op);
    }

    vector<string> letterCasePermutation(string s) {
        reverse(s.begin(), s.end());
        permute(s, "");
        return res;
    }
    
};