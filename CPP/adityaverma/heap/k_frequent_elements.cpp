#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

    void printVector(const vector<int>& ip){
        for(auto& ele : ip){
            cout << ele << " ";
        }
        cout << "\n";
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(auto& ele : nums){
            map[ele]++;
        }
        priority_queue<pii, vector<pii>, greater<pii>> min_heap;
        for(auto& p : map){
            min_heap.push({p.second, p.first});
            if(min_heap.size() > k){
                min_heap.pop();
            }
        }
        vector<int> op;
        while(!min_heap.empty()){
            op.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return op;
    }

/**
 * https://leetcode.com/problems/top-k-frequent-elements/
 */
int main(){
    int t, k, n;
    cin>> t;
    while(t--){
        cin>> k >> n;
        vector<int> ip(n);
        for(int i = 0; i < n; i++){
            cin >> ip[i];
        }
        printVector(topKFrequent(ip, k));
    }
}