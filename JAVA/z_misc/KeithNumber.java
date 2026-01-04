package z_misc;

import java.util.Scanner;
import java.util.*;

/*
    https://www.geeksforgeeks.org/problems/keith-number2745/1
*/
public class KeithNumber {
    
    static Scanner sc = new Scanner(System.in);

    static void printArray(int[] arr){
        for(int ele : arr){
            System.out.print(ele + " ");
        }
        System.out.println();
    }

    static int isKeith(int n) {
        List<Integer> l = new ArrayList<>();
        int numberOfDigit = 0, isKeith = n;
        while(n > 0){
            l.add(n % 10);
            n = n / 10;
            numberOfDigit++;
        }

        int i = 0, j = l.size() - 1, temp;
        while(i < j){
            temp = l.get(i);
            l.set(i, l.get(j));
            l.set(j, temp);
            i++; j--;
        }

        int sum;
        while(l.get(l.size() - 1) < isKeith){
            sum = 0;
            for(int k = numberOfDigit - 1; k >= 0; k--){
                sum += l.get(l.size() - 1 - k);
            }
            l.add(sum);
        }
        if(l.get(l.size() - 1) == isKeith){
            return 1;
        }
        return 0;
    }

    public static void main(String[] args) {
        System.out.println(isKeith(197));
    }
}
