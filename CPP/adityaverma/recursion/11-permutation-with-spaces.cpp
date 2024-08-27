#include<bits/stdc++.h>
using namespace std;

/**
 * https://www.geeksforgeeks.org/problems/permutation-with-spaces3627/1
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
        op = op + " " + c;
        permute(ip, op);
        op.pop_back(); op.pop_back();
        permute(ip, op + c);
    }

  
    vector<string> permutation(string s) {
        if(s.size() == 1){
            res.push_back(s);
            return res;
        }
        reverse(s.begin(), s.end());
        string op;
        op.push_back(s.back());
        s.pop_back();
        permute(s, op);
        return res;
    }
};