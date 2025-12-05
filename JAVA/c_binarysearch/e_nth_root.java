package c_binarysearch;

import java.util.Scanner;

public class e_nth_root {

    static Scanner sc = new Scanner(System.in);

    /*
        https://www.geeksforgeeks.org/problems/find-nth-root-of-m5843/1
    */
    static int nthRoot(int n, int m) {
        if(m == 0)
            return 0;
        int low = 1, high = m, mid;
        long nth;
        while(low <= high){
            mid = low + (high - low) / 2;
            nth = 1L;
            for(int i = 1; i <= n; i++){
                nth = nth * mid;
            }
            if(nth == m){
                return mid;
            }
            if(nth > m){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }


    static double nthRootV2(int n, int m) {
        double epsilon = 1e-5;
        double low = 1, high = m, mid, nth;
        // Binary search until the difference greater than eps
        while(high - low > epsilon){
            mid = low + (high - low) / 2;
            nth = 1;
            for(int i = 1; i <= n; i++){
                nth = nth * mid;
            }
            if(nth > m){
                high = mid; // Cannot do +/- 1 as it will may cause us to skip answer
            } else {
                low = mid;
            }
        }
        return low; // or high
    }

    public static void main(String[] args) {
        // System.out.println(nthRoot(sc.nextInt(), sc.nextInt()));
        System.out.println(Math.pow(10, 1.0/3));
        System.out.println(nthRootV2(3, 10));
    }
    
}
