#include<bits/stdc++.h>
using namespace std;

/**
 * https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
 */
class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        vector<int> res;
        queue<int> q;
        int i = 0, j = 0;
        while(j < arr.size()){
          if(arr[j] < 0){
            q.push(arr[j]);
          }
          if(j - i + 1 < k){
            j++;
          } else {
            if(!q.empty()){
              res.push_back(q.front());
            } else {
              res.push_back(0);
            }
            if(!q.empty() && arr[i] == q.front()){
              q.pop();
            }
            i++; j++;
          }
        }
        return res;
    }
};