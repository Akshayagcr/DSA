package c_binarysearch;

import java.util.Scanner;

/*
    https://leetcode.com/problems/search-in-rotated-sorted-array/description/

        target = 0

        0 1 2 3 4 5 6
        4 5 6 7 0 1 2
        F F F F T T T

        0 1 2 3 4 5 6
        F F F F F F F
        Step 1: find the boundary
        Step 2: Apply BS on the two half for target element
*/
public class f_rotated_sorted_array {

    static Scanner sc = new Scanner(System.in);

        static int binarySearch(int[] arr, int start, int end, int ele){
        int low = start, high = end, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(arr[mid] == ele){
                return mid;
            }
            if(arr[mid] > ele){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }

    static int findPartition(int[] arr){
        int pos = -1, low = 0, high = arr.length - 1, mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if(arr[mid] < arr[0]){
                pos = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return pos;
    }

    public int search(int[] nums, int target) {
        int partitionIndex = findPartition(nums);
        if(partitionIndex != -1){
            int left = binarySearch(nums, 0, partitionIndex - 1, target);
            int right = binarySearch(nums, partitionIndex, nums.length - 1, target);
            if(left != -1){
                return left;
            } 
            if(right != -1){
                return right;
            }
            return -1;
        }
        return binarySearch(nums, 0, nums.length - 1, target);
    }
    
}
