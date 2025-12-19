Stack question identification
1. Question will contain array and brute force approach will result in nested loop (n^2)
2. Nested loop in brute force will depend on each other i.e. j = fn(i) inner loop will depend on outer loop. 

Stack questions

1. Nearest greater to right.
2. Nearest Greater to left.
3. Nearest smaller to right.
4. Nearest smaller to left.
    for all of the above problem if we need to scan right sub array we iterate right to left else we iterate 
    from left to right.
    We use stack to keep track of left and right sub array
    initialize the output array with -1
    then start iterating the implement a while loop which pops elements from stack 
        if stk.top is greater when finding smallest element
        if stk.top is less when finding greatest element
    then check if stk is empty or not
        if empty output = stk.top
    push the current element in stack for analysis.

5. Stock span problem.
    We store index of NGL in output array.
6. Maximum area of histogram.
    We find NSL and NSR index array and find width and then use that width to find area by multiplying it with height i.e input
7. Maximum area in a binary matrix.
    Convert 2d array to 1d array i.e find maximum area of histogram of all 1d array in the 2d array.
8. Rain water trapping.
        In this problem we need to find min of greatest element in left and right sub-array not the NGL or NGR
9. Min stack using additional space.
    We use an additional stack to store the current minimum element.
10. Min stack with O(1) additional space.
    We use only one variable to store minimum element by store 2*ele - minimum element in stack 
    when a element smaller than minimum is encountered and this works like a flag i.e. when we again encounter it
    will find that it is less than current minimum which me we need to return the current minimum 
    and restore the previous minimum element by 2 * min element - ele
