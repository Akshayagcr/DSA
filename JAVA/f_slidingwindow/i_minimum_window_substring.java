package f_slidingwindow;

import java.util.*;

/*
    https://leetcode.com/problems/minimum-window-substring/description/
*/
public class i_minimum_window_substring {
    
    public static String minWindow(String s, String t) {
        Map<Character, Integer> map = new HashMap<>();
        for(char c : t.toCharArray()){
            if(map.containsKey(c)){
                map.put(c, map.get(c) + 1);
            } else {
                map.put(c, 1);
            }
        }

        int low = 0, high = 0, resLow = -1, resHigh = -1, noZero = 0, minWindowLength = Integer.MAX_VALUE;
        char charAtHigh, charAtLow;

        while(high < s.length()) {

            // Do calculation / increase window
            charAtHigh = s.charAt(high);
            if(map.containsKey(charAtHigh)){
                if(map.get(charAtHigh) == 1){
                    noZero++;
                }
                map.put(charAtHigh, map.get(charAtHigh) - 1);
            }

            // While condition meet. Try reduce window size while keeping track of result.
            if(noZero == map.size()){
                while(noZero == map.size()){
                    if(minWindowLength > high - low + 1){
                        minWindowLength = high - low + 1;
                        resLow = low;
                        resHigh = high;
                    }

                    charAtLow = s.charAt(low);
                    if(map.containsKey(charAtLow)){
                        if(map.get(charAtLow) == 0){
                            noZero--;
                        }
                        map.put(charAtLow, map.get(charAtLow) + 1);
                    }
                    low++;
                }
            }
            high++; // Do calculation / increase window
        }

        if(resLow == -1){
            return "";
        }
        return s.substring(resLow, resHigh + 1);
    }

    public static void main(String[] args) {
        System.out.println(minWindow("ADOBECODEBANC", "ABC"));
    }

}
