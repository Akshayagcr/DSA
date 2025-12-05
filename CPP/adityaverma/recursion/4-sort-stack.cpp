#include<bits/stdc++.h>
using namespace std;

    void printStack(stack<int> stk){
        while(!stk.empty()){
            cout<< stk.top() << " ";
            stk.pop();
        }
    }

    void insertElementIntoSortedStack(stack<int>& stk, int ele){
        if(stk.empty() || stk.top() >= ele){
            stk.push(ele);
            return;
        }
        int tempEle = stk.top(); stk.pop();
        insertElementIntoSortedStack(stk, ele);
        stk.push(tempEle);
    }

    void sortStackUsingRecursion(stack<int>& stk){
        /*
            If we call sortStackUsingRecursion on n - 1 elements it returns us sorted stack
            with smallest element on top. now we need to insert nth element in the sorted stack
        */
       if(stk.size() == 1){
        return;
       }
       int topEle = stk.top(); stk.pop();
       sortStackUsingRecursion(stk);
       insertElementIntoSortedStack(stk, topEle);
    }

int main(){
    int n;
    cin>> n;
    stack<int> stk;
    int ele;
    for(int i = 0; i < n; i++){
        cin>> ele;
        stk.push(ele);
    }

    printStack(stk);
    sortStackUsingRecursion(stk);
    cout<< "\n" << "Sorted stack : " << "\n";
    printStack(stk);
}