#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

    void printVector(const vector<int>& ip){
        for(auto& ele : ip){
            cout << ele << " ";
        }
        cout << "\n";
    }

    /**
     * This method uses heap but we can also use a vector/set and custom comparator.
     * if problem requires to sort in descending when we have element with same frequency 
     * then this method cannot be used.
     */
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto& ele : nums){
            m[ele]++;
        }
        priority_queue<pii, vector<pii>, greater<pii>> min_heap;
        for(auto& p : m){
            min_heap.push({p.second, p.first});
        }
        vector<int> op;
        while(!min_heap.empty()){
            auto p = min_heap.top();
            for(int i = 0; i < p.first; i++){
                op.push_back(p.second);
            }
            min_heap.pop();
        }
        return op;
    }

    class CustomComparator{
        public:
        bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) const{
            if(p1.first == p2.first)
                return p1.second > p2.second;
            return p1.first < p2.first;
        }
    };

    /**
     * https://leetcode.com/problems/sort-array-by-increasing-frequency/
     */
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto& ele: nums){
            m[ele]++;
        }
        set<pair<int, int>, CustomComparator> s;
        for(auto& p : m){
            s.insert({p.second, p.first});
        }
        vector<int> op;
        for(auto& p : s){
            for(int i = 1; i <= p.first; i++){
                op.push_back(p.second);
            }
        }
        return op;
    }

int main(){
    int t, n;
    cin>> t;
    while(t--){
        cin>> n;
        vector<int> ip(n);
        for(int i = 0; i < n; i++){
            cin>> ip[i];
        }
        printVector(frequencySort(ip));
    }
}