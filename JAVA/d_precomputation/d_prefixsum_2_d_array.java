package d_precomputation;

/*
    https://leetcode.com/problems/range-sum-query-2d-immutable/
*/
public class d_prefixsum_2_d_array {
    
    /**
     * Your NumMatrix object will be instantiated and called as such:
     * NumMatrix obj = new NumMatrix(matrix);
     * int param_1 = obj.sumRegion(row1,col1,row2,col2);
    */
    class NumMatrix {

        int[][] pref;

        static void printArr(int[][] arr){
            for(int[] row : arr){
                for(int ele : row){
                    System.out.print(ele + " ");
                }
                System.out.println();
            }
        }

        public NumMatrix(int[][] matrix) {
            int row = matrix.length;
            int column = matrix[0].length;
            pref = new int[row + 1][column + 1];

            for(int i = 1; i <= column; i++){
                pref[1][i] = pref[1][i - 1] + matrix[0][i - 1];
            }
            for(int i = 1; i <= row; i++){
                pref[i][1] = pref[i - 1][1] + matrix[i - 1][0];
            }
            for(int i = 2; i <= row; i++){
                for(int j = 2; j <= column; j++){
                    pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + matrix[i - 1][j - 1];
                }
            }
            // printArr(pref);
        }
        
        public int sumRegion(int row1, int col1, int row2, int col2) {
            return pref[row2 + 1][col2 + 1] - pref[row1][col2 + 1] - pref[row2 + 1][col1] + pref[row1][col1];
        }
    }


}
