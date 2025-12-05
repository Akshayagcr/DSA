#include<bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/subsets-ii/
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

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        /*
        for [4,4,4,1,4] input unsorted array will create duplicate subsets like [1, 4], [4, 1] (Element order does not matter)
        so we sort the input, so that set can eliminate duplicates.        
        */
        sort(nums.begin(), nums.end());

        subsetRecursive(nums, vector<int>());
        set<vector<int>> s;
        for(auto v : res){
            s.insert(v);
        }
        res.clear();
        for(auto ele : s){
            res.push_back(ele);
        }
        return res;
    }
};