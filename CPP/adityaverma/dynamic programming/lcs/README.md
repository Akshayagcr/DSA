Parent question: Longest common subsequence 

S1 = abcvdef
S2= abchdjk

Lcs = abcd

Subsequence = we can skip elements i.e. it is non continuous but in same order

Substring= continuous as well as in order

*****Recursive solution structure 
1: base case
2: Choice diagram
3: make input small

Make input small : we need to make input small inorder to terminate recursion. If ip is not getting smaller recursion will not end.

Generally in case of array or string we start from end index and keep decreasing the size
I.e. from n - 1, n - 2, ... 
This makes the input small

We take decision on last element based on choice diagram and then we reduce the input

In this problem we reduce the size of input string

Base case : think of smallest valid input
Generally in case of string it's is empty string i.e. size 0 same is the case with array

In this problem base case would be when for the two input string of size becomes zero for any one of the string then we return 0 as lcs



Choice diagram: 
Start with an example to understand all choices and decision 
And then draw choice diagram for an abstract input i.e. string x, y

In this problem we have following choices
1: last char of each string is equal
In this case we return 1 + lcs(len x - 1, len y - 1)

2. Last char not equal
In this case we have two choices
2.1 take first string as it is and reduce len of 2 string
2.2 reduce len of 1 string and take 2 string as it is
Then return max(2.1, 2.2)

Memozised version :

If a recursive function has only one call to itself then dp will not be applied
If a recursive function call itself twice in a single call then there can be overlapping sub problems
To make the recursive code efficient we can store answer to subproblems in a matrix. So that we can efficiently retrieve the ans of the subproblem from matrix rather than to recalculate

Matrix will be of size n * m where n and m are size of string which is varying in every function call
We initialize it with -1 and before computing the lcs we query the matrix to check if lcs is already calculated or not
If calculated just return the ans or else make recursive call and store the result in matrix


Tabulation:

In tabulation we omit the recursive call itself
Only matrix is there
We convert base case in recursion into initialization of DP matrix
And choice diagram into iterative code i.e. nested loop for fill rest of the cells In dp matrix

**** Each cell in dp matrix represents a subproblem and we get our final ans in mat[n][m]


Question: longest common substring 
Return length of longest common substring 

Substring is the continuous part of a string

Similarity with lcs:
As in lcs we are given two strngs in input and in output we need to return length.
Only difference is that instead of subsequence we need to ging length of substring 

Code variation 
Initialization of DP table will be same as if any one string is empty we cannot have substring 

In choice diagram
If last char are equal will add 1 in substring length till now same as lcs 
But in case the characters are different we return 0 as now string has become discontinuous which in case of lcs we were returning max of recursive function call as we can still continue counting length

This is the only change in code of lcs.


Question: print lcs between two strings

We check similarity based on in/op and what is asked in question. This problem is similar to lcs as input and what is asked i.e. lcs is same only thing different is the output 
Previous we were returning length now we need to return the subsequence itself

We start with tabulation method of lcs
Which gives us the dp table 

Value in a given cell in dp table is derived from following two ways (refer tabulation code of lcs)
If I, j is coornate of current cell then
1: if char at I and j is equal we copy value from i -1, j -1 
2: if char at I and j are not equal the we copy value from i-1, j or I, j -1 which every is maximum

By using the above concept
We start from cell t[m][n] and start moving backward by checking if char at that I and j are same or not
If same then we move diagonally backward cell or we go to cell up or cell to left of char are not equal we move to max of cell up or cell left
We move until we reach zeroth column or row and during traversal if char are equal we store that char in the resultant string


Question: length of shortest common super sequence

We are given two strings and we need to find length by merging the two strings the resulting string should contain both string as subsquences and the length of the merged string should be shortest

Eg : S1= abcdef,   s2= cdefgh
Follow are the possible super sequences
1: abcdefcdefgh (poor choice of just joining given string)
2: abcdefgh. (This is shortest common super sequence)

Key : lcs of both string will be the part that can be kept common in the merged string 

We can add both string length
So this total will include lcs two once from each string
Substract the lcs from the combined length

Length of shortest common supersequence = length of S1 + length of s2 - lcs


Question: No of insertions and deletion required to convert a string a into string b
Need to give no of insertions and deletion separately 

Identification :
Step 1: Identify if it is a DP problem or not
A question is DP if we need to make choice and something optimum is asked

Step 2: Identify which Pattern in DP
Knapsack pattern identification: We are given some array and a target value and we need to make choices from the array whether to take element or not

LCS pattern identification: We are given two string and something optimum is asked

To check if a question is of a particular pattern if any 2 of below 3 criteria is satisfied
1: ip
2: Question
3: output

in this question ip and op are same therefore LCS pattern is involved

Key: We first covert first string to LCS and then convert LCS to target string
i.e. logically we need to subtract element from first string to make it LCS and we need to insert characters in LCS to convert it in target string.

no of deletions = length of source string - LCS len
no of insertions = length of target string - LCS len


Question: longest palindromic subsequence
We are given a single input string first we need to make all subsequence of the string and then we need to filter out only the subsequence that are palindrome and then we need to find string with longest palindrome among it.

** This question itself can be considered as a catogery in dp but still lcs is the parent of this question

Identification: we can identify that it is a variation of lcs are the return type is same we need to return length and also the question involves finding subsequence

Key: we are given only one ip String because second string can be derived from first and it is the reverse of string

So if we find lcs between string and reverse of that string it will be the longest palindromic subsequence.

Question: minimum no of deletions to make a string palindrome 

Key: find the longest palindromic subsequence and then subtract it from the length of the input string. It will give the minimum no of deletions required to convert a string to a palindrome.



Question: print shortest common super sequence 

most poor way to get super sequence is to just concatinate the two strings
To get the shortest common super sequence we need to find LCS of both string as the lcs part will be repeated

Will use the same print lcs code
we just need to modify the code in which we move back from final resultant back to i == 0 or j == 0

In LCS we add character in resulting string only when the s1[i] == s2[j] 
and if they are unequal we move to either a cell up or cell to left depending on what is maximum
we still move to maximum cell but now we include the character in resulting string
i.e. if we move a cell up we add left cell character to resulting cell
and if we move a left cell we add character in cell above in resulting cell.


Question: longest repeating subsequence
We are given a single input string and we need find a subsequence whose replicate is present and its length should be greatest

eg : abchabc
longest repeating subsequence is abc

Key: We can concatinate the string with itself and take LCS with itself with condition that i != j
a b c h a b c
a b c h a b c
1 2 3 4 5 6 7

We have included the condition of 1 != j as we need to ensure that we dont use the same character 
which are already used in a subsequence

i.e.    1: a at index 1 should match with a at index 5, it should not match with a at same index
        2: b at index 2 should match with b at index 6, ..
        3: c at index 3 should match with c at index 7, ..
By using this condition It gives us abc subsequence which is the longest repeating subsequence



Question: Sequence pattern matching

We are given two strings a and b, we need to find if string a is a subsequence of string b or not
a = "abc", b = "xycahbc"

*** to find which question is nearest to the question match its ip, op and question.
In this question ip, op and question is same as minimum no of deletion to make a string palindrome.

Key: Just find the LCS between two string. If lcs length == a.length() return true else false.


Question: minimimum no of insertions required to make a string palindrome

Key : find lcs between the input string and reverse of input string
find the unique characters = length of input string - length of lcs

minimum no of insertions = no of unique charaters

