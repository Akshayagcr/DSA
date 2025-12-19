package e_twopointers;

import java.util.HashMap;
import java.util.Map;

public class f_two_sum {

    /*
        Two sum in sorted array
        https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
    */
    public int[] twoSum(int[] arr, int target) {
        int i = 0, j = arr.length - 1, sum;
        while(i < j){
            sum = arr[i] + arr[j];
            if(sum == target){
                return new int[]{i + 1, j + 1};
            }
            if(sum < target){
                i++;
            } else {
                j--;
            }
        }
        return new int[]{-1, -1};
    }

    /*
        Two sum in unsorted array.
        https://leetcode.com/problems/two-sum/description/
    */
    public int[] twoSumUnsorted(int[] arr, int target) {
        int diff;
        Map<Integer, Integer> m = new HashMap<>();
        for(int i = 0; i < arr.length; i++){
            diff = target - arr[i];
            if(m.containsKey(diff)){
                return new int[]{m.get(diff), i};
            }
            m.put(arr[i], i);
        }
        return new int[]{-1, -1};
    }
}
