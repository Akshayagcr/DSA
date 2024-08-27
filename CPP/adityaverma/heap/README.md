
Whenever question involves finding smallest or largest k element and where sorting is the most natural solution 
these questions can be solved efficiently using heap

When question involves finding
smallest use max heap
largest use min heap

Using heap we convert O(nlog(n)) sorting approach to nlog(k) where k is the size of the heap.
log(k) because for min/max heapify operation takes log(n) time where n is the size of the heap

we can use type def to give an alias to complex data type

#include<bits/stdc++.h>

using namespace std;
typedef pair<int, pair<int, int>> ppi;

priority_queue<int> == max heap
priority_queue<int, vector<int>, greater<int>> == min heap
priority_queue<ppi, vector<ppi>, greater<ppi>> == min heap

- Kth smallest
- All K largest elements
- Sort an k sorted array
    K sorted array means that any given element x is only misplaced from it original sorted bosition by x - k, x + k only
    we start iterating from left to right pushing element in heap of size k. when heap size increases beyond k we pop from heap 
    and add it to sorted list

- K closest element
    In this problem we use pair where pair.first is the key which is abs difference between an element x and the given number y.

* If we insert pair<int, int> in heap. Then the elements are naturally sorted according to pair.first and then according to pair.second


When we have pair directly we use pair.first and pair.second
but when we have a iterator pointing to a pair i.e. when we are looping using an iterator
in that cases we use
it-> first, it-> second

- K frequent elements in an array

    Whenever question involves frequency we have to use map (unordered_map<int, int>).
    once we the frequency using map we use that frequency as a key in the heap to find K frequent elements. 

- Frequency sort
    Use map(unordered_map) to find frequency of all element
    put all element of map in heap with key(pair.fiirst) as frequency
    pop all elements from heap in sorted order

- K closest point to origin
    In this question we will store the distance of a point from origin as key in the heap
    distance formula = root((x1 - x2)^2 + (y1 - y2)^2) as we need to find distance from origin
    the above formula becomes root(x1^2 + y1^2)
    we can also ignore the square root as it will not make difference in sorting
    so the key to be used reduces to x1^2 + y1^2

- Connect ropes to minimize cost
    In this problem we have to connect all givrn ropes in a single rope. There is a cost associated eith the connect  operation
    the cost is equal to length of the ropes we are connecting
    We get and optimal cost by always combining rope with minimum length
    Therefore we use a min heap
    first insert all ropes the pop two ropes add cost in total_cost variable and again inser the combined length of rope in heap
    continue until only one element is left in the heap which means we have combined all ropes in one

- Sum of elements between k1 smallest and k2 smallest element in an array
    We write a function to find kth smallest element in an array
    the use the above function to find k1 and k2
    the in a loop add all numbers between k1 and k2

