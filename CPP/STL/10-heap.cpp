#include<bits/stdc++.h>
using namespace std;

typedef pair<int, string> pis;

    void printMinHeap(priority_queue<pis, vector<pis>, greater<pis>>& heap){
        cout<< "Min heap size : " << heap.size() << "\n";
        while (!heap.empty()){
            pair<int, string> p = heap.top();
            cout<< p.first << " " << p.second << "\n";
            heap.pop();
        }
    }

    void printMaxHeap(priority_queue<pis>& heap){
        cout<< "Max heap size : " << heap.size() << "\n";
        while (!heap.empty()){
            pair<int, string> p = heap.top();
            cout<< p.first << " " << p.second << "\n";
            heap.pop();
        }
    }

/**
 * priority_queue<int> == max heap
 * priority_queue<int, vector<int>, greater<int>> == min heap
 * we can store pair inside heap, if pair contains string it will be compared based on
 * lexicographical order.
 */
int main(){
    priority_queue<pis> max_heap;

    max_heap.push({10, "andreea"});
    max_heap.push({10, "gautam"});
    max_heap.push({10, "zakir"});
    max_heap.push({25, "marty"});
    
    printMaxHeap(max_heap);

    priority_queue<pis, vector<pis>, greater<pis>> min_heap;

    min_heap.push({10, "andreea"});
    min_heap.push({10, "gautam"});
    min_heap.push({10, "zakir"});
    min_heap.push({25, "marty"});
    
    printMinHeap(min_heap);


}
