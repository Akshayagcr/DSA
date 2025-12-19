Question: we are given an array of integers and a sub-array size k we need to find a sub-array of size k with maximum sum

Brute force : we apply two nested loops first going from array start to end - k and inner loop going from outer loop index till k and it sums and we keep track of maximum 

In brute force approach we do repetitive work i.e. if k = 3 then we first sum index from 0 + 1 + 2 and then again sum 1 + 2 + 3 so we are doing repetitive work of adding 1 + 2

*** Whenever we see repetitive work there is possible of optimization 

Optimized approach : instead of every time summing the window we just need to subtract first element and add new element 

Identification: whenever a question involves a subarray or substring and a window size is given and we are asked about minimum, maximum etc then the problem is of sliding window 

Types of sliding window:
1: fixed length sliding window 
2: variable length sliding window : sometime in question the length of sliding window will not be given instead it will be variable like find the maximum length subarray with sum equal to 5


Question: maximum sum subarray of size k

General structure of sliding window code for fixed size window :

i: window start, j : window end

i, j = 0
while(j < array end){
    1: do calculations
    if(check if window size is achived or not){
        j++
    } else {
        get answer from calculation
        move window
    }
}

In this question 
step 1: Doing calculation is summing the array elements
step 2: Is to get max from all answer
Step 3: is just go i++, j++

Question: first negative integer in a window of size k

In this question
Step 1: Of doing calculations is to keep track of negative integers by storing them in queue.
step 2: is to get negative integers from the stored integers
step 3: we need to check while moving the window ahead that we also remove the negative integer from the front of the queue

Question: Count occurrence of anagram

Given two strings we need to find the count of total number of times and anagram of a string occurs in the first string

Anagram : given a word all of its permutation are anagram of the word

Identification: This is a variation of sliding window as we need to find sub arrays which are anagrams and length of second string indirectly represents window size

We first create a character frequency map from second string and a variable that keep tracks of characters whose frequency becomes zero initially it would be equal to size of the map

We start iterating over the first string with I,j equal to zero an iterate till j does not reached end of the string

In calculation part we check which is the current character and decrement the count in frequency character array also keep track of the count becomes zero we also decrement the variable which keeps count of no of characters which are zero

In the if condition we check if we have hit the window size it remains same

Once we have hit the window size i.e. in else condition we if the variable has become zero or not if zero we have encountered an anagram so increase the count of anagram

While sliding window i.e. when incrementing I we update character frequency map and variable 

Question: maximum of all subarray of size k

We are given an array and a window size k we need to return an array containing maximum element of every window of size k

Calculation step for j

We use a queue to keep all important element, all element which are smaller to j to its left are of no use as current maximum will be j but all small element to right of j are important as when we will remove current max j there is a possibility that smaller element will be the next maximum

For every j we check if all element in front of queue are smaller or not if smaller pop from the front and then push j in the queue

When sliding the window ahead i.e. when incrementing I we need to check if queue front is equal to I ordered not if equal pop I from the front of the queue.

***** Variable length sliding window 

Question: Longest subarray of sum k

Difference and identification of variable sliding window pattern :

It is same as fixed length sliding window we will be given an array or string and subarray or substring will be involved now the only difference is that in place of window size k we will be given a condition 

General structure of variable sliding window 

I,j = 0
While(j < are.length){
    Do calculation
    If(calculation < k){
        J++
    }
    If(calculation == k){
        Get answer from calculation 
        J++
    }
    If(calculation > k){
        While(calculation > k){
            Remove element I from calculation 
            I++
        }
    }
}

So in this problem we need to implement the three conditions 
Calculation == calculating sum
Sum < k, sum == k, sum > k

Question: Longest substring with k unique character 

Calculation = keep track of no of unique character in string using map

Question : longest substring without repeating character 

Identification:
Is a problem of sliding window pattern as question involves an array/substring and we are asked about substring and it also gives us the condition instead of window size i.e unique character so it is a problem of variable size sliding window

We use a HashMap to keep track of frequency count of each character 

Calculation 
When window size j - I + 1 is equal to size of hash map which means our window contains all unique character

Question: Pick a toy

We have a rack of toy we can only pick two types of toy and that to in continuous and we need to take maximum number of toys

This problem is equal to 
Return largest subarray with unique character number of unique character equal to k


Question: minimum window substring 

We are given two strings one longer than other and we need to find a miminum substring which is equal to th smaller string.

Calculation : We need to use and hashmap filled with frequency characted of smaller string and a count variable which keep track of number of character whose frequency count is Zero. once count reached zero we get a possible candidate of ans we increase variable i i.e. shrink window till count does not becomes equal to zero.
