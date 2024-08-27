#include<bits/stdc++.h>
using namespace std;

    vector<vector<int>> t;

    string printLcs(const string& s1, const string& s2){
        
        t.assign(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        string res = "";

        int n = s1.size();
        int m =  s2.size();

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i - 1] == s2[j - 1]){
                    t[i][j] = 1 + t[i - 1][j - 1]; // moved diagonally
                    res.push_back(s1[i - 1]);
                } else{
                    t[i][j] = max(t[i][j - 1], t[i - 1][j]);
                }
            }
        }

        return res;
    }

int main(){
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin>> s1 >> s2;
        cout << printLcs(s1, s2) << "\n";
    }
}