package f_slidingwindow;

import java.util.*;

/*
    https://leetcode.com/problems/fruit-into-baskets/description/
*/
public class h_pick_a_toy {
    
    public static int totalFruit(int[] arr) {
        int longestSubarrayLength = 0, low = 0, high = 0;
        Map<Integer, Integer> map = new HashMap<>();

        while(high < arr.length){

            if(map.containsKey(arr[high])){
                map.put(arr[high], map.get(arr[high]) + 1);
            } else {
                map.put(arr[high], 1);
            }

            if(map.size() > 2){
                while(map.size() > 2){
                    if(map.containsKey(arr[low])){
                        if(map.get(arr[low]) == 1){
                            map.remove(arr[low]);
                        } else {
                            map.put(arr[low], map.get(arr[low]) - 1);
                        }
                    }
                    low++;
                }
            }

            if(map.size() == 1 || map.size() == 2){
                longestSubarrayLength = Math.max(longestSubarrayLength, high - low + 1);
            }

            high++;
        }
        return longestSubarrayLength;
    }

    public static void main(String[] args) {
        System.out.println(totalFruit(new int[]{0}));
    }
}
