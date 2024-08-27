#include<bits/stdc++.h>
using namespace std;

int main(){

    // ***** Pairs *****

    pair<int, string> p1;
    p1 = {1, "akshay"};
    cout<< p1.first << " " << p1.second << endl;

    pair<int, string> p2 = p1; // It is copied by value
    p1.first = 2;
    cout<< p2.first << " " << p2.second << endl;

// p2{1, akshay}
    pair<int, string> &p3 = p2; // It is copied by reference
    p2.first = 3;
    cout<< p3.first << " " << p3.second << endl;

    // pairs are used to store two elements that are related
    pair<int, int> pair_arr[3];
    pair_arr[0] ={1, 2};
    pair_arr[1] ={3, 4};
    pair_arr[2] ={5, 6};
    swap(pair_arr[0], pair_arr[2]); // Inbuilt swap
    for(int i = 0; i < 3; i++){
        cout<< pair_arr[i].first << " " << pair_arr[i].second << endl;
    }

//  IO
    cin >> pair_arr[0].first >> pair_arr[0].second;
    cout<< pair_arr[0].first << " " << pair_arr[0].second;

}