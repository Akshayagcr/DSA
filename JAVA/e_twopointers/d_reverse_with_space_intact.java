package e_twopointers;

/*
    https://www.geeksforgeeks.org/problems/reverse-a-string-with-spaces-intact5213/1
*/
public class d_reverse_with_space_intact {
    
    String reverseWithSpacesIntact(String s) {
        StringBuilder sb = new StringBuilder(s);
        int i = 0, j = sb.length() - 1;
        char temp;
        while(i < j){
            if(sb.charAt(i) == ' '){
                i++;
            } else if(sb.charAt(j) == ' '){
                j--;
            } else {
                temp = sb.charAt(i);
                sb.setCharAt(i, sb.charAt(j));
                sb.setCharAt(j, temp);
                i++; j--;
            }
        }
        return sb.toString();
    }
}
