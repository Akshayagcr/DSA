# Longest Common Substring - Tabulation Method Explanation

---

## Problem Overview

Given two strings `s1` and `s2`, find the **length** of the **Longest Common Substring**.
- **Substring** means: characters must be **contiguous** in both strings.

Example:
```
s1 = "abcde"
s2 = "abfde"
Longest Common Substring = "de" (length 2)
```

---

## Tabulation Approach (Bottom-Up Dynamic Programming)

### Step-by-Step Process

1. **Create a 2D DP Table `t`**
   - Size `(n+1) x (m+1)` where `n = s1.size()` and `m = s2.size()`.
   - `t[i][j]` represents the length of the longest common substring ending at `s1[i-1]` and `s2[j-1]`.

2. **Initialize**
   - All elements of `t` to `0`.
   - Because if any string is empty, the longest substring is of length 0.

3. **Filling the Table**
   - Loop `i` from 1 to `n`, and `j` from 1 to `m`.
   - If `s1[i-1] == s2[j-1]`, then:
     ```
     t[i][j] = 1 + t[i-1][j-1]
     ```
     (Extend previous substring)
   - Else:
     ```
     t[i][j] = 0
     ```
     (Characters do not match, reset)

4. **Track Maximum**
   - Maintain a variable `maxLen` to keep track of the maximum value in the table while filling it.

### Code

```cpp
vector<vector<int>> t(n+1, vector<int>(m+1, 0));
int maxLen = 0;

for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
        if(s1[i-1] == s2[j-1]) {
            t[i][j] = 1 + t[i-1][j-1];
            maxLen = max(maxLen, t[i][j]);
        } else {
            t[i][j] = 0;
        }
    }
}

return maxLen;
```

---

## Why We Cannot Simply Return `t[n][m]`

- In **Longest Common Substring**, the longest matching substring may **end anywhere** in the two strings.
- `t[n][m]` only tells the length if the matching substring **ends exactly at** the last characters.
- But it could have ended much earlier.

### Visual Example

Let's consider:
```
s1 = "abcde"
s2 = "abfde"
```

The table `t` will be:

|   |   | a | b | f | d | e |
|---|---|---|---|---|---|---|
|   | 0 | 0 | 0 | 0 | 0 | 0 |
| a | 0 | 1 | 0 | 0 | 0 | 0 |
| b | 0 | 0 | 2 | 0 | 0 | 0 |
| c | 0 | 0 | 0 | 0 | 0 | 0 |
| d | 0 | 0 | 0 | 0 | 1 | 0 |
| e | 0 | 0 | 0 | 0 | 0 | 2 |

- Notice: maximum value (`2`) occurs at multiple places.
- **But `t[5][5] = 2` doesn't capture all possible substring locations.**

### Conclusion

✅ **We must scan the whole table to find the maximum value.**

---

## Summary

| Problem Type                  | Final Answer from `t[n][m]`? | Reason |
|---------------------------------|------------------------------|--------|
| Longest Common Subsequence     | Yes ✅                       | Subsequence allows gaps, ends at last cell. |
| Longest Common Substring       | No ❌                        | Substring must be contiguous, can end anywhere. |

---

# Quick Save:
> In **Longest Common Substring**, always scan the **entire table** to find the maximum! 🚀

