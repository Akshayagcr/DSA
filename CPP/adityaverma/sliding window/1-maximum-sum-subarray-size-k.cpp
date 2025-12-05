#include<bits/stdc++.h>
using namespace std;

/**
 * https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
 */
class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        int i = 0, j = 0, maxSum = INT_MIN, currentWindowSum = 0;
        while(j < arr.size()){
            currentWindowSum = currentWindowSum + arr[j];
            if(j - i + 1 < k){
                j++;
            } else {
                maxSum = max(maxSum, currentWindowSum);
                currentWindowSum = currentWindowSum - arr[i];
                i++; j++;
            }
        }
        return maxSum;
    }
};