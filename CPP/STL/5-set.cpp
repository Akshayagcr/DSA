#include<bits/stdc++.h>
using namespace std;

void printSet(set<int> &s){
    cout<< "set size : " << s.size() << endl;
    for(auto &ele : s){
        cout << ele << " ";
    }
    cout<< endl;
}

void printUnorderedSet(unordered_set<int> &s){
    cout<< "unordered_set size : " << s.size() << endl;
    for(auto &ele : s){
        cout << ele << " ";
    }
    cout<< endl;
}

void printMultiset(multiset<int> &ms){
    cout<< "multisetsize : " << ms.size() << endl;
    for(auto &ele : ms){
        cout << ele << " ";
    }
    cout<< endl;
}

int main(){
    /*
        set : Internally it uses red black trees.
        time complexity of every operaion is O(log(n))
    */
    set<int> s = {1, 2, 3};
    s.insert(4); // O(log(n))
    s.insert(1);
    printSet(s);

    auto it = s.find(2); // O(log(n))
    if(it != s.end()){
        cout<< " found : " << *it << endl;
        s.erase(it); // It takes an iterator
        s.erase(4); // It takes an value O(log(n))
    }
    printSet(s);

    /*
        unordered_set : internally uses hashtable
        time complexity of all operation O(1)
        cannot use complex keys like pair possible but need to implement cutom hash method
    */
   unordered_set<int> us = {1, 1, 2};
   printUnorderedSet(us);

   /*
    multiset :instrnally uses red black trees. it allows duplicate
    time complexity of all operation is O(log(n))
   */
  multiset<int> ms = {10, 10, 2, 5, 1};
  printMultiset(ms);

  auto msit = ms.find(10); // return iterator pointing to first occurance
  if(msit != ms.end()){
    cout<< " found in multi set : " << *msit << endl;
    ms.erase(msit); // erases only the single instance which iterator points to.
  }
  printMultiset(ms);
  ms.insert(10);
  printMultiset(ms);
  ms.erase(10); // erases all instance of the value !!
  printMultiset(ms);

  ms.clear();
  printMultiset(ms);


}