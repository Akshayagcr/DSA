#include<bits/stdc++.h>
using namespace std;

    void printVector(const vector<int>& ip){
        for(int i = 0; i < ip.size(); i++){
            cout << ip[i] << " ";
        }
        cout << "\n";
    }

    vector<int> getNearestGreatestLeftIndex(const vector<int>& ip){
        int n = ip.size();
        vector<int> op(n, -1);
        stack<pair<int, int>> stk; // pair.first == value, pair.second == index
        // As we need to find nearest greatest in left sub array we start iterating from left.
       for(int i = 0; i < n; i++){

            int ele = ip[i];

            while(!stk.empty() && stk.top().first <= ele){
                stk.pop();
            }

            if(!stk.empty()){
                op[i] = stk.top().second;
            }

            stk.push({ip[i], i});
       }
       return op;
    }

    /**
     * Ip : [100, 80, 60, 70, 60, 75, 85]
     * Op : [1, 1, 1, 2, 1, 4, 6]
     */
    void getStockSpan(const vector<int>& ip){
        vector<int> nglIndex = getNearestGreatestLeftIndex(ip);
        int n = ip.size();
        vector<int> op(n);
        for(int i = 0; i < n; i++){
            op[i] = i - nglIndex[i];
        }
        printVector(op);
    }


int main(){
    int T, n;
    cin>> T;
    while(T--){
        cin>> n;
        vector<int> ip(n);
        for(int i = 0; i < n; i++){
            cin >> ip[i];
        }
        getStockSpan(ip);
    }

}