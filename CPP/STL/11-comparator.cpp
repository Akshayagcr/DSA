#include<bits/stdc++.h>
using namespace std;

/**
 * This comparator sorts pair in ascending order based on first
 * if two pairs have same first. then sort pairs in descending based on second
 */
bool customComparatorVector(pair<int, int>& p1, pair<int, int>& p2){
    if(p1.first == p2.first)
            return p1.second > p2.second;
        return p1.first < p2.first;
}

void sortVector(){
    vector<pair<int, int>> v = {{3, 1}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {1, 2}};
    sort(v.begin(), v.end(), customComparatorVector);
    cout<< "{";
    for(auto& p : v){
        cout<< "{" << p.first << ", " << p.second<< "} ";
    }
    cout<< "}" << "\n";
}

/**
 * This comparator sorts pair in ascending order based on first
 * if two pairs have same first. then sort pairs in descending based on second
 */
class CustomComparatorSet{
    public:
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const{
        if(p1.first == p2.first)
            return p1.second > p2.second;
        return p1.first < p2.first;
    }
};

void sortSet(){
    set<pair<int, int>, CustomComparatorSet> s = {{3, 1}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {1, 2}};
    cout<< "{";
    for(auto& p : s){
        cout<< "{" << p.first << ", " << p.second<< "} ";
    }
    cout<< "}" << "\n";
}

/**
 * This comparator sorts pair in ascending order based on first
 * if two pairs have same first. then sort pairs in descending based on second
 * 
 * To write comparator for priority queue we need to change reverse all comparison operators,
 * Inorder to achive same result as custom comparator for vector and set.
 * If we use same custom comparator of vector and set for priority queue then will get ans in reverse. 
 * As it first arranges element same as CustomComparator but starts poping element from reverse. 
 */
class CustomComparatorHeap{
    public:
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const{
        if(p1.first == p2.first)
            return p1.second < p2.second;
        return p1.first > p2.first;
    }
};

void sortPriorityQueue(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, CustomComparatorHeap> h;
    h.push({3, 1});
    h.push({2, 1});
    h.push({2, 2});
    h.push({2, 3});
    h.push({2, 4});
    h.push({1, 2});
    cout<< "{";
    while(!h.empty()){
        auto p = h.top();
        cout<< "{" << p.first << ", " << p.second<< "} ";
        h.pop();
    }
    cout<< "}" << "\n";
}

/**
 * This comparator sorts keys in descending order. 
 * 
 * For map we can only apply custom sorting for keys only. 
 * As value are associated with key, we cannot apply sorting on key as well as value. 
 * Sorting for values is not supported. Custom comparator for map works only for keys. 
 */
class CustomComparatorMap{
    public:
    bool operator()(const int& a, const int& b) const{
        return a > b;
    }
};

void sortMap(){
    map<int, int, CustomComparatorMap> m = {{1, 1}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {3, 2}};
    cout<< "{";
    for(auto& p : m){
        cout<< "{" << p.first << ", " << p.second<< "} ";
    }
    cout<< "}" << "\n";
}

/**
 *  ip : [{3, 1}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {1, 2}]
 *  expected : [{1, 2}, {2, 4}, {2, 3}, {2, 2}, {2, 1}, {3, 1}]
 */
int main(){
    sortVector();
    sortSet();
    sortPriorityQueue();
    sortMap();
}
