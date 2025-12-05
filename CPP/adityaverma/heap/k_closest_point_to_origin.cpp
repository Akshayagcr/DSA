#include<bits/stdc++.h>
using namespace std;

typedef pair<int, vector<int>> piv;

/**
 * https://leetcode.com/problems/k-closest-points-to-origin/
 * 
 * finding distance using manhatten distance i.e. x + y does not work
 * We need to use simplified euclidean formula x^2 + y^2
 * [[1,3],[-2,2],[2,-2]]
 *  manhattern distance of all above points is 4
 * where as euclidean distance is different for above points
 * 
 */
vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<piv> max_heap;
    for(auto& p : points){
        int d = (p[0] * p[0]) + (p[1] * p[1]);
        max_heap.push({d, p});
        if(max_heap.size() > k){
            max_heap.pop();
        }
    }
    vector<vector<int>> op;
    while(!max_heap.empty()){
        op.push_back(max_heap.top().second);
        max_heap.pop();
    }
    return op;
}

/**
 * This pronblem involves finding closest point to origin 
 * i.e. point with shortest distance from origin. 
 * Therefore we need to eliminate point with largest distance therefore we use max heap
 */
int main(){

}