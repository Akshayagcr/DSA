Parent question: matrix chain multiplication 

Identification:
1: In mcm problems we will be given an input array or string
2: we will get a feeling to break the input array or string into parts

I.e. will have three indexes I, j, k
Where I and j will be at extreme ends of array or string and k will vary from i to j

And we need to call a function on both the parts i.e fn(I, k) op fn(k+1, j)
Will get temporary any from this
We need to calculate for all k
And then get final ans from all this temporary answers

The operation between fn(I, k) op fn(k+1, j) depends on the ouestion given

And the final function we apply of all temp ans also depends on the question it can be max, minutes, sum etc.

Int solve(arr, I, j){
if(I > j) // base case
Return 0
Ans;
For k=I, k < j, k++{
Tempans = solve(I, k) op solve(k+1, j)
Ans = fn(and, tempans)
}
Return ans;
}

Base case : when I will be greater than j then we return 0

Given above is the basic format of mcm problem. Base case, function to join recursive call and function to apply on temporary answers will depend on specific problem which we are solving

Question: matrix chain multiplication 

We are given an input array where of integers 
a=[10, 20, 30, 40]
Which represents dimensions of the matrix
If there are n elements then array will contain dimension of n - 1 matrix

I.e. a1= 10*20
a2= 20*30
a3= 30*40

No of multiplication/cost of multiplying matrix a of dimension m*n and matrix b of dimension n*j

Is m*n*j

We need to multiply the given three matrix and need to multiply it optimally to minimize cost/no of multiplication.

Steps for writing code for mcm
1: fix I, j 
2: find out proper I and j for base case i.e. if I, j point to single matrix than the cost is 0
3: find proper value of k to be used in loop
4: calculate cost by combining return value of function and calculating cost of multiplication those matrices which are input to function calls
5: calculate minutes among those costs

*** Main thing is to proper initialize I, j and k and iterate properly inside loop

Memoized version:
Only I, j values are varying in every function call
So create a matrix where row and column represents I and j respectively and initialize it with -1
Before calculating mcm first check if there is an entry for I,j in dp table if there return value or else calculate it
And store the answer before returning 


Question: palindrome partation 

We are given a string and we have to partation the string so that each string in a partation is a palindrome. We have to minimize the total no of partation and return the count of partation 
Eg : s = nitik
We can partation it in three substring 
N, iti, k so minimum no of partation = 2

Identification: it is a variation of mcm as we need to partation the input string and check if the string we get is palindrome or not

Steps to solve mcm problem:
1: find I, j
2: base condition 
3: move from i to j using k
5: get final answer by applying fun on all temporary answers

Recursive solution:

For this question
1: we place I and j as start and end of string
2: **** if I == j a single character then it is a palindrome and if string length is greater than 1 we check for palindrome by applying palindrome function 
If any case is true return 0 as no partation are required
3: move k from i to j and recursive call solve function to get minimum no of partation in the partations formed by k and add 1 as we are doing partation on k

4 combine all temp ans using min function

Momoize it by storing ans in dp table before returning and checking dp table for i,j before solving.

****Interview bits site requires more optimised code than geekforgeek

**** Vimp: to make code more optimised also check the dp table for the two recursive calls in for loop also. It is not necessary that checking dp table only at start of function will suffice. Need to check dp table for each recursive function call

Question: evaluate expression to true

We are given an input string which consist of following symbols T, F, &, |, ^ only. We need to return no of ways we can place brackets so that the string eveluates to true.

Step 1: find I and j

I and j will point to characters i.e. t or f
And k will point to operator i.e. &, |, ^

And k will move from i + 1 to j - 1
In step of k = k + 2



In this problem I and j will not be sufficient as
Eg : exp1 ^ exp2
 To find total no of way in which this expression evaluates to true
Is 
No of false, left * no of true, right + no of true, left * no of false, right

We need to not only find no of ways true but also number of ways false also

So our method signature changes to

Int solve (array, I, j Boolean toFind)

We need to derive same formula as given above for all operators and both scenarios true and false

Base case: will be when I == j in that case of the character they are pointing is t then return true else false

**** Need to revise base condition 

Memoized solution 
DP table will be a 3d matrix as there are 3 parameters changing I,j, Boolean toFind
We can also use map insread of 3d array and in map key will be the changing parameter i, j and boolean toFind and value will be the calculated value of the solve function

now before we start calculating value we first check map if an entry is present or not
if present return that entry or calculate it in solve function and before returning store the value in map
which will be used later

Question: Scrambled string

We are given two strings we need to find if first string is a scrambled string of second or not i.e. we need to return Boolean

What is scrambled string : we need to represent a string as a binary tree where none of the node can be a empty string.
And we can swap non leaf node and if we swap two non leaf nodes than its parent string also changes accordingly 

Two strings are scrambled string of each other when from a binary tree of one string we can do zero or more swap to get second string

Key :
In this problem we need to split string at every possible position and swap it and check if it's equal to second string or not
It's a variation of mcm as we need to split string

After splitting we have two choices either to swap it or not
Eg : S1=greater,     s2=rgeater
Suppose we split the S1 at position 2

I.e.  gr, eater
After slitting we have two choices 
1: swap and compare
eater == rgeat
gr==er

2: no swap and compare
gr==rg
eater==eater

Base case : both input strings are equal
Return true

Steps for solving

1: Fix I at string.start and jat string.end
2: k loop
3: find temp answer by implementing two conditions
I.e swap and compare, don't swap and compare
4: if the result is true break loop and return
5: base case both input string are equal
If input string lengths are not equal immediately return false



Question : egg dropping problem

We are given n eggs and f floors. we need to find minimum no of attempts in works case we need to find a floor k. for which
if we drop a egg from any floor greater than k egg will break, and from floor k to ground egg will not break

Eg n = 1, f = 6
minimum no of attempts = 5
i.e. we start from ground floor we drop egg if it does not break then we throw egg from 1st floor and so on
therefore for n floor in worst case we require n - 1 attempts.

It is a variation of mcm problem as we need to find minimum no of attempt from k = 1 to f floor

Recursive solution:

for a given floor k we have to choices when we drop a egg from it
1: egg breaks
2: egg does not break

i.e. fn(e-1, k - 1), fn(e, f -k)
we have to take max of both the fn as we have to find minimum no of attempts in **worst case
*** reason in depth inlearning content

And we take min of all such temp ans from k = 1 to f

Memoize it with a dp table where row and column == [n][f], before calculating check in dp table
and when returning store the result in dp table
*** not only check in dp table about the top level fn call but also check for both recursive fn call 
whether its value is already calculated or not





