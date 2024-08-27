#include<bits/stdc++.h>
using namespace std;

    void printVector(vector<int> &v){
        for(auto &ele : v){
            cout<< ele << " ";
        }
        cout << "\n";
    }

    /**
     * ip : 10  8   3   4   13 16
     * op : 8   3  -1  -1   -1 -1
     * 
     * For an element x we need to check its right subarray
     * therefore right subarray should be stored in stack and for that we start iterating from right to left
     * As we iterate from backward direction we need to reverse the output vector.
     */
    void getNearestSmallestRight(vector<int> &ip){

        stack<int> stk;
        vector<int> op;
        int n = ip.size();

        // Initial processing for last element
        op.push_back(-1);
        stk.push(ip[n - 1]);

        for(int i = n - 2; i >= 0; i--){
            int ele = ip[i];
            if(stk.empty()){
                op.push_back(-1);
            }
            else if(stk.top() < ele){
                op.push_back(stk.top());
            }
            else{
                while(!stk.empty() && stk.top() >= ele){
                    stk.pop();
                }
                if(stk.empty()){
                    op.push_back(-1);
                }
                else{
                    op.push_back(stk.top());
                }
            }
            stk.push(ele);
        }
        reverse(op.begin(), op.end());
        printVector(op);
    }

int main(){
    int T, n, ele;
    cin >> T;
    while(T--){
        cin >> n;
        vector<int> input;
        for(int i = 0; i < n; i++){
            cin>> ele;
            input.push_back(ele);
        }
        getNearestSmallestRight(input);
    }
}