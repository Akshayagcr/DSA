#include<bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/generate-parentheses/
 */
class Solution {
    public:

    vector<string> res;

    void generate(int close, int open, string op){
        if(close == 0 && open == 0){
            res.push_back(op);
            return;
        }
        if(close == open){
            op.push_back('(');
            generate(close, open - 1, op);
            return;
        }
        if(close >= 1 && open == 0){
            op.push_back(')');
            generate(close - 1, open, op);
            return;
        }
        op.push_back('(');
        generate(close, open - 1, op);
        op.pop_back();
        op.push_back(')');
        generate(close - 1, open, op);
    }

    vector<string> generateParenthesis(int n) {
        generate(n, n, "");
        return res;
    }
};