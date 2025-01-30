#include<bits/stdc++.h>
using namespace std;

    void printVector(vector<int>& v){
        for(auto &ele : v){
            cout << ele << " ";
        }
        cout << "\n";
    }

    /**
     * 
     *  ip  10 8  3 4  13 16
     *  op  13 13 4 13 16 -1
     * 
     *  for any given element x we need to find the nearest greatest in its right sub array (x + 1, n).
     *  therefore we need to keep its right sub array in a stack, Also as we need the nearest greater to right.
     *  We need to start scaning array(Stack) from left to right.
     *  therefore we start processing element from right to left and keep adding required element in stack which represent right sub array.
     */
    void getNearestRight(vector<int>& input){
        int n = input.size();
        stack<int> stk;
        vector<int> output;
        output.push_back(-1); // nearest greatest for the last element will always be -1
        stk.push(input[n - 1]);
        for(int i = input.size() - 2; i >= 0; i--){
            int ele = input[i];
            // stk.top > current element add stk.top in output vector
            // stk.top <= current element pop from stk while 1: stk.top > current elemet 2: stk is empty
            // if stk is empty add -1 in output
            if(stk.empty()){
                output.push_back(-1);
            }
            else if(stk.top() > ele){
                output.push_back(stk.top());
            }
            else{
                while(stk.top() < ele && !stk.empty()){
                    stk.pop();
                }
                if(stk.empty()){
                    output.push_back(-1);
                }
                else{
                    output.push_back(stk.top());
                }
            }

            stk.push(ele);
        }
        reverse(output.begin(), output.end());
        printVector(output);
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
            cin >> ele;
            inputVector.push_back(ele);
        }
        getNearestRight(inputVector);
    }
}
