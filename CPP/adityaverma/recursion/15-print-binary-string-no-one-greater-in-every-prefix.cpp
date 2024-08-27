#include<bits/stdc++.h>
using namespace std;

/**
 * https://www.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1
 */
class Solution{
    public:	

    vector<string> res;

    void generate(int zeros, int ones, int remainingSum, string op){
        if(remainingSum == 0){
            res.push_back(op);
            return;
        }
        if(zeros == ones){
            op.push_back('1');
            generate(zeros, ones + 1, remainingSum - 1, op);
            return;
        }
        op.push_back('1');
        generate(zeros, ones + 1, remainingSum - 1, op);
        op.pop_back();
        op.push_back('0');
        generate(zeros + 1, ones, remainingSum - 1, op);
    }

    vector<string> NBitBinary(int n){
        generate(0, 0, n, "");
        return res;
    }
};