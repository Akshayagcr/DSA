#include<bits/stdc++.h>
using namespace std;

    void printStack(stack<int> stk){
        while(!stk.empty()){
            cout << stk.top() << " ";
            stk.pop();
        }
        cout<< "\n";
    }

    void insertElementAtBottom(stack<int>& stk, int ele){
        if(stk.size() == 0){
            stk.push(ele);
            return;
        }
        int temp = stk.top(); stk.pop();
        insertElementAtBottom(stk, ele);
        stk.push(temp);
    }

    void reverseStack(stack<int>& stk){
        if(stk.size() == 1){
            return;
        }
        int ele = stk.top(); stk.pop();
        reverseStack(stk);
        insertElementAtBottom(stk, ele);
    }

int main(){
    int n;
    cin >> n;
    int ele;
    stack<int> stk;
    while(n--){
        cin>> ele;
        stk.push(ele);
    }
    printStack(stk);
    reverseStack(stk);
    cout<< "After reversing stack \n";
    printStack(stk);
}