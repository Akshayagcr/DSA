*** If there is sorted keyword in question then the question will surely involve binary search

Question: binary search on sorted array

We use below formula to calculate mid as it prevents from overflow
Mid = start + (end - start)/2 

If we just use Mid = (start + end)/2 
It will cause overflow for large value of start and end

Question : binary search on reverse sorted array

Question: bs on order agnostic sorted array

In this question array will be sorted But it will not be provided if array is sorted in ascending or descending 

Question: find first and last occurrence of an element in a sorted array

Once we find the element at the mid we continue our search using binary search on first half if we need to find first occurrence and search in second half if we need to find last occurrence
We use a variable to store the currently found index and continue search by updating just start and end. Search will eventually end like element is not found i.e. start > end
** We don't use linear search after finding element as it can lead to O(n) complexity i.e. in case if array contains a large number of elements but all values are same.

Question: count of an element in a sorted array

Count = index of last occurrence - index of first occurrence+ 1

Question: Number of time an sorted array is rotated

An sorted array is rotated by moving elements from **right side to left side of an array

Number of time array is rotated is equal to index of first element 

We need to address two concerns in this problem 

1: we need to way to quickly identify that the mid element we get by applying bs is the minimum element of the array
2: if mid is not equal to minimum element then how will navigate 

1: we can find an element is minimum by checking if the element is less than its neighboring element 
While checking also keep range of array in mind i.e. element may be the first element then how will check it's neighboring element 

• Previous ele index = (mid + N - 1) % N
• next ele index = (mid + 1) % N


2: when mid split the array it will be split into two sorted and un sorted part our ans i.e. smallest element will always lie in unsorted part

We can find if the array is sorted or not by comparing mid with start and end
In sorted array mid will be greater than start

Question: find an element in a rotated sorted array 

We use solution in previous question to find index of minimum element and then apply bs on two sorted array

Question: Searching in nearly sorted array

In nearly sorted array an element can be at position i - 1, i , i + 1 where i is is original position in sorted array
We need to modify BS to search in nearly sorted array. everything will be same now instead of just comparing element to be searched
with mid we will compare it with mid -1, mid, mid + 1 if not found search in right or left sub array by updating start and end with
mid +- 2. We also need to take care while doing mid + 1, mid - 1 that we are not going out of bound.

Question : Find floor of element in a sorted array

Floor of an element : Element which is equal to or the greatest element smaller than the given element
So all element smaller than the element are its possible candidate when the element itself is not present
we just need to save the candidates in a variable
 i.e. when arr[mid] < x store index/element in result
 This result will again updated when we move right.

Question : Find ceil of element in a sorted array

Ceil : element which is equal to or smallest element greater than the given element
All element which are greater than the given element are candidate for ceil so whenever arr[mid] > ele we store the index in result
and move to left. The flow of BS when moving towards left will gives us the ceil of the element

Question : Next alphabetic element

It is similar to finding ceil element in sense that all element  greater than input character are candidate of next alphabetic element
we store the the possible candidate in a variable when arr[mid] > ele.
Only change will be when we find an exact match of input character in that case we can't stop the search we need to continue search by doing start = mid + 1

Question : Find position of an element in a infinite sorted array

** This is an interview question as in practical we cannot create an infinite array
Main problem is to find the high index in an infinite array. We can solve this by applying a strategy to increase high index
depending on the key to be searched
i.e. we start with low = 0, high = 1 and apply a loop while arr[high] < key, we move high = high * 2 and move low = high
once the key is bounded we apply bs on that range

Question : Find index of first 1 in a infinite binary sorted array

It is a combination of two questions 1: first occurrence of an element ans position of an element in a infinite sorted element
We find low and high index similar to finding element in sorted array
once found we apply bs on that index once an element is found we don't return but store the index in an variable and 
move left in search of first occurrence

Question: minimum difference element in a sorted array 

We are given a key and sorted array in input we need to return an element for the array whose absolute difference will be the minimum with the given key

Apply bs if the element is present return it, if not present then low and high will point to its neighbors in sorted array i.e. higher and lower

Concept : Binary search on answer 

In some questions we will be given unsorted array but in those we will be able to apply binary search not directly but indirectly, we will be able to form some criteria to check if middle element is the answer or not by verifying the criteria and able to move to right or left based on criteria 

Question: peak element  

Given an unsorted array we have to find peak element. A peak element is an element which is greater than its neighboring elements. In case of first and last element in an array it should be greater than its neighboring one element. There can be multiple peak element in an array.
This is a question on binary search on answer
Will apply usual binary search and find mid. To check if mid is our answer compare it with its neighbors it should be greater.
To move left and right if mid is not peak we move to the more promising side of array i.e. where it's neighbor is greater than mid
*** Verify if this approach covers all cases. As there is a chance of missing peak element 

Question: find maximum element in a bitonic array

bitonic array is an array formed by combining monotonically increasing and decreasing array
Monotonically increasing/decreasing array is an array in which neighboring element always increases/decrease but will never be equal 
An bitonic array will always have a single peak and this question is similar to above question of finding peak element 

Question: search element in a bitonic array 

We will use peak element bs to find peak element and then apply normal bs on both arrays divided by peak element 

Question : Search a element in a row and column wise sorted matrix

We start from top right corner and check if element is greater than or less than the key, If it is greater than the current element we 
move to left i.e. j-- as all element in the current column will be greater then current element as it is sorted.
If the current element is less than the key we move i++. if an element is not present we will go out of bound.

i,j = top right corner
While(Not out of bound){
    if current ele == key
        return i, j
    else if current ele > key
        j--
    else
        i++
}
return -1


Question: allocate pages of book

We are given a array and integer k where k represents no of students and we need to return an integer which represents minimum no of pages each student needs to read

Each array element represents a book and value represents no of pages in the book

Every student should be get at least one book

Conditions: 
Condition 1: As every student will get one book the initial lower limit will be the book with maximum pages. And higher limit will be total pages in all book

Condition 2: book should be distributed in continuous manner i.e. we cannot pick a book from between

Problem is to minimize the number of maximum pages each student has to read

The given array can be unsorted 

***** Looking directly at question at first time no one will be able to figure it out that it's problem of bs. We have to do atl east one question of this type to recognize that question will involve bs.

We apply bs on low and high to find mid which represents one candidate of answer i.e. minimum no of pages k students can read

We write a isValid(are, current mid, noStudents) which tells us whether the current mid is a possible and or not

If not then we move to right to increase capacity. I.e. low = mid + 1

If yes then we try to optimize by moving high = mid - 1 and before doing well store it in a result variable

Eventually low will become greater than high and will come out of loop

IsValid function we just need to create a variable name noStudents initialize with zero. Loop over the array and accumulate and whenever sum becomes greater than estimated no of minimum pages increase noStudents variable 
And then check if schema is valid for the given no of students in the question or not


In different variations of this question there will be minor changes in isValid function.

******* Most imp question of bs 
