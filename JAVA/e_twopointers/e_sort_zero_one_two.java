package e_twopointers;

/*
    https://leetcode.com/problems/sort-colors/
    https://www.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

    Working:- 
    We use three pointers i, j, k 
    where 0 to i keeps sub-array consisting 0
    i + 1 to j keeps sub-array consisting 1
    k to n - 1 keeps sub-array consisting 2
    sub-array of 1 grows from left to right uses same partition logic as quicksort
    sub-array of 2 grows from right to left and there is one edge case which need to be consider
    when swapping the value of k can be 0, 1 or 2 therefore we don't move j pointer to next index.


*/
public class e_sort_zero_one_two {
    
    static void swap(int[] arr, int i, int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public void sortColors(int[] arr) {
        int i = -1, j = 0, k = arr.length;
        while(j < k){
            if(arr[j] == 0){
                i++;
                swap(arr, i, j);
            }
            if(arr[j] == 2){
                k--;
                swap(arr, j, k);
                j--; // This is the edge case we need to keep in mind. decrementing and incrementing keeps j on same index to process the swapped element.
            }
            j++;
        }
    }

}
