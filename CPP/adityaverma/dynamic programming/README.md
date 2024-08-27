Dynamic programming parent questions

1. 0/1 knapsack
2. Unbounded knapsack
3. Longest common subsequence (LCS)
4. Matrix chain multiplication


Learnings from 01 knapsack:

1: Memoized solution does not fill all cell in the DP table for a single function call. 
Prefer Tabulation method as it is more efficient and a single call fills all cells in DP table

2: *** If input contains zeros then it need special considaration in code.

3: In memoization we initialize dp table with -1. but in tabulation method it is not required
according to problem initialize it with 0 or other value as required.

4: *****VIMP : Read all learning content of 01 knapsack.

Learnings from unbounded knapsack

1: In counting problem we dont do +1 we jsut add counting from both choices i.e. when element is 
included or excluded. we need to do +1 in problems like coin change minimum nummber of coins 
as if we include a coin we need to do +1

2: We need to use INT_MAX in problem coin change minimum no of coin. as it correctly represents unrechable states
and works naturally with min().

3: In coin change problem (Minimum no of coin required) we like other problem only initialize zeroth row and column

4: *****VIMP : Read all learning content of unbounded knapsack.



My thinking:

For base case thing about smallest possible trival unit in the problem. 
Like a single matrix in case of MCM, a single lement in case of merge sort
In MCM cost of multiplying a single matrix is zero
In merge sort a single element can be consider as sorted.
Basically think about unit in which we do not need to do any work
work will be done in induction step i.e. when combining results from recusrive calls

