


Recursion is everywhere !!!

Recursion is the parent of
1: Dynamic programming
2: Backtracking
3: Divide and conqure

We can apply recursion in every data structure. lot of problem on every DS involves recursion.

Two methods to solve recursive problem
1: ip op method
2: extended ip op method

problems:

1: print 1 to n using recursion

recursion works on = base case + hypothesis + induction
Sometimes it is difficult or not obvious how to make a decision. In that case thinking to make input small helps

methods to think for solving recusrsive problem
1: recursive tree - IO/OP method - when its clear what decision we need to take
2: base case - induction -hypothesis  - when what decision to take is not clear and breaking ip in smaller input is clear
3: choice diagram
4: to be discussed later

hypothesis == we assume that our function will retun a value for an input x
induction == we need to code something in induction to make hypothesis work
base condition == smallest valid ip or largest invalid input

IBH method is most useful in case of linkedlist or tree

start thinking from following order to solve problem
1: IBH
2: recursive tree - IP/OP method
3: choice diagram.


*********************************************************************************************

Recursive is best way to represent decision space 

Problem identification = we will be given choices + we have to take decisions

In recursion main goal is to make decisions 
As result of this input becomes small

Imp *** if for a problem statement if we are able to draw a recursive tree 
Then writing code is a cake walk 

Eg : generate all subset of a given string

At every step we have to take decision whether to include the char in the string or not for every char in string 

We need a method to represent the decision taken
And recursive tree is the method to represent the decision 

Use ip-op method to create recursive tree 

Draw a complete binary tree
Where at each node we write down the ip and op at that point 

No of branches in recursion tree represents no of choices

Once we come down a branch it represents that we have taken a decision 

We get answer in leaf node once the input is empty

2 steps to solve recursive problem
Step 1: draw recursive tree
Step 2: write code 
***If we draw recursive tree then problem is done

******************************* part 2 ***************************************

Incase of ip op method we only go one step down

And in recursion tree we draw the entire tree to know where we are getting solution 

Q: Delete middle element of stack

Hypothesis:
removeMiddleEle(stack, indexOfEleToDelete)

We call this method with stack size - 1 and index -1 

While calling the function we need to store the top element in a temp variable and once the function returns stack with middle element deleted 
We push the temp variable on top

Storing temp variable and pushing it afterwards is our induction step

Base case occurs when indexOfEleToDelete is 1 and we just pop the element and this deletes the middle element 

And then induction step of storing temp and pushing it back restores the elements above of the middle element 

Reverse a stack 

******************************* part 3 ***************************************
Nth symbol in grammer

Question
K == rows
N == Nth symbol in Kth row

Start with
N== 1, K== 1 oup == 0

Substitute every 0 with 01 and 1 with 01

Eg : N = 4
0
0 1
0 1 1 0
0 1 1 0 1 0 0 1

Solution

Int solve(k,n ){

If n and k == 1 
Return 0

Else 

Temp arr[k - 1][n / 2]

If n == even
Return temp
Else 
Return inverse of temp
}

Above soln works if we are storing it in array
But as we need to use recursion

As which decision to take is not clear we use IBH method

We need to think in hypothesis step what will be the method signature and we need to call our function on one unit less than current input

Int solve k, n

Int solve k - 1, ?

We need to think about the value of n for smaller input

If we observe the example

For given n it's n / 2 is same as k -1, n
And for it's n /2 to n it's is compliment of k -1, n

Steps to solve

1: find mid of current input row k
Mid = 2^n -1  / 2

2: if n <= mid return solve k - 1, n

3: if n > mid return compliment of solve k - 1, n - mid

Here we need good observation skills to figure out what value of k and n we need to call the function on smaller input

Problem : Tower of hanoi

Move n plates from source to destination pole using a single helper pole

Hypothesis: void solve(n, source, dest, helper)

Our function will move n plates from source pole to destination using helper pole

Let's run our function for a smaller input of size - 1 and figure out what work we need to do in induction

Void solve(n - 1, source, dest, helper)

Induction:

As our function will move n - 1 plates. We need to move the last bigger plate from source to destination 

** As we cannot keep bigger plate on smaller plate we need to move top n - 1 plates from source to help using destination 
Then move the biggest plate to destination from source
And then again move n - 1 plates from helper to destination using source

Base case: 
No of plate is equal to one
Just move the single plate from source to destination 

** If we are asked about the count of no of steps we pass a variable by reference in the solve method call and increment it with every function call. This variable will give us the count as with each function call we are performing a step

**************************************
Next all problems will be based on ip/op method i.e. by drawing recursive tree

List of problem in screen shot

Question: print all subsets of a string

Draw the recursive tree where each node contains ip/op at that stage

Solve(String ip, String op)

Initial call to solve function from main function will consist of initialising ip with the input string and op with empty string 

In recursive tree we get valid subset/answer in leaf node when ip String size becomes 0
This becomes our base case

We trim the ip and op string according to recursive tree and then call solve function twice as per the recursive tree diagram.

Question: print unique subsets

If we draw recursive tree of string aab we will have a listed twice

To solve this question we store all subset in a vector and then use a set to deduplicate the output

Variations ***************************

Subset == powerset

Substring : any contineous part of string is it's substring

Subsequence : any parts of string combined together is subsequence in same order as in original string

Subset: any parts of string combined in any order
Note : ab, bc are consider as same element in set any one is allowed.

When we are asked to print all subsequence of given string we write same subset code as our recursive solution gives only valid subsequences

If we need to print all subset element of subset in lexicographical order store all elements in vector and sort the vector

If deduplication is required then use set

**** So in a question if we are asked to print subset/powerset/subsequences then we write our same code. All are equivalent 

****************************************** part 4 ******************************

Question: permutation with space

Ip : abc

Op : abc, a bc, ab c, abc

It is recursive problem as we have to make a choice whether to include space or not

There is no choice at the beginning of the string to include space or not

There first choice is always fixed to take a first character as it is

Then we draw recursive tree in which we have two choices for each character to take it with space at beginning or not to include space

Draw recursive tree then implement the first fixed decision in main method itself 

And then implement the solve function with parameters of ip and op string

Code the recursive tree

Use

String s.push_back()
S.erase(s.begin())

Functions of cpp to implement code

Base condition is when input string becomes empty i.e. leaf node of recursive tree and at leaf node we get output

Question: permutation with case change

Ip: ab
Op : ab, Ab, aB, AB

Draw recursive tree as we have two choice to make whether to capatilize the char or not

Base case occurs when ip String becomes empty and we get op at leaf node

Cpp function to change case of character 
toupper(char), tolower(char)


Question: letter case permutation 
Ip: a1B
Op: a1B, A1B, a1b, ...... We need to change case of character in the input string one time to upper and second to lower

For digit we take as it's 

Recursive tree will now also contain node that will have only one child i.e. when the current input character is a digit
In that case we only call the function once

But is case of alphabet se call the method with modified ip and op twice which results in two child node

Isalpha(char) to check if it is a digit or a alphabet

Base case occurs when ip String becomes empty and at leaf node we get the output


Question: generate balanced paranthesis for given number n where is no of close and open brackets
If n = 2 we have (())  two open brackets and 2 closed brackets

Identification of recursive problem :
1: problem itself says that use recursion like sort a stack using recursion
2: from problem it is clear that it involves recursion like Nth symbol in grammar problem where grammer itself is defined recursively
3: Datastructure which involves recursion : trees
4: We are given choices to make

In this problem for n = 2. there are four places where we can place parenthesis and we need to make a choice. This is the identification that it will involve recursion

We cannot choose anything we need to choose wisely so that our decision will lead to balanced parenthesis

We need to use extended ip/op method as ip data type is not equal to output datatype.
input is a integer and output is a string

We can use ip/op method when input data type is equal to output datatype

we need two variables to keep track of opening and closing bracket

void solve(int no_opening_brackets, int no_closing_brackets, vector<string>& output) 

First draw recursive tree by evaluating whether a choice will be taken or not i.e. node will have a single child or multiple

******* Then observe the recursive tree to find condition that needs to be implemented so that the smae recusrive tree will be generated programatically

i.e. in current problem we note that we always take the choice of opening bracket all time till it does not becomes zero
Choice of closing bracket is sometime take sometimes not. 
Then by observation we see that when no_closing_bracket > no_opening_bracket then we have a choice of taking closing bracket
this is because when no of opening bracket is less means that there is always and ( bracket which can be closed

base condition occurs when we have exhausted all opening and closing bracket.

IMP steps : 
1: Draw recursive tree.
2: Observe recursive tree to find conditions that we implement to determine that will make a choice or not i.e. in current problem that condition is closing bracket count > opening bracket count

Question: print all binary string where in each string no of 1s is greater than no of 0s for every prefix

ip: N = 5
op: one possible output for N = 5 is 11010
Following are its prefix
11010
1101
110
11
1

in all of it prefix no of 1 is greater than no of zeros

Soln

We define two integers to represent no of 1s and no of 0s
N given in the input represent no of position in which we can place a 1 or a 0
for each position we have two choices of 1 and 0
As problem involves choices we use recursion to solve the problem

we start by drawing the recusrive tree
recursive tree will not be a complete binary tree but some node will only have one child.
Carefully  observing the tree we can see that for 1 we always have a choice i.e. we have a brach for 1
but for 0 sometimes we make a choice sometimes not

We need to comeup with a solid if condition to derive this recursive tree programatically.
By careful observation we see that we only have a choice of 0 when no of 1 is greater than 0
1 > 0. If no of 1 == no of 0 then also we dont make a choice of zero is it will make the prefix condition to fail.
 base condition occurs when output string becomes size == n or when n == 0 as with each recusrive call
 we increase count of either 0 or 1 by 1 and reduce n

 void solve(int no_ones, no_zeros, total_length)


Question : josephus problem

input n = no of people, K = kth person will be executed

output : index of the only person surviving 

This is a recursive problem as we need to follow the same steps on smaller input
i.e. kill a person at index i and then gain count k and kill the person at index K
will use an array to represent this problem and each array element will hold its initial index

Hypothesis : our function will return index of person surviving
int solve(vector<int> persons, int k, int index)

lets call our fun on smaller input
int solve (person - 1, k, index of person last executed)

inorder to reduce the input size we execute the person from the vector
from index = (index + (K - 1)) % vector.size()
we take k - 1 as we also count person at current index
we use modulo to bring index back to starting of vector when it croses the size of vector
Then the return value of the function call with smaller input will be our answer to original function call

Induction : there is nothing to do in induction as recursively calling the function for smaller input
i.e. after eliminating one element from array. does the necessary work.

base condition 
will be when vector size becomes zero. then we return the content of vector which will be index at starting position

