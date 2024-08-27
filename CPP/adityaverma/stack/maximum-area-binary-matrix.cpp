#include<bits/stdc++.h>
using namespace std;

    void printMatrix(const vector<vector<int>>& m){
        for(int i = 0; i < m.size(); i++){
            auto row = m[i];
            for(int j = 0; j < row.size(); j++){
                cout << row[j] << " ";
            }
            cout << "\n";
        }
    }

    vector<int> nearestSmallestRightIndex(const vector<int>& ip){
        int n = ip.size();
        vector<int> op(n, n);
        stack<pair<int, int>> stk; // first == value, second == index

        for(int i = n - 1; i >= 0; i--){
            int ele =  ip[i];

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

    vector<int> nearestSmallestLeftIndex(const vector<int>& ip){
        int n = ip.size();
        vector<int> op(n, -1);
        stack<pair<int, int>> stk;

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

    int maximumAreaHistogram(const vector<int>& ip){
        vector<int> nsri = nearestSmallestRightIndex(ip);
        vector<int> nsli = nearestSmallestLeftIndex(ip);

        int n = ip.size();

        vector<int> op(n);

        for(int i = 0; i < n; i++){
            op[i] = nsri[i] - nsli[i] - 1;
            op[i] = op[i] * ip[i];
        }
        return *max_element(op.begin(), op.end());
    }


    /*
            ip :
            4
            5
            1 0 1 0 0
            1 0 1 1 1
            1 1 1 1 1
            1 0 0 1 0
            
            op : 6
            
            https://leetcode.com/problems/maximal-rectangle/description/
    
    */
    void getMaximumAreaInBinaryMatrix(const vector<vector<int>>& m){

        int no_rows = m.size();
        int no_col = m[0].size();
        int maximum_area = INT_MIN;

        vector<int> temp(no_col, 0);

        for(int i = 0; i < no_rows; i++){
            auto row = m[i];
            for(int j = 0; j < no_col; j++){
                row[j] == 0 ? temp[j] = 0 : temp[j]++;
            }
            maximum_area = max(maximum_area, maximumAreaHistogram(temp));
        }
        cout<< maximum_area << "\n";
    }

    void solve(){
        int n, m, ele;
        cin >> n >> m;
        vector<vector<int>> ip;
        for(int i = 0; i < n; i++){
            vector<int> row;
            for(int j = 0; j < m; j++){
                cin >> ele;
                row.push_back(ele);
            }
            ip.push_back(row);
        }
        getMaximumAreaInBinaryMatrix(ip);
    }

int main(){
    int T;
    cin>> T;
    while(T--){
        solve();
    }
}