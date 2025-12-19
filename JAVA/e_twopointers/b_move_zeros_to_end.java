package e_twopointers;

/*
    https://leetcode.com/problems/move-zeroes/
*/
public class b_move_zeros_to_end {
    
    public void moveZeroes(int[] arr) {
        int i = -1, temp;
        for(int j = 0; j < arr.length; j++){
            if(arr[j] != 0){
                i++;
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

}
