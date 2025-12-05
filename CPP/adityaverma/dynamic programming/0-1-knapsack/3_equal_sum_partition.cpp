#include<bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 */
class Solution {
    public:
        vector<vector<int>> t;
    
        bool canPartition(vector<int>& nums) {
            int sum = accumulate(nums.begin(), nums.end(), 0);
            if(sum % 2 == 0){
                int targetSum = sum / 2;
                t.assign(nums.size() + 1, vector<int>(targetSum + 1, -1));
                return subsetSum(nums.size(), nums, targetSum);
            }
            return false;
        }
    
        bool subsetSum(int n, vector<int>& arr, int target){
            if(target == 0){
                return true;
            }
            if(n == 0){
                return false;
            }
            if(t[n][target] != -1){
                return t[n][target];
            }
            if(arr[n - 1] <= target){
                bool takeCurrentEle = subsetSum(n - 1, arr, target - arr[n - 1]);
                bool dontTakeCurrentEle = subsetSum(n - 1, arr, target);
                return t[n][target] = takeCurrentEle || dontTakeCurrentEle;
            } 
            return t[n][target] = subsetSum(n - 1, arr, target);
        }
    
    };