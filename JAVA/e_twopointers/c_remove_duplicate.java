package e_twopointers;

import java.util.*;

/*
    https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
*/
public class c_remove_duplicate {

    static Scanner sc = new Scanner(System.in);

    public static int removeDuplicates(int[] arr) {
        int i = 0, temp;
        for(int j = 1; j < arr.length; j++){
            if(arr[i] != arr[j]){
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        return i + 1;
    }

    public static void main(String[] args) {
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println(removeDuplicates(arr));
        for(int i = 0; i < arr.length; i++){
            System.out.print(arr[i] + " ");
        }
    }
}
