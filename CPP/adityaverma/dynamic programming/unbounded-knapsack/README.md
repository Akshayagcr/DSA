Parent question: Unbounded knapsack 

Difference with 01 knapsack:
In 01 knapsack once we take a decision to include or exclude we have processed and element. But in unbounded knapsack we can again include an element in knapsack untill condition is not violated. Element is considered as processed only when we decide not to take it (i.e when condition is violated)

Only code variation in 01 knapsack is when we consider to take an element in choice diagram we include it's value and call knapsack on remaining elements i.e. n - 1

In unbounded knapsack we will again call knapsack function on n.

Only one code change is required and will get code for unbounded knapsack.

*** Relate all problems with other as there will only be a very minor modification. This way of thinking helps rather than solving each question as new

Question: Rod cutting problem

We are given an integer L representing length of a rod and and value array and length array i.e. what is the value of profit for corresponding length and we need to cut rod in such a way to maximize the profit

Similarity:
It is similar to knapsack as we are given two array and we need to maximize profit

01 or unbounded knapsack:
Here we can cut rod in similar length also support rod length is 6 we can cut rod in 6 equal parts of 1 unit. So it is variation of Unbounded knapsack.

Code variation:
There is absolutely no difference between unbounded knapsack and rod cutting problem. It is just a different way to ask a question 

Question: Coin change : Maximum number of ways


We are given an array of denomination and a sum s. We need to return no of way we can use denomination to get sum s. 

It is similar to knapsack as we need to choose from the given denomination and we are given an sum which is similar to capacity of knapsack 

It is variation of Unbounded knapsack as we can use a denomination n number of time

This is exactly similar to count no of subset with given sum.

Question: Coin change : Minimum number of coins

It is variation of Unbounded knapsack

We start with initialisation of the dp table 
This is a special problem where not only first row and first needs to be initiated but also second row
Reason not explained 
And in initialisation if we are given zero coins and we need a sum greater than zero then we initialize with intmax 
Reason not told clearly

If we need a sum 4 and we only have a coin with denomination 3 thne it is not possible to achive the sum then in that case also we initialize with intmax
Reason not told clearly 

Then same code for unbounded knapsack come and in case where we include a choice we just need to add +1 as it denotes that we have choosen a coin

Parent question: longest common subsequence 




