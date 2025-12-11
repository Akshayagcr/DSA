package c_binarysearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/*
    https://www.spoj.com/problems/EKO/
*/
public class h_ECO_SPOJ {
    
    static class FastReader {
        BufferedReader b;
        StringTokenizer s; 
        public FastReader() {
            b = new BufferedReader(new InputStreamReader(System.in));
        }

        // Method to read the next token as a string
        String next() {
            while (s == null || !s.hasMoreElements()) {
                try {
                    s = new StringTokenizer(b.readLine());
                } catch (IOException e) {
                    e.printStackTrace(); 
                }
            }
            return s.nextToken();
        }

        int nextInt() { 
            return Integer.parseInt(next()); 
        }

        long nextLong() { 
            return Long.parseLong(next()); 
        }

        double nextDouble() { 
            return Double.parseDouble(next()); 
        }

        // Method to read the next line as a string
        String nextLine() {
            String str = "";
            try {
                if (s.hasMoreTokens()) {
                    str = s.nextToken("\n");
                } else {
                    str = b.readLine();
                }
            } catch (IOException e) {
                e.printStackTrace(); 
            }
            return str;
        }

    }


    static boolean predicateFn(int[] arr, int height, int m){
        int sum = 0;
        for(int ele : arr){
            if(ele > height){
                sum = sum + (ele - height);
            }
            if(sum >= m){
                return true;
            }
        }
        return false;
    }

    static int solve(int[] arr, int m){
        int low = 0, high = arr[0], mid, ans = -1;
        for(int i = 1; i < arr.length; i++){
            if(arr[i] > high){
                high = arr[i];
            }
        }
        while(low <= high){
            mid = low + (high - low) / 2;
            boolean res = predicateFn(arr, mid, m);
            if(res){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        FastReader fr =  new FastReader();
        int n = fr.nextInt();
        int m = fr.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = fr.nextInt();
        }
        
        System.out.println(solve(arr, m));
    }
}



