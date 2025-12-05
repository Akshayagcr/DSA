#include<bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/k-th-symbol-in-grammar/
 */
class Solution {
    public:
    int kthGrammar(int n, int k) {
        if(n == 1){
            return 0;
        }
        if(k % 2 == 0){
            int res = kthGrammar(n - 1, k / 2);
            if(res == 0){
                return 1;
            }
            return 0;
        }
        return kthGrammar(n - 1, (k + 1) / 2);
    }
};