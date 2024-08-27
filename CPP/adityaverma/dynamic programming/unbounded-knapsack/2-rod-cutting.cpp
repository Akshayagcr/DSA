#include<bits/stdc++.h>
using namespace std;

/**
 * https://www.geeksforgeeks.org/problems/rod-cutting0840/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
 */
class Solution {

    vector<vector<int>> t;

    public:

      int cutRod(vector<int> &price) {
        int n = price.size();
        t.assign(n + 1, vector<int>(n + 1, 0));
        vector<int> length(n);
        for(int i = 0; i < n; i++){
          length[i] = i + 1;
        }
        return cutRodTabulation(price, length, n, n);
      }

      int cutRodTabulation(vector<int> &price, vector<int> &length, int n, int target){
        for(int i = 1; i <= n; i++){
          for(int j = 1; j <= target; j++){
            if(length[i - 1] <= j){
              int include = price[i - 1] + t[i][j - length[i - 1]];
              int exclude = t[i - 1][j];
              t[i][j] = max(include, exclude);
            } else{
              t[i][j] = t[i - 1][j];
            }
          }
        }
        return t[n][target];
      }

  };