package d_precomputation;

import java.util.*;

/*
    Given T test cases and in each testcase a number N. Print its
    factorial % M
    Where M = 10^9 + 7

    1 <= T <= 10^5
    1 <= N <= 10^5
 */
public class a_factorial {

    private static Scanner sc = new Scanner(System.in);
    private static int M = (int)1e9 + 7;

    private static void solveNaive(){
        long res = 1;
        int n = sc.nextInt();
        for(int i = 2; i <= n; i++){
            res = (res * i) % M; // *** Careful as multiplication of 10^5 * 10^5 overflows for int data type.
            /*
                ***** Need to use res as long, if used int the for 12! value will store normally withing int
                but 12! * 13 goes beyond int range !!!! 
                even with mod apply it will overflow as before modulus operation,
                and integer multiplication is happing which overflows.

                Time complexity:
                O(T * N) = 10 ^ 10 iterations, so it will give time limit exceeded error.
                T is number of testcase and each test case we run loop of size N.
            */
        }
        System.out.println(res);
            
    }
    
    // public static void main(String[] args) {
    //     int T = SC.nextInt();
    //     while(T > 0){
    //         solveNaive();
    //         T--;
    //     }
    // }

    private static int[] fact = new int[(int)1e5 + 10];

    /*
        Optimized factorial code using pre-computation
        Time complexity:
        O(N) + O(T) = O(N) = 10 ^ 5 iterations
    */
    public static void main(String[] args) {
        fact[0] = fact[1] = 1;
        for(int i = 2; i <= (int)1e5; i++){
            fact[i] = (int)((1L * fact[i - 1] * i) % M);
            /*
                1L * -> converts the whole calculation in long
                % M -> reduces it back to int range
                (int) cast it back to int
                
                ****** 1L should come first or else it does not work
                If 1L is put in last like (int)((FACT[i - 1] * i * 1L) % M)
                then evaluation happens from left to right 
                i.e. int * int calculation which overflows happens first
                then it is casted to long and multiplied by 1

            */
        }
        int t = sc.nextInt();
        while(t > 0){
            System.out.println(fact[sc.nextInt()]);
            t--;
        }
    }


}
