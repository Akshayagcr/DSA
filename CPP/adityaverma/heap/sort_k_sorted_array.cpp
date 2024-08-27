#include<bits/stdc++.h>
using namespace std;

    void printVector(const vector<int>& ip){
        for(auto& ele : ip){
            cout << ele << " ";
        }
        cout << "\n";
    }

    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int j = 0;
        for(int i = 0; i < arr.size(); i++){
            min_heap.push(arr[i]);
            if(min_heap.size() > k){
                arr[j] = min_heap.top();
                j++;
                min_heap.pop();
            }
        }
        while(!min_heap.empty()){
            arr[j] = min_heap.top();
            j++;
            min_heap.pop();
        }
        printVector(arr);
    }

int main(){
    int t, k, n;
    cin>> t;
    while(t--){
        cin>> k;
        cin>> n;
        vector<int> ip(n);
        for(int i = 0; i < n; i++){
            cin>> ip[i];
        }
        nearlySorted(ip, k);
    }
}