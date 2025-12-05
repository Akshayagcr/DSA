DP is enhanced recursion 
Recursion is parent of DP

Companies which gives high packages ask DP question 

Identification of DP

1. We need to make choices
Whenever a function make two calls to itself i.e. a single node in recursion tree has two child nodes 
If a recursive function has a single call to itself on smaller input than dp will not be applied

Then there can be overlapping sub problems
In that case DP will be applied

2. Optimal is asked like smallest, largest, minimum, maximum 

Steps to solve DP:
Step 1: write recursive solution 
Step 2: memorize it
Step 3: convert it to top down i.e. solution which involves matrix

DP parent questions
1. 0/1 knapsack
2. Unbounded knapsack
3. Fibonacci
4. longest common subsequence (lcs)
5. longest increasing subsequence (lis)
6. Kadanes algorithm 
7. Matrix chain multiplication 
8. DP on tree
9. DP on grid
10. Others


Question : 0/1 knapsack:

Related problems 
1. Subset sum
2. Equal sum partition 
3. Count of subset sum
4. Minimum subset sum difference 
5. Target sum
6. No of subset given difference 

Type of knapsack 
1. Fractional knapsack - this is a greedy problem
    We can take a fraction of a single item.
2. 0/1 knapsack - DP
    We either take a item as whole or not take it.
3. Unbounded knapsack
    We have n instances of a single item. if needed we can fill the entire knapsack with this single item only.

In knapsack problem we are given a Bag with capacity W
And n items where each item is having its weight and it's value

Input 
Capacity W
Weight array
Value array

The problem is to choose from n items which can be placed in bag to maximize profit respecting the bags capacity 

See 1_explanation_0-1-knapsack.cpp


In all variations of knapsack problem there will be different values for initialising the matrix
Rest a small modification in knapsack problem will be required 

Identification of a knapsack problem:
We will be given n items from which we have to make a choice to include it or not
And a value similar to capacity will be given in the problem

Question: subset sum

We are given an array of integer. And a target sum. We need to check if any subset of given input array adds up to given target sum.

Identification: It is a variation of knapsack as in this question we are given an value similar to capacity i.e. target sum and we have to make choices from n elements

Code variation:
Start with initialisation of matrix
Where row and column indicate sunsets and target sum
Each cell in matrix contains Boolean entry as current question just ask us whether it's possible or not 

If we are given an empty set then we can construct an empty set with target sum equal to zero 
Also if we are given an subset which contains elements we can construct empty set with target sum equal to zero

Weight array in knapsack changes to the array in this problem
Max in knapsack changes to OR between Boolean

Rest code will be similar to knapsack
Draw choice diagram to understand why this changes are required 
**Draw choice diagram representing a single number in a subset**

**Choice diagram is drawn for a single element. It is not recursive tree**


Question: equal sum partition 

We need to return Boolean whether or not we can partition the given input array into two subset which have equal count

If the sum of entire array is add them there is now way to partition it equally so return false

If sum is even we call subsetsum function which will check if totalSum/2 target sum is present or not in the input array. If present return true else false.

Question: Count of subset for a given sum
We need to give number of subset whose sum is equal to target sum

Similarity with subset sum : it is similar to subset sum problem as in subset sum we were asked about whether a sum is present or not i.e. a Boolean output but here we need to return the count

Code variation
1: initialisation: if there are n elements in array and sum is s then the matrix will be t[n + 1][s + 1] 

Row == i == subset 
Column == j == weight == sum

Start by initialising first row and first column same as subset sum problem but now instead of Boolean will have an integer

** We can draw a recursive tree with an example subset starting i.e. root node with empty subset and each level of tree represent and decision about an element in input subset i.e. based on condition given in problem we include and element or not include

Draw choice diagram for an element x and then code it. Comparing and taking help from knapsack code

OR condition in subset sum will convert to + in this problem.

**** Question: minimum subset sum difference 
We are given an array we have to find two subset whose difference of their respective sum will be the minimum 

My thought:
1: we call subSetSumTabulation() with all element n and sum / 2 == target
2: By calling subSetSumTabulation we get DP table with row t[n][i] representing if a given sum subset is present or not
3: Check code for remaining logic (It worked successfully)

Key of question: 
Last row of our matrix in subset sum represent if we are having all elements in array and whether from 1 to sum if a subset is present or not

Therefore we need to call subset sum once and use the last row of matrix to efficiently check if a we can get a subset with given sum or not

Question: count no of subset with given difference 

Given two subset S1 and s2 and a target difference 

We need to find the count of all sunch subset
S1 - s2 = diff ------ eq 1
As we know that S1 + s2 = total
So s2 = total - s1------ eq 2

S1- total + S1 = diff ------ from eq 1 and 2
s1 = (diff + total)/2

So we need to find count of subset with target sum = (diff + total)/2



Question: Target sum
We are given an integer array and we have to put +/- sign infront of every elemnt such that we get the target sum
and we have to count number of such subset.

This question is same as count number of subset with given difference as we as assigning +/- is equal to partationing array
into two subset nad the difference should be equal to given sum.

It is just another way of asking the same problem.




