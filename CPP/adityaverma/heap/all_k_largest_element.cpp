#include<bits/stdc++.h>
using namespace std;

    void printVector(const vector<int>& ip){
        for(auto& ele : ip){
            cout << ele << " ";
        }
        cout << "\n";
    }

    /**
     * k = 2
     * ip = 3 2 1 5 6 4
     * 
     * sorted ip  = 1 2 3 4 5 6
     * all k largest = {5, 6}
     */
    vector<int> getAllKLargestElements(const vector<int>& ip, int k){
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for(auto& ele: ip){
            min_heap.push(ele);
            if(min_heap.size() > k){
                min_heap.pop();
            }
        }
        vector<int> op;
        while(!min_heap.empty()){
            op.push_back(min_heap.top());
            min_heap.pop();
        }
        return op;
    }

int main(){
    int T, k, n;
    cin>> T;
    while(T--){
        cin>> k;
        cin>> n;
        vector<int> ip(n);
        for(int i  = 0; i < n; i++){
            cin >> ip[i];
        }
        printVector(getAllKLargestElements(ip, k));
    }
}