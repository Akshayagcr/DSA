package d_precomputation;

import java.util.Scanner;

/*
    Given array a of N integers. Given Q queries
    and in each query given a number X, Print
    count of that number in array.

    Constraints
    1 <= N <= 10^5
    1 <= a[i] <= 10^7
    1 <= Q <= 10^5
 */
public class b_count_elements {

    static Scanner sc = new Scanner(System.in);

    static int countEleNaive(int[] arr, int x){
        int count = 0;
        for(int i = 0; i < arr.length; i++){
            if(arr[i] == x){
                count++;
            }
        }
        return count;
    }

    /*
        Time complexity:
        O(N) + O(Q * N) = 10^5 * 10^5 = 10^10 iterations
    */
    // public static void main(String[] args) {
    //     int n = sc.nextInt();
    //     int[] arr = new int[n];
    //     for(int i = 0; i < n; i++){
    //         arr[i] = sc.nextInt();
    //     }
    //     int q = sc.nextInt();
    //     while(q > 0){
    //         int x = sc.nextInt();
    //         System.out.println(countEleNaive(arr, x));
    //         q--;
    //     }
    // }

    /*
        Time complexity:
            O(N) + O(Q) = 10^5 iterations
    */
    public static void main(String[] args) {
        int[] count = new int[(int)1e7 + 10];

        int n = sc.nextInt();
        for(int i = 0; i < n; i++){
            count[sc.nextInt()]++;
        }

        int q = sc.nextInt();
        while(q > 0){
            System.out.println(count[sc.nextInt()]);
            q--;
        }
    }
    
}
