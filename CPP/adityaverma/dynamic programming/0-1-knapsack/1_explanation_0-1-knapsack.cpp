#include<bits/stdc++.h>
using namespace std;

/**
 * Identification:
 * If problem contains following two things then it is a DP problem
 * 1. choice 2. optimal
 * This a DP problem as we are need to make choices among given items as well as we have been asked about
 * maximum profit. 
 * Steps of solving : 1. Write recursive solution, 2. Memorize it 3. write Top down
 * 
 * ****** DP = Recursion + storage(memorization/top down(matrix))
 * 
 * We make choice diagram for a single item
 *  1. weight of item is less than capacity 
 *      1.1 We take the item
 *      1.2 we dont take the item
 * 2. Weight of item is greater tha capacity
 *      2.1 We can not take the item. 
 * 
 * (Visualize the above statement by drawing it in form of tree)
 * 
 * Important parts and structure of recursive function
 * 
 *  return_type function(inout){
 *      base condition
 *      choice diagram
 * }
 * 
 * 1. return type  2. inout   3. base condition    4. choice diagram
 * 
 * Base condition = think about smallest possible valid input
 * i.e. in this case it will be when input array size is zero i.e. no item present or when capacity is zero
 * in these conditions profit will be zero
 *  
 * check recursive solution knapsackRecursive
 * 
 * after seeing and understanding check memorization knapsack
 * 
 * after that check knapsack top down
 * 
 */

    int knapsackRecursive(vector<int>& weight, vector<int>& value, int capacity){
        int n = weight.size();
        /**
         * Base condition
         */
        if(n == 0 || capacity == 0){
            return 0;
        }
        if(weight[n - 1] <= capacity){
            int value_last_item = value[n - 1];
            int weight_last_item = weight[n - 1];
            weight.pop_back();
            value.pop_back();
            int profit_one = value[n - 1] + knapsackRecursive(weight, value, capacity - weight_last_item);
            int profit_two = knapsackRecursive(weight, value, capacity);
            return max(profit_one, profit_two);
        } else{
            weight.pop_back();
            value.pop_back();
            return knapsackRecursive(weight, value, capacity);
        }
    }

    /**
     * in the function call determine the values that are changing. 
     * these values will represent row and column in matrix
     * create a matrix globally with maximum value provided in constrain. this is to prevent it from passing around
     * first thing we do when entering a function is to check whether for given input value is stored in matrix or not
     * ** initialize the matrix with -1 using **** memset(mat, -1, sizeof(mat)) function in main
     * if value is not present we store the value in matrix after recursive function call instead of directly returning
     * and then we return
     */
    int knapsackMemorised(vector<int>& weight, vector<int>& value, int capacity){
        // TODO : complete implementation
    }

    /**
     * 1: Recusrive sol = base case + recursive call
     * 2: memoized sol = recursive call + storage(matrix)
     * 3: Top down = matrix (In top down we remove recursive call as in some rare cases recursive call will 
     * lead to stack overflow)
     * *** recursion should be strong for DP
     * 
     * Steps involved in writing top down approach using matrix only no recursive code
     * 
     * Step 1: initialization
     * Step 2: turn recursive code into iterative code
     * 
     * dimensions of matrix
     * If there are n items and w capacity of knapsack
     * the matrix will have 0 index + n rows and 0 index + w capacity row
     * 0th row and column will be filled in initialization step. it represents
     * 0 elements a and capacity zero
     * we will get answer in call mat[n][m]
     * every other cell represents a subproblem
     * 
     * Base condition in recursive call changes to initialization of matrix in top down approach. 
     * 
     * look at the recursive code and change it in iterative version
     * every function call will be replaced by lookup in matrix. and the current i, j is solved by using
     * the value of the sub problem some (i - val)(j - val)
     * 
     * functionCall(n, w) == mat[i][j]
     * 
     */
    void knapsackTopDown(){

    }


int main(){

}