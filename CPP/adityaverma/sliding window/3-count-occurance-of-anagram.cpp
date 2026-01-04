#include<bits/stdc++.h>
using namespace std;

/**
 * https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
 */
class Solution {
  public:
    int search(string &pat, string &txt) {

        unordered_map<char, int> map;
        int count = 0, low = 0, high = 0, zeroCount = 0;

        for(int i = 0; i < pat.length(); i++){
          if(map.find(pat[i]) != map.end()){
            map[pat[i]] = map[pat[i]] + 1;
          } else {
            map[pat[i]] = 1;
          }
        }

        while(high < txt.length()){
            if(map.find(txt[high]) != map.end()) {
                if(map[txt[high]] == 1) {
                    zeroCount++;
                }
                map[txt[high]] = map[txt[high]] - 1;
            }
            if(high - low + 1 < pat.length()) {
                high++;
            } else {
                if(zeroCount == map.size()) {
                    count++;
                }
                if(map.find(txt[low]) != map.end()) {
                    if(map[txt[low]] == 0){
                        zeroCount--;
                    }
                    map[txt[low]] = map[txt[low]] + 1;
                }
                low++; high++;
            }
        }


        return count;
    }
};