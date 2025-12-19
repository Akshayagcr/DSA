package e_twopointers;

import java.util.Scanner;

/*
    https://www.geeksforgeeks.org/problems/string-palindromic-ignoring-spaces4723/1
*/
public class d_a_sentence_palindrome {

    static Scanner sc = new Scanner(System.in);
    
    public static boolean isPalinSent(String s) {
        int i = 0, j = s.length() -1;
        while(i < j){
            if(!isAlphaNum(s.charAt(i)) || s.charAt(i) == ' '){
                i++;
            } else if(!isAlphaNum(s.charAt(j)) || s.charAt(j) == ' '){
                j--;
            } else {
                if(Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j))){
                    return false;
                }
                i++; j--;
            }
        }
        return true;
    }

    static boolean isAlphaNum(char c){
        return (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z') ||
        (c >= '0' && c <= '9');
    }

    public static void main(String[] args) {
        System.out.println(isPalinSent(sc.nextLine()));
    }
}
