#include<bits/stdc++.h>
using namespace std;

    void insertEleInSortedVector(vector<int>& ip, int ele){
        /*
            pop and store the last element until an element less than or equal to input element is not found
            once found push_back the input element and other element back
         */
        if(ip.size() == 0 || ip.back() <= ele){
            ip.push_back(ele);
            return;
        }
        int temp = ip.back();
        ip.pop_back();
        insertEleInSortedVector(ip, ele);
        ip.push_back(temp);
    }

    void sortUsingRecursion(vector<int>& ip){
        /*
            if we call sortUsingRecursion on n - 1 element it will sort it.
            Then we just need to insert the nth element in the sorted vector
        */
       if(ip.size() == 1){
        return;
       }
       int temp = ip.back();
       ip.pop_back();
       sortUsingRecursion(ip);
       insertEleInSortedVector(ip, temp);
    }

int main(){
    int n;
    cin>> n;
    vector<int> ip(n);
    for(int i = 0; i < n; i++){
        cin>> ip[i];
    }
    sortUsingRecursion(ip);
    for(int ele : ip){
        cout<< ele << " ";
    }
    cout << "\n";
}