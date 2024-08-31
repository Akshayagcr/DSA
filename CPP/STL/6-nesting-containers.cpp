#include<bits/stdc++.h>
using namespace std;

int main(){
    /*
        We can compare pair, set, vectors directly using <, >, == operators
        comparison is done by comparing first element of both container then comparing second element
        so this containers can be used as key in map, set as they sort element according to key
    */

   pair<int, int> p1, p2, p3, p4;
   p1 = {1, 2};
   p2 = {2, 4};
   cout<< "p1 < p2 : " << (p1 < p2) << endl;
   p3 = {1, 2};
   p4 = {1, 4};
   cout<< "p3 < p4 : " << (p3 < p4) << endl;

   set<pair<int, int> > s = {{10, 2}, {1, 3}, {1, 1}, {5, 3}};
   for(auto &ele : s){
    cout<< ele.first << " " << ele.second << endl;
   }



}