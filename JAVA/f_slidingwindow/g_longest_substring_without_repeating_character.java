package f_slidingwindow;

import java.util.*;

/*
    https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/
public class g_longest_substring_without_repeating_character {
    
    public int lengthOfLongestSubstring(String s) {
        int longestSubstring = 0, low = 0, high = 0, windowSize;
        Map<Character, Integer> map = new HashMap<>();
        char charAtHigh, charAtLow;

        while(high < s.length()){

            // Expand window/Do calculation
            charAtHigh = s.charAt(high);
            if(map.containsKey(charAtHigh)){
                map.put(charAtHigh, map.get(charAtHigh) + 1);
            } else {
                map.put(charAtHigh, 1);
            }

            // Reduce window size by removing charAtLow(low)
            if(map.size() < high - low + 1){
                while(map.size() < high - low + 1){
                    charAtLow = s.charAt(low);
                    if(map.containsKey(charAtLow)){
                        if(map.get(charAtLow) == 1){
                            map.remove(charAtLow);
                        } else {
                            map.put(charAtLow, map.get(charAtLow) - 1);
                        }
                    }
                    low++;
                }
            }

            // When condition is met. Get answer from calculation
            windowSize = high - low + 1;
            if(map.size() == windowSize){
                longestSubstring = Math.max(longestSubstring, windowSize);
            }

            high++; // Expand window
        }

        return longestSubstring;
    }

}
