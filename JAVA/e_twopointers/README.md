A two-pointer pattern refers to an algorithm that utilizes two pointers. A pointer is a variable that represents an index or position within a data structure, like an array or linked list.

Situation in which two pointers can be applied
1. Liner data structure like array, linked-list and string
2. Instead of a single element question involves pair, ranges and sub-arrays
3. Predictable dynamics : Generally in brute force approach of question containing pairs involves two nested loop
for checking every possible combination, resulting in O(n^2) complexity i.e.
for(int i = 0; i < arr.length;i++){
    for(int j = i + 1; j < arr.length; j++){
        compare(arr[i], arr[j])
    }
}
But question involving two pointers a predictable dynamics will be given like sorted array, or palindromic string will be involved which makes moving the pointer in logical way possible
resulting in reduced space and time complexity

Types of two pointer problem:-

1. Pointers moving towards each other
    1. Is valid palindrome
    2. pair sum - sorted
    3. three sum
    4. four sum
    5. Container with most water
    6. Rainwater trapping
    7. Next Permutation
2. Pointers start at same place i.e. beginning. and move in same direction. A common application of this is when we want one pointer to find information (usually the right pointer) and another to keep track of information (usually the left pointer).
    1. Shift zeros to end
3. Two independent pointers pointing to two different arrays and moving according to given condition.
4. Fast and slow pointer (Specific variant of 2 pointer approach)
5. Sliding window(Specific variant of 2 pointer approach)

Ref:
1. https://leetcode.com/discuss/post/1688903/solved-all-two-pointers-problems-in-100-z56cn/
2. https://leetcode.com/discuss/post/1905453/master-in-two-pointer-by-rakibhasan1030-ku1j/
3. https://bytebytego.com/courses/coding-patterns/two-pointers/introduction-to-two-pointers?fpr=javarevisited
4. https://neetcode.io/roadmap
5. https://www.geeksforgeeks.org/dsa/top-problems-on-two-pointers-technique-for-interviews/


Learnings :-

1. Pointers start at same place:- Need to apply same partitioning logic as in quick sort. i.e. one pointer maintains the partition and other pointer scans the array

a_remove_element
b_move_zeros_to_end
c_remove_duplicate
e_sort_zero_one_two *** Special case, we use three pointers

2. Pointers moving towards each other
d_reverse_with_space_intact
z_sentence_palindrome

3. Identification : Linear data-structure will be involved. And main thinking factor will be how to move pointers 
i.e. in container with maximum water we move pointer which is having smaller height and in trapping rain water we move in direction which is having lower value of leftMax and rightMax.

4. When question will involve pair of element like two-sum use "<" condition in while loop and in question where we process
individual element like trapping rain-water use "<=" condition.