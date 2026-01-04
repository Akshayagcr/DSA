package f_slidingwindow;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class a_maximum_sum_subarray_size_k {
    
    /*
        https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
    */
    public int maxSubarraySumOne(int[] arr, int k) {
        int currentSum = 0, maxSum = 0, low = 0, high = 0;

        while(high < arr.length){
            currentSum += arr[high];
            if(high - low + 1 < k){
                high++;
            } else {
                if(currentSum > maxSum){
                    maxSum = currentSum;
                }
                currentSum -= arr[low];
                low++; high++;
            }
        }

        return maxSum;
    }

    /*
        https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
    */
    public static long maximumSubarraySumTwo(int[] arr, int k) {
        long currentSum = 0, maxSum = 0;
        int low = 0, high = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        
        while(high < arr.length){
            currentSum += arr[high];
            if(map.containsKey(arr[high])){
                map.put(arr[high], map.get(arr[high]) + 1);
            } else {
                map.put(arr[high], 1);
            }
            if(high - low + 1 < k){
                high++;
            } else {
                if(currentSum > maxSum && map.size() == k){
                    maxSum = currentSum;
                }
                if(map.get(arr[low]) == 1){
                    map.remove(arr[low]);
                } else {
                    map.put(arr[low], map.get(arr[low]) - 1);
                }
                currentSum -= arr[low];
                low++; high++;
            }
        }

        return maxSum;
    }

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }
        int k = sc.nextInt();
        System.out.println(maximumSubarraySumTwo(arr, k));
    }

}
