package c_binarysearch;

/*
    https://www.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1
*/
public class g_find_peak_element {
    
    /*
        0 1 2 3 4 5 6
        
        1 2 4 5 7 8 3
        T T T T T T F

        10 20 30 40 50
        T  T  T  T  T

        120 100 80 20 0
        T   F   F  F  F
    */
    public int findMaximum(int[] arr) {
        int low = 0, high = arr.length - 1, mid, pos = -1;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(mid == 0 || arr[mid] > arr[mid - 1]){
                pos = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return arr[pos];
    }

}
