We use recursion when we need to make choices and decisions 
Recursion = choices + decision 

Child of recursion 
1: Dp
2: back tracking 
3: divide and conquer 

If dp is recursion + storage then
Back tracking is recursion + control 

In dp we are generally asked optimum values
In back tracking we are generally asked about combinations 

In recursion we get answer at leaf node

In dp we get answer at root node i.e. child of root represents sub problems which we solve to get answer, which represents root

In back tracking answer is a particular path from root to leaf

As mentioned back tracking = controlled recursion + pass by reference 

Controlled recursion: 
In backtracking problems there will be n number of choices but some of the choices will not make sense so we exclude those choices by applying a simple if condition 

Eg: we are given 4 steps and our home is located in south east.

As in the problem it is mentioned house is located in south east we will not take any step in nort and east direction as it will not lead us to destination so we omit those choices

Pass by reference:
When we pass by reference a variable if it's value is changed it also get reflected in parent function. In back tracking we pass value by reference to child call. So that child can modify it.
If the value modify does not lead us to solution when the recursion comes back to parent call we backtrack by again changing the value back to its original state as it was before function call of child

If we pass variable by value and omit backtracking step then will get recursive version of the same code which works

Identification of backtracking problems :

1: choices and decisions 

2: All combinations 
Eg all path, all solved suduko boards

3: controlled recursion 

4: No of choices
Generally in recursion every node will have two child i.e. two choices. But in back tracking no of choices will be very large and can also be variable i.e sometime 5 or sometimes 7

5: Size of constraints 
If a constrain is like 1 <= n <= 10 i.e. a smaller constrain then problem will be backtracking as generally the complexity of DP problems will be exponential 

6: Don't be greedy

Sometimes applying greedy method work for some backtracking problems like

Form largest number in k swaps
Eg: 1234 k= 2
Op= 4312

Applying greedy method works only if digits are distinct. If number contains duplicate digits then greedy method fails
Eg : 4577 k=2
Op= 7745  
But largest number which can be formed 7754

So if in this question if duplicate are present then we need to apply back tracking 

So always think about counter example when applying greedy method 
Check constrain as there will be a huge difference between constant of greedy and back tracking problem. 

Back tracking problem can be solved using recursion. But when we apply recursion to Back tracking problem then will get a fell that it has become very complex 

General backtracking solution format

1: As back tracking is the child of recursion there will be a base case condition
Generally the base case of backtracking problems are complex therefore we create a seprate method for it

2: no of choices in BT problems is more we generally use a loop to make recursive call for all choices

3: controlled recursion, before making a choice we eveluate whether a choice will lead us to result or not

4: pass varibles by reference

5: modify the input values and call the recursive function again and then again revert the change back after function call
(Back tracking step)

void solve(&ipVar, other variables....){     // variables passed by reference

    if(baseCaseFunction()){
        print/save
    }

    for(choice in choices){
        if(controlled recursion condition){

            ipVar + change

            solve(ipVar)

            ipVar - change // back tracking step

        }
    }
}

Question: return all unique permutation of a string

Ip: aab
Op : aab, aba, baa

Recursive approach :

We start with ip/op method to draw recursive tree for a input string of length n we have n different places to put char.

In normal recursive question the no of choices  is usually fixed i.e two choices/two branches for each node but in this question it is variable and equal to size of input string
As for first position we have n choices for ip String of length n.

We use a for loop to generate all choices

If there are duplicate char in input string then with straight forward recursive approach will generate duplicates. 

There are two ways to deal with this use recursive approach and then deduplicate using set. Or prune the branch/choice which leads to generation of duplicate by creating a set and checking whether a choice was made previous or not this method of pruning reduces the amount of work done as it eliminates the entire computation of a sub tree which was already computed.

Base case : when ip size becomes zero i.e. leaf contains the answer

Currently in recursion method we are passing the ip/op by values. If we pass by reference then it will be converted into backtracking 

** Time complexity of a recursive problem 

To calculate time complexity of a recursive problem we need analyse the recursive tree 

Total work done = work done at each node * total no of node

Eg : for a complete binary tree total number of node is
1st level 1 node
2nd level 2 node
3rd level 4 node
For nth node it's 2^n nodes

For the permutation of string it recursive tree for input string abc consist of 

1 node at level 1
3 node at level 2
Each 3 node has 2 child 
Each child further has 1 child

So total no of node = 1 + n + n(n -1) + n(n-1)(n-2) + n(n-1)(n-2)...1

= 1 + 3 + ..... + N!
Total nodes is equivalent to n!. As the dominating factor in above equation = N!


Work done per will be equal to n^2. As there are 2 nested loop 
One loop for iterating over choices
Second is the substring method which is used to remove the middle char from the string

So total time complexity = O(n^2 * n!)


Backtracking approach for permutation of string

All things will be same the loop for choices, if condition for checking if a choice was already made or not only difference is that now we will pass the variables by reference instead of value

But why ?
Because pass by reference is more intuitive 
Think of it will real life example suppose we need to arrange three people with different color shirt in three positions. We will ask them to swap position among themself rather than asking other three people make them wear the shirts and then arrange them in new positions.

So now in our function becomes
Fn(string& s, int start, vector<string>& result)

We loop from start position to string size and swap.
Before swapping we check whether the choice of swap was already taken or not

• As now we are passing the variable by reference it changes the original variable so we have to again swap back to return string to original state. This is the backtracking step

Question: largest no in k swaps

Greedy approach : Swap the largest digit with initial digits of the given number.
This approach will work when the number contains unique digits. If number contains duplicate digits then this approach fails.

For loop for choices : we need to loop over every digit in the number to try swaping 

Prune the choices : we will not involve recursive for every choice. We only need to go further and swap digits which are not equal and greatest among rest of the choices.

In this problem we can get answer at any node of the tree. As we have at most k swaps but ans can be derived from less than k swaps also. So we need to generate a recursive tree of height == k and check in every function call if the current input is the largest or not.

**** Horizontal drift of the input : 
For a given start index it is possible that every branch get prune in the if condition so we need to move start to next digit in the input. 

In base case there will be two conditions k == 0 given no of swaps have been used or when start index has reached end of the given number

Question: N digit numbers with digits in increasing order

We will be given an integer n and we have to return an array of strings where each string has size n and every digit in the string is in increasing order.

Our recursive function represents a node in the recursive tree. So design the function which properly represents a recursive node.

Backtracking problems will have following structure

1: base case
When n becomes zero i.e. when we have eveluates choices for all positions we end recursion 
(In base condition we need to convert the vector<int> to an integer)

2: loop for choices 
For each position we have choices from 1 to 9

3: if condition to prune choices
As we only need number with digits in increasing order we can check the current last digit and take a choice only when digit is greater

Void solve(int n, vector<int>& number)

We have modeled the number as a vector as we need to check the last digit and also need to append the choice at the end

For each choice we append the digit and call our recursive function and then we again remove the last digit which we appended as backtracking step as we need to make place for the next choice

Time complexity is 9^n as we have 9 choices for n digits

Time complexity of recursive tree = total number of nodes * work done at single node


Question : Rat in maze

We are given an n * n matrix where the rat is placed at top left corner of matrix and exit is at bottom right corner of the matrix. matrix is a binary matrix where 0 represents the blocked cells and cell with 1 are the cells through which mouse can search path. we need to return all possible path from start to exit.

Choices : 
Rat has four choices i.e. go up, down, left, right

prune :
Althrough there are four choices but not all four choices will be valid, we will pruen choices with following conditions
1: If a cell is blocked
2: If taking a choice moves the mouse out of matrix i.e. out of bound
3: ** Already visited cells i.e. we should avoid moving in loop by not taking a choice which will move mouse to already visited cell

Base case :
1: When mouse has reached bottom right corner i.e. exit
2: there is no path to exit i.e. every neardy cells are visited

for choices we create an struct

struct choice{
    char directionName;
    int dx, dy;
}

vector<choice> = {{u, 1, 0}, {d, -1, 0}, ....};

we can represent visited cell and a blocked same in same way by making a cell which we visited as blocked i.e. by setting it as 0

Time complexity = number of nodes * work done at a node

number of node = 3 ^ total number cells -----(ideally we have 4 choices but if we think the one choice will always be pruned i.e. from where the mouse came initially)
= 3 ^ n ^ 2

work done at each node = O(1)

Time complexity = O(3 ^ n ^ 2)



******* Continue studying other problems of back tracking