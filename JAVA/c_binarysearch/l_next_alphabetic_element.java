package c_binarysearch;

/*
    https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
*/
public class l_next_alphabetic_element {
    
    public char nextGreatestLetter(char[] letters, char target) {
        int low = 0, high = letters.length - 1, mid, pos = 0;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(letters[mid] > target){
                pos = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return letters[pos];
    }
}
