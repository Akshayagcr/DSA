package f_slidingwindow;

import java.util.*;

/*
    https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
*/
public class b_first_negative_integer_window_size_k {
    
    static List<Integer> firstNegInt(int arr[], int k) {
        List<Integer> res = new ArrayList<>();
        Deque<Integer> deque = new ArrayDeque<>();
        int low = 0, high = 0;
        while(high < arr.length){
            if(arr[high] < 0){
                deque.offerLast(arr[high]);
            }
            if(high - low + 1 < k){
                high++;
            } else {
                if(!deque.isEmpty()){
                    res.add(deque.peekFirst());
                } else {
                    res.add(0);
                }
                if(!deque.isEmpty() && arr[low] == deque.peekFirst()){
                    deque.pollFirst();
                }
                low++; high++;
            }
        }
        return res;
    }
}
