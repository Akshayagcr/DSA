#include<bits/stdc++.h>
using namespace std;

    void printVector(const vector<int>& ip){
        for(auto& ele : ip){
            cout << ele << " ";
        }
        cout << "\n";
    }

    /**
     * closest element is based on absolute difference from x.
     */
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> max_heap;
        for(auto& ele : arr){
            max_heap.push({abs(ele - x), ele});
            if(max_heap.size() > k){
                max_heap.pop();
            }
        }
        vector<int> op;
        while(!max_heap.empty()){
            op.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return op;
    }

int main(){
    int t, k, x, n;
    cin>> t;
    while(t--){
        cin>> k >> x >> n;
        vector<int> ip(n);
        for(int i = 0; i < n; i++){
            cin >> ip[i];
        }
        printVector(findClosestElements(ip, k, x));
    }
}