package a_general;

import java.util.*; // **** To import all utility classes

public class Basics{


    private static void printArray(int[] arr){
        for(var ele : arr){
                System.out.print(ele + " ");
        }
        System.out.println();
    }

    private static void print2DArray(int[][] arr){
        for(var row : arr){
            for(var ele : row){
                System.out.print(ele + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {

        /*
            Datatype:

            char        single quotes
            boolean     true/false --> Cannot use int value like cpp 
            int(32-bit)     - 10 ^ 9 to 10 ^ 9      Integer.MIN_VALUE to Integer.MAX_VALUE
            long (64-bit)   - 10 ^ 18 to 10 ^ 18    Long.MIN_VALUE to  Long.MAX_VALUE
            String(Class)       double quotes

            1e5   --> 10 ^ 5

            Calculations always happens in higher data type
            result of 3/2 is 1 where as 3/2.0 is 1.5

            ***** To convert a calculation to long "1L*" should come first or else it does not work
            FACT[i] = (int)((1L * FACT[i - 1] * i) % M)

            1L * -> converts the whole calculation in long
            % M -> reduces it back to int range
            (int) cast it back to int
            
            If 1L is put in last like (int)((FACT[i - 1] * i * 1L) % M)
            then evaluation happens from left to right 
            i.e. int * int calculation which overflows happens first
            then it is casted to long and multiplied by 1
        */

        int i = (int)1e9 + 10;
        long l = (long)1e18 + 10;
        System.out.println("i=" + i + " l=" + l);

        System.out.println("3/2=" + 3/2 + " 3/2.0=" + 3/2.0);

        /*
            Scanner sc = new Scanner(System.in);
            sc.nextInt(), sc.nextLong() --> Ignores whitespaces & newLine i.e. input can be on same line separated by spaces or on new line
            Once the number is inputted. The cursor remains on same line. To move cursor to next line to take input of String use
            sc.nextLine(); --> Moves cursor to new line.
            String s = sc.nextLine(); --> To take String input

            String:
                String s = "Akshay";
                + --> for concatenating String
                use .equal to compare String
                Use *****StringBuilder --> For mutable strings

            *** Java is always and only pass-by-value. 
            For primitive values are copied and for objects their references are copied when passed in a method.

            Arrays:
                int[] arr = new int[10]; // Any int array created using new in Java is always initialized with zeros.
                int[] arr2 = new int[]{1, 2, 3, 4, 5};

                int[][] arr2 = new int[2][2];
                int[][] arr3 = new int[][]{{1, 2}, {2, 3}};

                We can pass 1d & 2d array as below
                print2DArray(int[][] arr)
                printArray(int[] arr)

         */

         int[] arr = new int[10];
         printArray(arr);

         int[][] arr2 = new int[2][2];
         int[][] arr3 = new int[][]{{1, 2}, {2, 3}};
         print2DArray(arr3);

         /*

            *** In java all array whether declared within method or class gets created in heap.
            So the size is limited by heap memory, not stack.

            1. Online competitive programming platforms:
            Generally we have the below constraints in online platform for time and memory. This is the prime reason that
            we can only declare array of maximum size 10 ^ 7 whereas same memory restriction is not there in local machine.
            
            1. Memory limit : 256 MB
            2. Time limit : 1 sec
    
            MemoryExceededError : Occurs if we try to declare array of size > 10 ^ 7
            RuntimeError : Occurs mostly because we tried to access memory which is not allowed eg: accessing array index which is outOfBound
            TimeLimitExceeded: If program takes more than 1 sec.

            1. In recursive program we can get both TimeLimitExceeded as well as MemoryExceededError depending on situations
                i.e. will get MemoryExceededError when the call stack size grows beyond limit and TimeLimitExceeded if recursion takes more time.
           
        2. Time complexity analysis:
            ********** Number of iterations run in 1 sec in online platforms = 10 ^ 7 to 10 ^ 8
            O(n) + O(n) + O(n) == O(n)

            * Sometime we will be given following kind of statements in competitive programming question
                a> Sum of N over all test case is < 10 ^ 7
                1 < T number of testcase < 10 ^ 5
                1 < N number of elements < 10 ^ 5
                1 < arr[i] < 10 ^ 3
                and if we have a program with nested loop then time complexity will be O(T * N)  i.e. 10 ^ 10
                but because of above statement (a) time complexity will be O(T) = 10 ^ 7
                because for T testcase we will have inner loop iteration as n1 + n2 + ... nT and as given in statement (a)
                It will be < 10 ^ 7


        3. Why print ans % m:

            (a + b) % M = ((a % M) + (b % M)) % M
            (a * b) % M = ((a % M) * (b % M)) % M
            
            (a - b) % M = ((a % M) - (b % M) + M) % M ---> result of subtraction can be negative so + M is added to make it +ve. 
            But it will not have any effect as we can expand using addition formula which will result in M % M which will be zero
            
            (a / b) % M = ((a % M) * (b ^ -1 % M)) % M ---> b ^ -1 is multiplicative inverse

            In many programming questions we will be given that print answer modulo M
            In programs such as factorial the value grows very fast i.e. factorial of 21 goes beyond the range of long long
            in such question we are given that print ans % M to make it feasible to calculate & store result.

            a % M result will always be less than M

            In most questions the value of M is 10 ^ 9 + 7 there are two reasons for its significance
            1. Its very close to integer range
            2. M = 10 ^ 9 + 7 is a prime number which makes it possible to find multiplicative inverse of numbers from 1 to M.

          */
         
    }
}