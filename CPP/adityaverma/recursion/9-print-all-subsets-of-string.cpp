#include<bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/subsets/description/
 */
class Solution {
    public:

    vector<vector<int>> res;

    void subsetRecursive(vector<int> ip, vector<int> op){
        if(ip.empty()){
            res.push_back(op);
            return;
        }
        int ele = ip.back(); ip.pop_back();
        op.push_back(ele);
        subsetRecursive(ip, op);
        op.pop_back();
        subsetRecursive(ip, op);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // reverse(nums.begin(), nums.end()); Order does not matter in subsets.
        subsetRecursive(nums, vector<int>());
        return res;
    }
};