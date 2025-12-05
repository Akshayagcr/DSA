package c_binarysearch;

import java.util.*;

public class a_binary_search {

    static Scanner sc = new Scanner(System.in); 

    static int binarySearch(int[] arr, int ele){
        int low = 0, high = arr.length - 1, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(arr[mid] == ele){
                return mid;
            } 
            if(arr[mid] < ele){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
    
    /*
        10 20 20 30 30 30 40 40 40 40
        0  1  2  3  4  5  6  7  8  9
    */
    public static void main(String[] args) {
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }
        int ele = sc.nextInt();
        System.out.println(binarySearch(arr, ele));
    }
}
