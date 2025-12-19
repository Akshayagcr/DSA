package e_twopointers;

/*
    https://leetcode.com/problems/trapping-rain-water/description/
*/
public class k_trapping_rain_water {

    /*
        Time complexity :- O(n), Space complexity :- O(n)
    */
    public static int trapV1(int[] arr) {
        int n = arr.length, result = 0, diff;
        int[] leftMax = new int[n];
        int[] rightMax = new int[n];
        for(int i = 1; i < n; i++){
            leftMax[i] = Math.max(leftMax[i - 1], arr[i - 1]);
        }
        for(int j = n - 2; j >= 0; j--){
            rightMax[j] = Math.max(rightMax[j + 1], arr[j + 1]);
        }
        for(int i = 0; i < n; i++){
            diff = Math.min(leftMax[i], rightMax[i]) - arr[i];
            if(diff > 0){
                result += diff;
            }
        }
        return result;
    }

    /*
        Most optimized solution:-
        Time complexity :- O(n), Space complexity :- O(1)
        To calculate water at any point we only need leftMax and rightMax not the entire array of leftMax and rightMax
        Math.min(leftMax[i], rightMax[i]) - arr[i]
        So we use two variables to keep track of left and right max and two pointers.
        Key :- How will move the pointers ?
            We move the pointer in the directing of the minimumValue(leftMax, rightMax)
            Why ? :- As water is bounded by lowest height, So if leftMax is minimum rightMax does not matter
    */
    public static int trap(int[] arr) {
        int left = 0, right = arr.length -1, result = 0;
        int leftMax = 0, rightMax = 0;
        while(left <= right){ 
            /*
                ******** We use <= in while condition because in each iteration of while loop we process one element either left or right.
                So to process the middle element when left == right we use <= or else if we used < then processing of middle element will be skipped
                *** Mental model to remember:-
                    1. If we are processing pairs use <
                    2. If we are processing single element use <= 
            */
            if(leftMax <= rightMax) {
                leftMax = Math.max(leftMax, arr[left]);
                result += leftMax - arr[left];
                left++;
            } else {
                rightMax = Math.max(rightMax, arr[right]);
                result += rightMax - arr[right];
                right--;
            }
        }
        return result;
    }

}
