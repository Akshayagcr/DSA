#include<bits/stdc++.h>
using namespace std;

int main(){
    
    /*

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
            2. By including bits/stdc++.h increases the compilation time of the program. 
                It will not increase its execution time


        2. Time complexity analysis:
            Number of iterations run in 1 sec in online platforms = 10 ^ 7 to 10 ^ 8
            O(n) + O(n) + O(n) == O(n)

            * Sometime we will be given following kind of statements in competitive programming question
                a> Sum of N over all test case is < 10 ^ 7
                1 < T number of testcase < 10 ^ 5
                1 < N number of elements < 10 ^ 5
                1 < arr[i] < 10 ^ 3
                and if we have a program with nested loop then time complexity will be O(T * N)  i.e. 10 ^ 10
                but because of above statement (a) time complexity will be O(T) = 10 ^ 7
                because for T testcase we will have inner loop interation as n1 + n2 + ... nT and as given in statement (a)
                It will be < 10 ^ 7


        3. Why print ans % m:

            (a + b) % M = ((a % M) + (b % M)) % M
            (a * b) % M = ((a % M) * (b % M)) % M
            
            (a - b) % M = ((a % M) - (b % M) + M) % M ---> result of substraction can be negative se + M is added to make it +ve. 
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