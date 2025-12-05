#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> &p1, pair<int, int> &p2){
    /*
        **Remember : Just return whatever you want.
        like we want p1.second should be greater than p2.second when p1.first is equal to p2.first
        and in other case p1.first should be greater than p2.first
    */
    if(p1.first == p2.first){
        return p1.second > p2.second;
    }
    return p1.first > p2.first;
}

int main(){
    /*
        Inbuild sort function uses intro sort which is mixture of quick sort,
        heap sort and insertion sort. It is the best sorting algorithm !!
        It is used to sort arrays and vectors.
        sort(start address, next address of the last element to be sorted)
    */

   int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
   sort(arr, arr + 9);
   for(auto &ele : arr){
    cout<< ele << " ";
   }
   cout<< endl;

   vector<int> v = {9, 8, 7, 6, 5, 4, 3, 2, 1};
   sort(v.begin(), v.end());
   for(auto &ele : v){
    cout<< ele << " ";
   }
   cout<< endl;

   /*
        Comparator : is a boolean function we can provide to sort
        to implement custom sorting behaviour
        *if you want to swap return true else false

        eg: sort an vector of pairs - In reverse of its default/natural order
   */

  vector<pair<int, int> > v1 = {{10, 11}, {5, 12}, {1, 10}, {1, 1}};
  sort(v1.begin(), v1.end(), comparator);
  for(auto &p : v1){
    cout<< p.first << " " << p.second << endl;
   }

// greater<int>(), greater<pair<int, int>>,... inbuilt comparator to sort in decreasing
   vector<int> v2 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
   sort(v2.begin(), v2.end(), greater<int>());
   for(auto &ele : v2){
    cout<< ele << " ";
   }
   cout<< endl;

   /*
        ***** Binary search *****
        lower_bound, upper_bound : can be used on a sorted array or vector
        It can also be used in map, sets
        lower_bound finds the given element or next greater elment.
        upper_bound will always find next greater element of the given element
        Both functions works in O(log(n))
   */

  int arr1[] = {1, 2, 3, 7, 10};
  sort(arr1, arr1 + 5);

  int *ptr;

  ptr = lower_bound(arr1, arr1 + 5, 3);
  cout<< *ptr << endl;

  ptr = lower_bound(arr1, arr1 + 5, 4);
  cout<< *ptr << endl;

  ptr = lower_bound(arr1, arr1 + 5, 11);
  if(ptr == arr1 + 5){
    cout<< "Not found" << endl;
  }

  ptr = upper_bound(arr1, arr1 + 5, 3);
  cout<< *ptr << endl;

  ptr = upper_bound(arr1, arr1 + 5, 11);
  if(ptr == arr1 + 5){
    cout<< "Not found" << endl;
  }

  /*
        for sets/maps we use s.lower_bound(val), s.upper_bound(val)
        It uses tree traversal internally for sets and map
        and binary search for arrays and vectors.
  */


}