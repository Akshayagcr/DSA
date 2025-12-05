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
        long long min_element;
    public:
        MinStack() {
        }
        
        void push(long long val) {
            if(stk.empty()){
                min_element = val;
                stk.push(val);
            }
            else if(val < min_element) {
                stk.push(2ll * val - min_element);
                min_element = val;
            }
            else {
                stk.push(val);
            }
        }
        
        void pop() {
            if(stk.top() < min_element){
                min_element = min_element * 2ll - stk.top();
            }
            stk.pop();
        }
        
        long long top() {
            if(stk.top() < min_element){
                return min_element;
            }
            return stk.top();
        }
        
        long long getMin() {
            return min_element;
        }
    };

