package c_binarysearch;

/*
    https://www.geeksforgeeks.org/problems/search-in-an-almost-sorted-array/1
*/
public class k_searching_nearly_sorted_array {
    
    public int findTarget(int arr[], int target) {
        int low = 0, high = arr.length - 1, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(arr[mid] == target){
                return mid;
            }
            if(mid - 1 >= 0 && arr[mid - 1] == target){
                return mid - 1;
            }
            if(mid + 1 <= arr.length - 1 && arr[mid + 1] == target){
                return mid + 1;
            }
            if(arr[mid] > target){
                high = mid - 2;
            } else {
                low = mid + 2;
            }
        }
        return -1;
    }
}
