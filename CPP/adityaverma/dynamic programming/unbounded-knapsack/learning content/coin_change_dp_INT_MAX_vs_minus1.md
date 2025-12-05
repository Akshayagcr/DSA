
# Why Use `INT_MAX` Instead of `-1` in Coin Change Dynamic Programming (DP)

In solving the **Coin Change problem** using **Dynamic Programming (DP)**, a common question arises:  
> Why do we use `INT_MAX` to represent "unreachable" states in the DP table instead of `-1`?

This document provides a clear and detailed explanation, with examples and comparisons to demonstrate why `INT_MAX` is the recommended approach.

---

## 🎯 Problem Statement (LeetCode #322)

Given a set of coin denominations `coins[]` and an integer `amount`, find the **minimum number of coins** required to make up that amount.  
If it is **not possible**, return `-1`.

---

## 🧠 DP Table Interpretation

Let `t[i][j]` represent the **minimum number of coins required to make amount `j` using the first `i` coins**.

---

## ✅ Base Case Initialization

| Case | Meaning | Value |
|------|--------|--------|
| `t[0][0]` | Amount `0` using `0` coins | `0` (no coins needed) |
| `t[0][j]` (j > 0) | Amount `j` using `0` coins | `INT_MAX` (unreachable) |

---

## ❓ Why Use `INT_MAX` Instead of `-1`?

### `INT_MAX` is used to mark **unreachable states** because:
- It works naturally with `min()` operations.
- You can **safely check `!= INT_MAX` before doing arithmetic like `1 + t[i][j - coin]`**, avoiding overflow or incorrect calculations.
- It clearly distinguishes between **reachable and unreachable states** in a numerical way.

---

### Example: `coins = {2}`, `amount = 3`

### ✔ Using `INT_MAX`:

**DP Table Construction:**

| i \ j | 0 | 1 | 2 | 3 |
|--------|---|---|---|---|
| 0      | 0 | ∞ | ∞ | ∞ |
| 1      | 0 | ∞ | 1 | ∞ |

**Explanation:**
- `j=2`: You can use one coin of `2` → `t[1][2] = 1`
- `j=3`: `t[1][1] = ∞` → You can't make amount `3` using coin `2`

➡ Final Answer: `t[1][3] = INT_MAX → return -1`

---

### ❌ Using `-1` Instead of `INT_MAX`

**Modified Base Case:**

| i \ j | 0 | 1 | 2 | 3 |
|--------|---|----|----|----|
| 0      | 0 | -1 | -1 | -1 |

**Filling the Table:**
- `j=2`: include = `1 + t[1][0] = 1` → ✅ Fine
- `j=3`: include = `1 + t[1][1] = 1 + (-1) = 0 ❌ Incorrect!`

Now the DP table becomes:

| i \ j | 0 | 1 | 2 | 3 |
|--------|---|----|----|----|
| 0      | 0 | -1 | -1 | -1 |
| 1      | 0 | -1 | 1  | 0 ❌ |

➡ Final Answer: `t[1][3] = 0 → return 0 ❌ Wrong Result!`

---

## 🔥 What Went Wrong With `-1`?

- Arithmetic operations (`1 + t[i][j - coin]`) on `-1` produce **valid but incorrect values** (e.g., `1 + (-1) = 0`)
- `min(a, b)` does **not work naturally** when one of them is `-1`
- Requires **extra conditional logic** to handle cases like:

```cpp
if (include == -1 && exclude == -1) t[i][j] = -1;
else if (include == -1) t[i][j] = exclude;
else if (exclude == -1) t[i][j] = include;
else t[i][j] = min(include, exclude);
```

➡ Code becomes **complex, error-prone, and less readable**

---

## 📌 Summary: Why `INT_MAX` is Better

| Criteria | `INT_MAX` | `-1` |
|---------|------------|------|
| Safe for `min()` operations | ✅ Yes | ❌ No |
| Prevents invalid arithmetic | ✅ Yes | ❌ No |
| Clear representation of "unreachable" | ✅ Yes | ✅ Yes |
| Requires extra logic | ❌ No | ✅ Yes (more if-else cases) |
| Code readability and maintainability | ✅ Better | ❌ Worse |

---

## 🏁 Conclusion

While you **can technically make `-1` work** with additional logic and checks, it:
- **Complicates your code**
- **Increases the risk of bugs**
- **Makes your DP transitions harder to manage**

Using `INT_MAX` is the standard, clean, and robust approach in **minimum value DP problems**, especially when arithmetic operations like `+1` are involved.

---

## ✨ Bonus Tip:
If you're using `INT_MAX`, always **check for `!= INT_MAX` before doing `+1`**, to avoid integer overflow:

```cpp
if (t[i][j - coins[i-1]] != INT_MAX) {
    include = 1 + t[i][j - coins[i-1]];
}
```

---

## 💬 Questions?
Feel free to experiment with both approaches, but you'll quickly realize why `INT_MAX` is the preferred choice in practice.
