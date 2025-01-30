#include<bits/stdc++.h>
using namespace std;

    void printVector(vector<int> &ip){
        for(auto &ele : ip){
            cout<< ele << " ";
        }
        cout<< "\n";
    }

    /**
     * 
     * ip  10  8  3  4  13 16
     * op  -1 10  8  8  -1 -1
     * 
     * We need to check for left subarray of givrn element x i.e. form 0 to x - 1
     * therefore will start iterating form left only 
     */
    void getNearestGreatestLeft(vector<int> &ip){
        if(ip.empty()){
            return;
        }
        vector<int> op;
        op.push_back(-1); // nearest greatest of the element at index 0 will be -1
        stack<int> stk;
        stk.push(ip[0]);
        for(int i = 1; i < ip.size(); i++){
            // if stk.top > current then op == stk.top
            // if stk.top < current pop until 
            //      1: stack is empty the op == -1 
            //      2: stk.top > current
            int ele = ip[i];
            if(stk.empty()){
                op.push_back(-1);
            }
            else if(stk.top() > ele){
                op.push_back(stk.top());
            }
            else{
                while (stk.top() <= ele && !stk.empty()){
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
        printVector(op);
    }

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> ip;
        int ele;
        for(int i = 0; i < n; i++){
            cin >> ele;
            ip.push_back(ele);
        }
        getNearestGreatestLeft(ip);
    }
}
