#include<bits/stdc++.h>
using namespace std;

void printMap(map<int, string> &m){
    cout<< m.size() << endl;
    for(auto &p : m){ 
        cout<< p.first << " " << p.second << endl;
    }
}

void printUnorderedMap(unordered_map<int, string> &m){
    cout<< m.size() << endl;
    for(auto &p : m){ 
        cout<< p.first << " " << p.second << endl;
    }
}

int main(){

    /*
        * map stores key value pair in sorted order. sorting is according to the key.
        It uses red black tree internally
        key should be unique.
        if we provide string as key they will be sorted according to lexicographical order
    */
    map<int, string> m;
    m[1] = "akshay"; // O(log(n)) insertion, accessing
    m[10] = "raj";
    m[100]; // if value not provided. the default value will be taken
    m.insert({2, "ankit"}); // Map stores elements a pairs
    printMap(m);

    auto it = m.find(13); // it returns an iterator. O(log(n))
    if(it == m.end()){
        cout<< "element not found" << endl;
    } else{
        cout << it->first << " " << it->second << endl;
    }


    if(it == m.end()){
        cout<< "element not found" << endl;
    } else{
        // O(log(n)) time complexity for erasing
        m.erase(it); // If element is not found. then iteratorpoints to end() and if try to erase end() we get error.
        m.erase(150); // erase also takes the value directly
    }

    m.clear(); // clear map
    
    printMap(m);
    // insertion time complexity also depends on key which we are using. if we use string as our key the time complexity will be O(log(n)) + Complexity of comparing key


/*
    unordered_map : internally uses hash table. keys are not sorted.
    insertion, accessing, erasing takes O(1)
    cannot use complex keys like pair possible but need to implement custom hash method
*/

unordered_map<int, string> um;
um[10] = "ajit";
um[1] = "rajashri";
um.insert({5, "sagar"});

printUnorderedMap(um);

/*
    multimap it stores elements in sorted order like map but it also allows duplicate key.
    **** It is not used in competative programming. 
    if there is a need to store multiple value we use map<int, vector<string> >
*/

multimap<int, string> mm = {{1, "akshay"}, {1, "rathod"}};
for(auto &p: mm){
    cout<< p.first << " " << p.second << endl;
}



}