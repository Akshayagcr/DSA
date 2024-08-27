#include<bits/stdc++.h>
using namespace std;

    void printVector(const vector<int>& ip){
        for(auto& ele : ip){
            cout<< ele << " ";
        }
        cout<< "\n";
    }

    vector<int> getNearestSmallestRightIndex(const vector<int>& ip){
        int n = ip.size();
        vector<int> op(n, n);
        stack<pair<int, int>> stk; // first == value. second == index
        for(int i = n - 1; i >= 0; i--){

            int ele = ip[i];

            while(!stk.empty() && stk.top().first >= ele){
                stk.pop();
            }

            if(!stk.empty()){
                op[i] = stk.top().second;
            }

            stk.push({ele, i});
        }
        return op;
    }

    vector<int> getNearestSmallestLeftIndex(const vector<int>& ip){
        int n = ip.size();
        vector<int> op(n, -1);
        stack<pair<int, int>> stk; // first == value, second == index
        for(int i = 0; i < n; i++){
            int ele = ip[i];
            while(!stk.empty() && stk.top().first >= ele){
                stk.pop();
            }
            if(!stk.empty()){
                op[i] = stk.top().second;
            }
            stk.push({ele, i});
        }
        return op;
    }

    /**
     * Input: heights = [2,1,5,6,2,3]
     * Output: 10
     * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
     * 
     *  for any given x height in height array we need to find the maximum width till which we can expand
     *  any given height can be expandedn till we find its nearest smallest to left and right index
     *  Then we need to find width for every height in height array
     *  width[i] = nsr[i] - nsl[i] - 1;
     *  area[i] = width[i] * height[i];
     *  max(area[i]);
     */
    void getMaximumAreaOfHistogram(const vector<int>& ip){
        vector<int> nsri = getNearestSmallestRightIndex(ip);
        vector<int> nsli = getNearestSmallestLeftIndex(ip);

        int n = ip.size();
        vector<int> op(n);

        for(int i = 0; i < n; i++){
            op[i] = nsri[i] - nsli[i] - 1; // calculate width
            op[i] = op[i] * ip[i]; // multiply width and height
        }

        auto max_ele = max_element(op.begin(), op.end());

        if(max_ele != op.end()){
            cout << *max_ele << "\n";
        }
    }

    void solve(){
        int n;
        cin>> n;
        vector<int> ip(n);
        for(int i = 0; i < n; i++){
            cin>> ip[i];
        }
        getMaximumAreaOfHistogram(ip);
    }

int main(){
    int T;
    cin>> T;
    while(T--){
        solve();
    }
}