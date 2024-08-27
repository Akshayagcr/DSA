package c_binarysearch;

import java.util.Scanner;

/*
    https://leetcode.com/problems/valid-perfect-square/
*/
public class d_perfect_square {

    static Scanner sc = new Scanner(System.in);
    
    static public boolean isPerfectSquare(int num) {
        int low = 1, high = num, mid;
        long dbl;
        while(low <= high){
            mid = low + (high - low) / 2;
            dbl = 1L * mid * mid;
            if(dbl == num){
                return true;
            } 
            if(dbl > num){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println(isPerfectSquare(sc.nextInt()));
    }
}
