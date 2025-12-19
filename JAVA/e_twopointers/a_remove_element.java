package e_twopointers;

/*
    https://leetcode.com/problems/remove-element/description/
*/
public class a_remove_element {
    
    public int removeElement(int[] nums, int val) {
        int i = -1, temp;
        for(int j = 0; j < nums.length; j++){
            if(nums[j] != val){
                i++;
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        return i + 1;
    }

}
