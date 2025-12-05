package c_binarysearch;

import java.util.*;

public class c_upper_bound {

    static Scanner sc = new Scanner(System.in);

    /*
        https://www.geeksforgeeks.org/problems/implement-upper-bound/1
        
        upper bound == greater than 
        if element does not exists and is the largest return length of array
    */
    static int upperBound(int[] arr, int ele){
        int pos = arr.length, low = 0, high = arr.length - 1, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(arr[mid] > ele){
                pos = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return pos;
    }

    /*
        For ele = 20
        10 20 20 30 30 30 40 40 40 40
        0  1  2  3  4  5  6  7  8  9
        F  F  F  T  T  T  T  T  T  T
    */
    public static void main(String[] args) {
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }
        int ele = sc.nextInt();
        System.out.println(upperBound(arr, ele));
    }
    
}
