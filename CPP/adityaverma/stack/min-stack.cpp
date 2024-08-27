#include<bits/stdc++.h>;
using namespace std;

/**
 * https://leetcode.com/problems/min-stack/description/
 * 
 *  ** Methods pop, top and getMin operations will always be called on non-empty stacks.
 */
class MinStack {
    private:
        stack<long long> stk;
        stack<long long> auxilaryStk;
    public:
        MinStack() {
        }
        
        void push(long long val) {
            if(auxilaryStk.empty()){
                auxilaryStk.push(val);
            } else if(auxilaryStk.top() >= val){
                auxilaryStk.push(val);
            }
            stk.push(val);
        }
        
        void pop() {
            if(stk.top() == auxilaryStk.top()){
                auxilaryStk.pop();
            }
            stk.pop();
        }
        
        long long top() {
            return stk.top();
        }
        
        long long getMin() {
            return auxilaryStk.top();
        }
    };

