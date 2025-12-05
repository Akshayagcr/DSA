package d_precomputation;

import java.util.Scanner;

/*
        Given Q queries and in each query given an index i, 
        Print the fibonacci number at that index.

        Constraints
        1 <= Q <= 10^5
        1 <= i <= 10^5
*/
public class z_misc_fibonacci {

    static Scanner sc = new Scanner(System.in);
    static int[] fibo = new int[(int)1e5 + 10];
    
    public static void main(String[] args) {
        fibo[1] = 1;
        for(int i = 2; i <= (int)1e5; i++){
            fibo[i] = fibo[i - 1] + fibo[i - 2];
        }
        int q = sc.nextInt();
        while(q > 0){
            System.out.println(fibo[sc.nextInt()]);
            q--;
        }
    }
}
