#include<bits/stdc++.h>
using namespace std;
stack<int> stk;

/**
 * 
 *  ip  10 8  3 4  13 16
 *  op  13 13 4 13 16 -1
 * 
 * We need to start comparing from left to right and for that we need to start constructing stack from right to left
 * as stack is LIFO
 * 
 * 
 */

    vector<int> getNearestRight(vector<int>& input){

        for(auto &ele : input){
            cout<< ele << " ";
        }
        cout<< endl;
    }

int main(){

    int t;
    cin>> t;
    while(t--){
        int n;
        cin>> n;
        vector<int> inputVector;
        for(int i = 0; i < n; i++){
            int ele;
            cin>> ele;
            inputVector.push_back(ele);
        }
        getNearestRight(inputVector);
    }
}