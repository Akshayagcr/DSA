#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> &v){
    // ** By default vectors are passed by value to pass by reference add "&" to avoid making copy.
    for(int i = 0; i < v.size(); i++){
        cout<< v[i] << " ";
    }
    cout<< endl;
}

void nestedVectors(){

    vector<pair<int, int>> v = {{1, 2}, {3, 4}};
    cout<< "Printing vector<pair<int, int>> :" << v[0].first << " " << v[0].second << endl;

    vector<int> v1[10]; // Array of vector ** size we can take from input like vector<int> v[n] : where n is take as input.
    // We can access array of vector similar to 2D array : v1[row][column]
    
    vector<vector<int> > v2; // vector of vector
    // We can access vector of vector similar to 2D array : v1[row][column]
    // v2.push_back(vector<int> ()) : to add an vector.
}

int main(){
    /*
        ***** vectors *****

        vectors are also contineous memory block simlar to arrays. but vectors are dynamic
        similar to array we can store 10^5 elements in vectors that are declared locally and 10^7 elements when declared globally.
        v.push_back(), v.size(), v.pop_back() -> O(1)
    */

   vector<int> v;
   int no_elements;
   cin >> no_elements;
   for(int i = 0; i < no_elements; i++){
    int ele;
    cin >> ele;
    v.push_back(ele);
   }

   printVector(v);

   vector<int> v1(5); // We can specify size
   printVector(v1);

    vector<int> v2(5, 10); // We can specify size and initial value to be filled in all vectors elements.
    printVector(v2);

    vector<int> v3 = {1, 2, 3, 4}; // directly initialize
    printVector(v3);

    v3.pop_back(); // pop last element
    printVector(v3);

    vector<int> v4 = {10};
    vector<int> v5 = v4; // Creates a deep copy. changes in v4 are not reflected in v5 vice versa. O(n) time complexity
    // vector<int> &v5 = v4; // Creates a shallow copy. changes in v4 are reflected in v5 vice vers.
    v4.push_back(3);
    printVector(v4);
    printVector(v5);


    nestedVectors();
}



