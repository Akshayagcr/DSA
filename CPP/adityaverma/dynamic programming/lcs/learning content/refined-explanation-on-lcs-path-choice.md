# Explanation: Path Choice in SCS Reconstruction (When LCS Cell Values Are Equal)

## ❓ Question

What happens during SCS backtracking if:
- `s1[i - 1] != s2[j - 1]` (characters are different)
- `t[i - 1][j] == t[i][j - 1]` (both options give same LCS length)

Which path should we follow?

---

## ✅ Answer

When both `t[i - 1][j]` and `t[i][j - 1]` are equal, **both directions are valid** LCS paths. You can either:
- Go **up** and include `s1[i - 1]`
- Go **left** and include `s2[j - 1]`

### ✅ Important:
Both choices lead to a valid **Shortest Common Supersequence (SCS)**, though they may result in **different sequences** (but of the same minimum length).

---

## 🔧 Code Behavior

Typical implementation:
```cpp
if (t[i - 1][j] > t[i][j - 1]) {
    res.push_back(s1[i - 1]);
    i--;
} else {
    res.push_back(s2[j - 1]);
    j--;
}
```

This means:
- You **prefer `s2[j - 1]`** (left direction) when both values are equal.
- This is a valid heuristic and produces one of the possible shortest supersequences.

---

## 📌 Full Example

Let’s take:

```cpp
s1 = "abc"
s2 = "adc"
```

### Step 1: LCS Table

|   | "" | a | d | c |
|---|----|---|---|---|
| ""| 0  | 0 | 0 | 0 |
| a | 0  | 1 | 1 | 1 |
| b | 0  | 1 | 1 | 1 |
| c | 0  | 1 | 1 | 2 |

The **LCS** is `"ac"`.

---

### Step 2: Backtracking with Equal Choices

We start from `t[3][3] = 2`:

- `s1[2] == s2[2] = 'c'` → Match → Add `'c'` → `res = "c"`
- Move to `t[2][2] = 1`

Now:
- `s1[1] = 'b'`, `s2[1] = 'd'` → No match
- `t[1][2] = 1`, `t[2][1] = 1` → **Equal!**
- If we choose `s2[1] = 'd'` → Add `'d'` → `res = "cd"` → move to `t[2][1]`

Then:
- `s1[1] = 'b'`, `s2[0] = 'a'` → No match
- `t[1][1] = 1`, `t[2][0] = 0` → Go up → Add `'b'` → `res = "cdb"`

Then:
- `s1[0] = 'a'`, `s2[0] = 'a'` → Match → Add `'a'` → `res = "cdba"`

Reverse → `"abdc"`

Alternatively, if we had chosen `'b'` at the equal point, we could get `"adbc"`.

---

## ✨ Result

Both `"abdc"` and `"adbc"` are valid SCS of `"abc"` and `"adc"` with length `4`.

---

## 🧠 Summary

- Equal `t[i-1][j]` and `t[i][j-1]` values mean multiple shortest supersequences exist.
- Picking either path is fine and will yield a correct result.
- If you want to generate **all** possible SCS variants, you'd need to explore **both** directions recursively.
