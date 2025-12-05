#include<bits/stdc++.h>
using namespace std;

/**
 * https://www.geeksforgeeks.org/connect-n-ropes-minimum-cost/
 */
int minCost(vector<int>& arr) {
    priority_queue<int, vector<int>, greater<int>> min_heap;
    for(auto& ele: arr){
        min_heap.push(ele);
    }
    int minCost = 0;
    while(min_heap.size() > 1){
        int firstRope = min_heap.top();
        min_heap.pop();
        int secondRope = min_heap.top();
        min_heap.pop();
        int sum = firstRope + secondRope;
        minCost = minCost + sum;
        min_heap.push(sum);
    }
    return minCost;
}

int main(){
    
}