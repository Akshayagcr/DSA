package e_twopointers;

import java.util.*;

/*
    https://leetcode.com/problems/4sum/description/
*/
public class i_four_sum {

    static Scanner sc = new Scanner(System.in);
    
    public static List<List<Integer>> fourSum(int[] arr, int target) {
        Arrays.sort(arr);
        List<List<Integer>> res = new ArrayList<>();
        long targetTwo;
        for(int i = 0; i < arr.length; i++){
            if(i == 0 || arr[i - 1] != arr[i]){
                targetTwo = 0L + target - arr[i];
                List<List<Integer>> tripletList = findTriplet(arr, i + 1, targetTwo);
                for(List<Integer> triplet: tripletList){
                    res.add(List.of(arr[i], triplet.get(0), triplet.get(1), triplet.get(2)));
                }
            }
        }

        return res;
    }

    public static List<List<Integer>> findTriplet(int[] arr, int start, long target) {
        List<List<Integer>> res = new ArrayList<>();
        int j , k;
        long targetTwo, sum;
        for(int i = start; i < arr.length; i++){
            if(i == start || arr[i - 1] != arr[i]){
                targetTwo = 0L + target - arr[i];
                j = i + 1; k = arr.length - 1;
                while(j < k){
                    sum = 0L + arr[j] + arr[k];
                    if(sum == targetTwo){
                        res.add(List.of(arr[i], arr[j], arr[k]));
                        j++; k--;
                        while(j < k && arr[j - 1] == arr[j]){
                            j++;
                        }
                    } else if(sum < targetTwo){
                        j++;
                    } else {
                        k--;
                    }
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }
        int target = sc.nextInt();
        System.out.println(fourSum(arr, target));
    }

}
