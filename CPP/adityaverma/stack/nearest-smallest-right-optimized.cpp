#include<bits/stdc++.h>
using namespace std;

    void printVector(const vector<int>& v){
        for(auto& ele: v){
            cout<< ele << " ";
        }
        cout<< "\n";
    }

    /**
     * ip : 10  8   3   4   13 16
     * op : 8   3  -1  -1   -1 -1
     * 
     * For an element x we need to check its right subarray
     * therefore right subarray should be stored in stack and for that we start iterating from right to left
     */
    void getNearestSmallestRight(const vector<int> &ip){

        int n = ip.size();
        vector<int> op(n, -1);
        stack<int> stk;

        for(int i = n - 1; i >= 0; i--){
            int ele = ip[i];

            while(!stk.empty() && stk.top() > ele){
                stk.pop();
            }
            
            /*
                above while loop ensures that stk.top will be the smaller than the current ele.
                if stk is empty already the vector is initialized with -1
            */
            if(!stk.empty()){
                op[i] = stk.top();
            }

            // push next element for processing
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
        getNearestSmallestRight(ip);
    }
}