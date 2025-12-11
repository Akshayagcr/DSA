package c_binarysearch;

/*
    https://leetcode.com/problems/find-peak-element/description/
*/
public class m_peak_element {
    
    /*
        3 4 5 6 7 8 9 10 2
        0 1 2 3 4 5 6 7  8

        5 4 3 2 1
        0 1 2 3 4

        5 6 7 8 9
        0 1 2 3 4 
    */
    public int findPeakElement(int[] arr) {
        if(arr.length == 1){
            return 0;
        }
        int low = 0, high = arr.length - 1, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if((mid == 0 && arr[0] > arr[1]) 
                || (mid == arr.length - 1 && arr[mid] > arr[mid - 1]) 
                || (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])){
                    return mid;
            }
            if(arr[mid + 1] > arr[mid]){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

}
