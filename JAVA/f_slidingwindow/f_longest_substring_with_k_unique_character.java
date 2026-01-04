package f_slidingwindow;

import java.util.*;

/*
    https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
*/
public class f_longest_substring_with_k_unique_character {
    
    public static int longestKSubstr(String s, int k) {
        int longestSubstringLen = -1, low = 0, high = 0;
        Map<Character, Integer> map = new HashMap<>();
        char charAtHigh, charAtLow;

        while(high < s.length()){

            charAtHigh = s.charAt(high);
            if(map.containsKey(charAtHigh)){
                map.put(charAtHigh, map.get(charAtHigh) + 1);
            } else {
                map.put(charAtHigh, 1);
            }

            if(map.size() < k){
                high++;
            } else if(map.size() == k){
                longestSubstringLen = Math.max(longestSubstringLen, high - low + 1);
                high++;
            } else {
                while(map.size() > k){
                    charAtLow = s.charAt(low);
                    if(map.get(charAtLow) == 1){
                        map.remove(charAtLow);
                    } else {
                        map.put(charAtLow, map.get(charAtLow) - 1);
                    }
                    low++;
                }
                if(map.size() == k){
                    longestSubstringLen = Math.max(longestSubstringLen, high - low + 1);
            } 
                high++;
            }
        }

        return longestSubstringLen;
    }


    public static void main(String[] args) {
        System.out.println(longestKSubstr("aabacbebebe", 3));
    }

}
