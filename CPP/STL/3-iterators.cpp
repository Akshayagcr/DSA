#include<bits/stdc++.h>
using namespace std;

int main(){
    /*
        We cannot use indexing in collection like map, set like we use in vector
        to access elements so there we use iterators.
    */
   vector<int> v = {1, 2, 3, 4};
   vector<int> ::iterator it = v.begin();// returns iterator pointing to 1
   cout<< *it << endl; // access element using *
   cout<< *(it + 1) << endl;
   v.end(); // returns iterator ponting to memory location next to last element i.e. memory location next to 4

    // **** we can iterate any container using iterators

    for(vector<int> ::iterator it2 = v.begin(); it2 != v.end(); it2++){
        cout<< *it2 << " ";
    }
    cout<< endl;

    /*
    **Note : it++ takes us to next iterator i.e. next element in all contaners
    but it = it + 1 takes us to next sequential location which is invalid for other unordered collections.
    */

   vector<pair<int, int>> v2 = {{1, 2}, {3, 4}, {5, 6}};
   vector<pair<int, int>> ::iterator it2;
   for(it2 = v2.begin(); it2 != v2.end(); it2++){
    cout<< (*it2).first << " " << (*it2).second << endl;
   }
   for(it2 = v2.begin(); it2 != v2.end(); it2++){
    cout<< it2 -> first << " " << it2 -> second << endl; // Different syntax to access pair element
   }
   
//    Range based loops : it works for all containers !! It directly gets the value from the container.

    for(pair<int, int> p: v2){ // values in p are copy of values in v2. so change in p will not be reflected.
        cout<< p.first << " " << p.second << endl;
    }

    for(pair<int, int> &p: v2){ // actual values are iterated.
        cout<< p.first << " " << p.second << endl;
    }

    // auto keyword. Automatically determines data type by looking at the assigned value

    auto a = 1.0;
    cout<< "a : " << a << endl;

    for(auto&p: v2){ // used auto keyword.  ********* Preferred
        cout<< p.first << " " << p.second << endl;
    }

    for(auto it3 = v2.begin(); it3 != v2.end(); it3++){ // auto for iterator
        cout<< it3 -> first << " " << it3 -> second << endl;
    }

}