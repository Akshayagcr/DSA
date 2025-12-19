package e_twopointers;

import java.util.Scanner;

/*
    https://leetcode.com/problems/container-with-most-water/description/

    As area is calculated as following area = Width * height
    area = (high - low) * Math.min(arr[low], arr[high])
    So area is bounded by lowest height. in-order to increase area we move
    pointer which is pointing to lowest height in search of a height which will be greater than current smallest
    Width is fixed i.e. it will always be decreasing as we are moving pointers inwards.

    Key summary:
        The area is limited by the shorter height, not the taller one.
        So:
            If you keep the shorter height → area is capped
            If you discard the shorter height → you might find a taller one
*/
public class j_container_with_most_water {
    
    static Scanner sc = new Scanner(System.in);

    public static int maxArea(int[] arr) {
        int low = 0, high = arr.length - 1, currentArea, maxArea = 0;
        while(low < high){
            currentArea = (high - low) * Math.min(arr[low], arr[high]);
            if(currentArea > maxArea){
                maxArea = currentArea;
            }
            if(arr[low] < arr[high]){
                low++;
            } else {
                high--;
            }
        }
        return maxArea;
    }

    public static void main(String[] args) {
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println(maxArea(arr));
    }

}
