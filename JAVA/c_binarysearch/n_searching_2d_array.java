package c_binarysearch;

/*
    https://leetcode.com/problems/search-a-2d-matrix/description/
*/
public class n_searching_2d_array {
    
    public boolean searchMatrix(int[][] matrix, int target) {
        int row = matrix.length, column = matrix[0].length;
        int low = 0, high = (row * column) - 1, mid, midEle;
        while(low <= high){
            mid = low + (high - low) / 2;
            midEle = matrix[mid/column][mid%column];
            if(midEle == target){
                return true;
            }
            if(midEle < target){
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }

}
