#include<bits/stdc++.h>
using namespace std;

    /**
     * k = 2
     * ip = 3 2 1 5 6 4
     * 
     * sorted ip  = 1 2 3 4 5 6
     * kth smallest = 2
     */
    int findKthSmallest(vector<int>& nums, int k) {
        priority_queue<int> max_heap;
        for(auto& ele: nums){
            max_heap.push(ele);
            if(max_heap.size() > k){
                max_heap.pop();
            }
        }
        return max_heap.top();
    }

    /**
     * k = 2
     * ip = 3 2 1 5 6 4
     * 
     * sorted ip  = 1 2 3 4 5 6
     * kth largest = 5
     * Time complexity = n(log(k))
     * n as we are iterating over n elements
     * and log(K) as insertion in heap takes log(size of heap) which is log(k)
     * space complexity = O(k) as we are only constructing heap of size k 
     */
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for(auto& ele : nums){
            min_heap.push(ele);
            if(min_heap.size() > k){
                min_heap.pop();
            }
        }
        return min_heap.top();
    }

    /**
     * k = 2
     * ip = 3 2 1 5 6 4
     * 
     * sorted ip  = 1 2 3 4 5 6
     * kth largest = 5
     * This method is not efficient as its
     * Time complexity is n(log(n)) 
     * n as we are iterating n elements
     * log(n) as inserting element in heap takes log(size of heap) i.e. log(n)
     * and space complexity is O(n) as we are inserting all elements in heap
     */
    int findKthLargestV1(vector<int>& nums, int k) {
        priority_queue<int> max_heap;
        for(auto& ele : nums){
            max_heap.push(ele);
        }
        for(int i = 0; i < k - 1; i++){
            max_heap.pop();
        }
        return max_heap.top();
    }

    /**
     * ***** most optimized approach for solving this problem is to use quick select algorithm
     * which is based on quick sort. 
     */
int main(){

    int T, k, n;
    cin>> T;
    while(T--){
        cin>> k;
        cin>> n;
        vector<int> ip(n);
        for(int i = 0; i < n; i++){
            cin>> ip[i]; 
        }
        cout << findKthSmallest(ip, k);
    }
    
}