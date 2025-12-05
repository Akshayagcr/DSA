package d_precomputation;

import java.util.*;

public class z_misc_count_letters {

    private static int[] arr = new int[26];

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();

        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) != ' '){
                arr[s.charAt(i) - 'a']++;
            }
        }
        for(int i = 0; i < arr.length; i++){
            if(arr[i] > 0){
                System.out.println((char)('a' + i) + "=" + arr[i] + " ");
            }
        }
    }
    
}
