#include<bits/stdc++.h>
using namespace std;

    void printStack(stack<int> stk){
        while(!stk.empty()){
            cout<< stk.top() << " ";
            stk.pop();
        }
        cout<< "\n";
    }

    void deleteMiddleElementRecursive(stack<int>& stk, int position){
        if(stk.size() == position){
            stk.pop();
            return;
        }
        int temp = stk.top(); stk.pop();
        deleteMiddleElementRecursive(stk, position);
        stk.push(temp);
    }

    void deleteMiddleElement(stack<int>& stk){
        if(stk.size() <= 1){
            return;
        }
        deleteMiddleElementRecursive(stk, (stk.size() / 2) + 1);
    }

int main(){
    stack<int> stk;
    int n;
    cin>> n;
    int ele;
    while(n--){
        cin>> ele;
        stk.push(ele);
    }

    printStack(stk);
    deleteMiddleElement(stk);
    cout<< "Stack after deletion \n";
    printStack(stk);
}
