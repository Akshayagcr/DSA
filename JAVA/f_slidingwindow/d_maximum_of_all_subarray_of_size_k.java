package f_slidingwindow;

import java.util.*;

/*
    https://leetcode.com/problems/sliding-window-maximum/
*/
public class d_maximum_of_all_subarray_of_size_k {
    
    /*
        Initial accepted solution.
        Better solution uses queue.
    */
    public int[] maxSlidingWindow(int[] arr, int k) {
        List<Integer> list = new ArrayList<>();
        TreeMap<Integer, Integer> m = new TreeMap<>();
        int low = 0, high = 0, highEle, lowEle;

        while(high < arr.length){
            
            highEle = arr[high];
            if(m.containsKey(highEle)){
                m.put(highEle, m.get(highEle) + 1);
            } else {
                m.put(highEle, 1);
            }

            if (high - low + 1 < k) {
                high++;
            } else {

                list.add(m.lastEntry().getKey());

                lowEle = arr[low];
                if(m.containsKey(lowEle)){
                    if(m.get(lowEle) == 1){
                        m.remove(lowEle);
                    } else {
                        m.put(lowEle, m.get(lowEle) - 1);
                    }
                }

                low++; high++;
            }
        }
        return list.stream()
        .mapToInt(Integer::intValue)
        .toArray();
    }

    /*
        Efficient approach using Deque
    */
    public int[] maxSlidingWindowV2(int[] arr, int k) {
        List<Integer> list = new ArrayList<>();
        Deque<Integer> q = new ArrayDeque<>();
        int low = 0, high = 0, highEle;

        while(high < arr.length){
            
            highEle = arr[high];

            if(q.isEmpty()){
                q.addLast(highEle);
            } else {
                while(!q.isEmpty() && q.getLast() < highEle){
                    q.removeLast();
                }
                q.addLast(highEle);
            }

            if (high - low + 1 < k) {
                high++;
            } else {

                list.add(q.getFirst());

                if(q.getFirst() == arr[low]){
                    q.removeFirst();
                }

                low++; high++;
            }
        }
        return list.stream()
        .mapToInt(Integer::intValue)
        .toArray();
    }

}
