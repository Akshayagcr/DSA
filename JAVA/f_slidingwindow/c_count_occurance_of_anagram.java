package f_slidingwindow;

import java.util.*;

/*
    https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1
*/
public class c_count_occurance_of_anagram {
    
    /*
        Below solution with HashMap gives TLE error, but same logic with unordered_map in cpp is accepted !!!
        So TLE is because of Hashmap and its overhead of auto-boxing 
    */
    static int search(String subString, String text) {
        int count = 0, noZero = 0, low = 0, high = 0;
        Map<Character, Integer> m = new HashMap<>();

        for(char c : subString.toCharArray()){
            if(m.containsKey(c)){
                m.put(c, m.get(c) + 1);
            } else {
                m.put(c, 1);
            }
        }

        while(high < text.length()){
            if(m.containsKey(text.charAt(high))) {
                if(m.get(text.charAt(high)) == 1) {
                    noZero++;
                }
                m.put(text.charAt(high), m.get(text.charAt(high)) - 1);
            }
            if(high - low + 1 < subString.length()) {
                high++;
            } else {
                if(noZero == m.size()) {
                    count++;
                }
                if(m.containsKey(text.charAt(low))) {
                    if(m.get(text.charAt(low)) == 0){
                        noZero--;
                    }
                    m.put(text.charAt(low), m.get(text.charAt(low)) + 1);
                }
                low++; high++;
            }
        }
        
        return count;
    }

    /*
        This solution is accepted !!!!
        Same logic as above but replaced Map with frequency array and used Set to check membership 
    */
    static int searchV2(String subString, String text) {
        int count = 0, noZero = 0, low = 0, high = 0;
        int[] freq = new int[26];
        Set<Character> set = new HashSet<>();

        for(char c : subString.toCharArray()){
            freq[c - 'a']++;
            set.add(c);
        }

        while(high < text.length()){
            if(set.contains(text.charAt(high))) {
                if(freq[text.charAt(high) - 'a'] == 1) {
                    noZero++;
                }
                freq[text.charAt(high) - 'a'] = freq[text.charAt(high) - 'a'] - 1;
            }
            if(high - low + 1 < subString.length()) {
                high++;
            } else {
                if(noZero == set.size()) {
                    count++;
                }
                if(set.contains(text.charAt(low))) {
                    if(freq[text.charAt(low) - 'a'] == 0){
                        noZero--;
                    }
                    freq[text.charAt(low) - 'a'] = freq[text.charAt(low) - 'a'] + 1;
                }
                low++; high++;
            }
        }
        
        return count;
    }

    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        String text = sc.nextLine();
        String subString = sc.nextLine();
        System.out.println(search(subString, text));
    }

}
