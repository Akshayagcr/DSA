package f_slidingwindow;

import java.util.Scanner;

/*
    https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399
*/
public class e_longest_subarray_sum_k {


    public static int longestSubarrayWithSumK(int []arr, long k) {
        int maxWindowLength = 0, low = 0, high = 0;
        long currentSum = 0;

        while(high < arr.length){

            currentSum += arr[high];

            if(currentSum < k){
                high++;
            } else if (currentSum == k) {
                maxWindowLength = Math.max(maxWindowLength, high - low + 1);
                high++;
            } else {
                while(currentSum > k){
                    currentSum -= arr[low];
                    low++;
                }
                if(currentSum == k){ // need to check if our target is achieved before moving the window 
                    maxWindowLength = Math.max(maxWindowLength, high - low + 1);
                }
                high++; // As we have already processed high as part of calculation. We need to increment high to avoid re-processing 
            }
        }

        return maxWindowLength;
    }

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int n = sc.nextInt();
        int[] arr = new int[n];

        int k = sc.nextInt();

        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println(longestSubarrayWithSumK(arr, k));
    }

}
