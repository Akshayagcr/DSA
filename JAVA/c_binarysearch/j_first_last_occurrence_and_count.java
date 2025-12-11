package c_binarysearch;

import java.util.*;

/*
    https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
*/
public class j_first_last_occurrence_and_count {

    static Scanner sc = new Scanner(System.in);
    
    static int countFreq(int[] arr, int target) {
        int first = firstOccurrence(arr, target);
        if(first == arr.length){
            return 0;
        }
        return lastOccurrence(arr, target) - first + 1;
    }

    /*
        6 7 7 8 8
        0 1 2 3 4
    */
    static int firstOccurrence(int[] arr, int ele){
        int low = 0, high = arr.length - 1, mid, pos = arr.length;
        while (low <= high) {
            mid = low + (high - low) / 2;
            /*
                Finding first occurrence != lower bound
                As in lower bound we find >= target
                While in first occurrence finding greater will not work if element is not present
                Therefore either we need to include below if for equals condition or
                will find lower bound and we need to add a check for target equality.
            */
            if(arr[mid] == ele){
                pos = mid;
                high = mid - 1;
            } else if(arr[mid] < ele){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return pos;
    }

    /*
        6 7 7 8 8
        0 1 2 3 4
    */
    static int lastOccurrence(int[] arr, int ele){
        int low = 0, high = arr.length - 1, mid, pos = arr.length;
        while(low <= high) {
            mid = low + (high - low) / 2;
            if(arr[mid] == ele){
                pos = mid;
                low = mid + 1;
            } else if(arr[mid] < ele) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return pos;
    }

    public static void main(String[] args) {
        int target = sc.nextInt();
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println(countFreq(arr, target));
    }
}
