package e_twopointers;

import java.util.*;

/*
    https://leetcode.com/problems/3sum/description/

    *** Key in this question is how we avoid duplicate, using two sum approach is just a small part !!!!!!!!!!!
    If we sort the input array all duplicate will be adjacent to each other. 
    and we can skip them so that will always get the unique triplet.
    *** Also when we find the triplet we need to avoid duplicate
*/
public class g_three_sum {

    static Scanner sc = new Scanner(System.in);
    
    public static List<List<Integer>> threeSum(int[] arr) {
        List<List<Integer>> res = new ArrayList<>();

        Arrays.sort(arr);

        int j, k, sum;
        for(int i = 0; i < arr.length; i++){

            if(i == 0 || arr[i - 1] != arr[i]){

                j = i + 1; k = arr.length - 1;
                while(j < k){
                    sum = arr[i] + arr[j] + arr[k];
                    if(sum == 0){
                        res.add(List.of(arr[i], arr[j], arr[k]));
                        j++; k--;
                        while(j < k && arr[j - 1] == arr[j]){
                            j++;
                        }
                    } else if(sum < 0){
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

        System.out.println(threeSum(arr));
    }

}
