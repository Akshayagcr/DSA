#include<bits/stdc++.h>
using namespace std;

/**
 * https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
 * 
 * capacity = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] max_profit = 3
 * 
 * capacity = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 6, 3] max_profit = 50
 * 
 */
int knapSackRecursive(int n, int capacity, vector<int> &val, vector<int> &wt) {
    if(n == 0 || capacity == 0){
        return 0;
    }
    int lastEleWt = wt[n - 1];
    int lastEleVal = val[n - 1];
    if(lastEleWt <= capacity){
        int lastEleTaken = lastEleVal + knapSackRecursive(n - 1, capacity - lastEleWt, val, wt);
        int lastEleNotTaken = knapSackRecursive(n - 1, capacity, val, wt);
        return max(lastEleTaken, lastEleNotTaken);
    }
    return knapSackRecursive(n - 1, capacity, val, wt);
}

int knapSackMemoized(int n, int capacity, vector<int> &val, vector<int> &wt) {
    if(n == 0 || capacity == 0){
        return 0;
    }
    if(t[n][capacity] != -1){
        return t[n][capacity];
    }
    int lastEleWt = wt[n - 1];
    int lastEleVal = val[n - 1];
    if(lastEleWt <= capacity){
        int lastEleTaken = lastEleVal + knapSackMemoized(n - 1, capacity - lastEleWt, val, wt);
        int lastEleNotTaken = knapSackMemoized(n - 1, capacity, val, wt);
        return t[n][capacity] = max(lastEleTaken, lastEleNotTaken);
    }
    return t[n][capacity] = knapSackMemoized(n - 1, capacity, val, wt);
}

/**
 * Element are indexed from 1 to n in DP table but are indexed from 0 to n - 1 in val & val array
 */
int knapSackTopDown(int n, int capacity, vector<int> &val, vector<int> &wt) {
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= capacity; j++){
            if(i == 0 || j == 0){
                t[i][j] = 0;
            } else if(wt[i - 1] <= j){
                int currentEleTaken = val[i - 1] + t[i - 1][j - wt[i - 1]];
                int currentEleNotTaken = t[i - 1][j];
                t[i][j] = max(currentEleTaken, currentEleNotTaken);
            } else{
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][capacity];
}


vector<vector<int>> t; // t[no elements][capacity]

int knapSack(int capacity, vector<int> &val, vector<int> &wt){
    int n = val.size();
    t.assign(n + 1, vector<int>(capacity + 1, -1));
    return knapSackTopDown(n, capacity, val, wt);
}