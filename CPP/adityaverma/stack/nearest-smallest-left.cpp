#include<bits/stdc++.h>
using namespace std;

    void printVector(const vector<int> &v){
        for(auto& ele: v){
            cout<< ele << " ";
        }
        cout<< "\n";
    }

    /**
     * ip : 10  8   3   4   13 16
     * op : -1 -1  -1   3   4  13
     * 
     * We need to search nearest smalles element in left sub array
     * therefor we start iterating from left.
     */
    void getNearestSmallestLeft(const vector<int> &ip){

        int n = ip.size();
        vector<int> op(n, -1);
        stack<int> stk;

        for(int i = 0; i < n; i++){

            int ele = ip[i];

            while(!stk.empty() && stk.top() > ele){
                stk.pop();
            }

            if(!stk.empty()){
                op[i] = stk.top();
            }

            stk.push(ele);
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
            cin>> ip[i];
        }
        getNearestSmallestLeft(ip);
    }
}