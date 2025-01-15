#include<bits/stdc++.h>
using namespace std;

int main(){

    /*
    For all the algorithms generally two parameters will always be passed 
    1. starting point of vector or array
    2. one location greater than the end location till we want to apply the algorithm
    */

    vector<int> v = {1, 2, 3, 4, 5};

    int min = *min_element(v.begin(), v.end());
    cout << "min : " << min << endl;

    int max = *max_element(v.begin(), v.end());
    cout << "max : " << max << endl;

    int sum = accumulate(v.begin(), v.end(), 0);
    cout << "sum : " << sum << endl;

    auto it = find(v.begin(), v.end(), 21);
    if(it != v.end())
        cout << "element found !!" << endl;
    else
        cout << "element not found" << endl;

    // reverse can be used in arrays, vectors and string it reverses the same array, string and vector it does not creates a copy.
    string s = "akshay";
    reverse(s.begin(), s.end());
    cout << "reversed string : " << s << endl;

    /*
    In case of arrays start address = name of array = vector.begin()
    end address + 1 = name of array + no of elements = vector.end()
    int a[10];
    start address = a, location next to end address = a + 10; 
    */

    // lambda function : [](int x){return x + 2;}
    cout << "lambda fun : " << [](int x){return x + 2;}(2) << endl;
    // *** in sort function also we can directly pass lambda for thr comparator

    vector<int> v1 = {2, 4, 6};

    cout<< "all_of : " << all_of(v1.begin(), v1.end(), [](int x){return x < 10;}) << endl;
    cout<< "any_of : " << any_of(v1.begin(), v1.end(), [](int x){return x < 10;}) << endl;
    cout<< "none_of : " << none_of(v1.begin(), v1.end(), [](int x){return x < 10;}) << endl;



}