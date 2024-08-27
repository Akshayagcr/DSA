Identification:
Take example of finding diameter of a tree problem, in this problem we need to find the longest path between any two leaf node. The path is not guaranteed to travel through root

For this problem we need to visit every node and then calculate the height of its left and right tree + 1 gives the length of longest path between two leaf

In such questions where we need to visit every node and on every node we need to perform an operation that is of O(n)

Then in such questions we need to apply dp to avoid doing repetitive work.

General syntax of solving dp on trees problem:

There will be an result variable passed by reference in all of the function 

Base case : in most problem it will be if input pointer is null in that case return 0

Will recursively call same function on left and right sub tree obtain the ans and calculate the temporary answer

We apply some function that depends on the problem to calculate temporary answers i.e. answer when the current node can be consider as possible candidate of answer

And we also apply function between the result variable that is passed and temp answer to calculate result

We return temporary answer


Question: diameter of a binary tree 

Number of nodes between longest path between two leaf nodes

Base case : when input root pointer is null return 0

Hypothesis: 
We make two recursive call to get height of leaft and right subtree

Induction :

for a given node x there are two choices
1: The longest path goes through current node as root
2: The longest path goes through other node as root

Below step calculates heigh considering that longes path will go through other node as root as per 2nd condition
Temp = max(left subtree height, right subtree height) + 1

Below steps determines which choice will result in longest path from condition 1 and 2
Ans = max(temp, 1 + left + right subtree height)
Result = max(result, ans)

we return temp considering the longest path will go through other node as per condition 2 and further steps will require
the temp answer
Return temp

Question: Maximum path sum from any node to any node

We are given an binary tree in which node have an integer value i.e. value can be +ve or -ve. we need to return maximum sum
which can be achived along a path

In all dp on tree problems format discussed aerlier will be applied
only 
temp and ans calculation will be different

Given a node x it have two choices
1: It is included as root node in a path with maximum sum
2: other node is invloved as root in a path with maximum sum

We calculate temp value as per 2nd condition
temp = max( max(left subtree sum, right subtree sum) + current node sum, current node sum)
we apply max it it might be possible that both left or right subtree contains an negative integer and they both
my return negative value than its current value

so we have included a max condition which returns the best possible maximum value either from left/right subtree
or its value itself.

We calculate ans as if current node will be the root along the path with maxmimum sum

ans = max(temp, left subtree sum + right subteee sum + current node value)

then we return temp

Question: maximum path sum from leaf to leaf

Only difference between this question and above question is change in heow we calculate temp variable
previously if a nodes left or right sub tree returned a negative value we can omit that value and only consider current
nodes value. now we dont have that previledge

so temp = max(left subtree sum, right subtree sum) + current node sum

rest everythig will be same

