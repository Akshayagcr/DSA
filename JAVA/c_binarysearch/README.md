Monotonic functions :- function which maintains a given order
*** Binary search can be applied to any monotonic function 
Example of monotonic functions:- 
1. Array sorted in ascending or descending order
2. x^2
3. Predicate function:- a function which returns false initially and once it return true it always returns true for all increasing values. Vice versa

Finding an element in a sorted array is one of the specific case in which we can apply binary search 

******** The search space should be monotonic to apply binary search

We can find nth root of number using binary search !!!!! Instead of just comparing with the middle element we check for eg for square root as mid * mid == target

Question : ECO - eco - SPOJ

Generally questions related with BS will involve creating monotonic predicate function and applying BS using that function

Predicate function :- function which returns true/false
We apply binary search on monotonic predicate function
there are only two types of monotonic predicate functions
1. TTTTFFF   i.e. they start with true and after boundary point only return false
2. FFFFTTT   i.e. they start with false and after boundary point only return true

We need to find/derive a monotonic predicate function that according to the given question
Using binary search and variation of upper/lower bound we can find the boundary boolean value either on left/right

Question : AGGRCOW - SPOJ

We start by thinking about a monotonic predicate function i.e. our function will take distance as input we start with minimum distance as 0 and try to place cow at the stalls and keep on increasing the distance to get maximum distance. After a maximum distance is reached there will not be possible to place the cows at the stalls.

Then we apply binary search on search space of distance equal to 1 to maximum and move according to the requirement i.e. we want to find first true as the below will be the output of our monotonic predicate function 

TTTTTTTTTTFFFFFFFFFFFF

***************************************************************************************
Ericto :

Should use below formula to calculate mid
Mid 
= left + distance/2 
= left + (right - left)/2

We can use binary search to find if a given number is a perfect square root or not

Lower bound : element greater than or equal to input element 

Hacky approach:- use normal binary search and then check it's adjacent element. Disadvantage of this approach is that we need to check whether we are going out of bound or not and it will not work for other use case therefore we need some generic approach

Generic approach : use a temporary variable and whenever we find a possible candidate just update the temporary variable.

**** In binary search problem we can partition the input into two parts i.e. true and false and we generally try to find the boundary by moving to either left or right and while moving we store the probable candidate in a temporary variable.
**** Thinking in terms of true and false and then what condition to apply to realize it and find boundary helps 


Question: Rotated sorted array: think in terms of true and false
Question: Peak of element: think in terms of true and false
Question: Find square root of a number

********************************************************************************************************

Learnings :-
1. Carefully think about the low & high values i.e. search space
2. Draw the expected predicate function output and decide the direction to move carefully.
3. ****** Most IMP !!!!!!!! - Implementation of predicate function 