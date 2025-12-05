# Why We Need a Loop After One of i or j Becomes Zero in SCS Reconstruction

## 🧩 Context

During reconstruction of the **Shortest Common Supersequence (SCS)** using the LCS DP table, we typically backtrack from the bottom-right of the table (`t[m][n]`) to the top-left.

We loop while both `i > 0 && j > 0`, matching characters or following the path based on the values in `t[i][j]`.

But after that, we **must handle the case when only one string has characters left**.

---

## ❓ Why Is an Extra Loop Needed When i or j Becomes 0?

When we reach the edge of the DP table (i.e., `i == 0` or `j == 0`), it means we've reached the beginning of one string, **but not necessarily the other**.

We need to **append the remaining characters** of the non-exhausted string to the result because:

- These characters are not part of the LCS.
- But they still need to appear in the SCS.

---

## ✅ Example

Let’s take:

```cpp
s1 = "abc"
s2 = "d"
```

### Step-by-step:

1. **LCS** of `"abc"` and `"d"` is empty (`""`)
2. While `i > 0 && j > 0`:
   - `s1[2] = 'c'` ≠ `s2[0] = 'd'`
   - `t[2][1] == t[3][0] == 0`, so it chooses `s2[0] = 'd'`, and decrements `j`.

3. Now, `j == 0`, but `i == 3`.  
   We've only consumed all of `s2`, so we still need to **append the rest of `s1`**: `'a'`, `'b'`, `'c'`.

### Final SCS: `"dabc"`

---

## ✅ Code Snippet

```cpp
// After main while loop
while(i > 0){
    res.push_back(s1[i - 1]);
    i--;
}
while(j > 0){
    res.push_back(s2[j - 1]);
    j--;
}
```

This ensures that **no characters are left out**, even if they don’t participate in the LCS.

---

## 🧠 Summary

- The extra loops handle leftover characters from `s1` or `s2` once the other string is fully processed.
- This is **essential** for constructing the correct SCS, especially when LCS is short or empty.
