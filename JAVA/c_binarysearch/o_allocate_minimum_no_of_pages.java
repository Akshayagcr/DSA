package c_binarysearch;

/*
    https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
*/
public class o_allocate_minimum_no_of_pages {

    boolean predicateFn(int minimumPages, int[] arr, int k){
        int count = 1, sum = 0;
        for(int ele : arr){
            sum += ele;
            if(sum > minimumPages) {
                count++;
                sum = ele;
            }
            if(count > k){
                return false;
            }
        }
        return true;
    }
    
    public int findPages(int[] arr, int k) {
        if(k > arr.length){
            return -1;
        }
        int low = arr[0], high = 0, mid, ans = -1;
        for(int i = 0; i < arr.length; i++){
            high += arr[i];
            if(arr[i] > low){
                low = arr[i];
            }
        }
        while(low <= high){
            mid = low + (high - low) / 2;
            /*
                F F F F F T T T T T
            */
            if(predicateFn(mid, arr, k)){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    
}
