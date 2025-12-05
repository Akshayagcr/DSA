
# ✅ Perfect Sum Problem – Memoized vs Tabulation: Base Case & Zero Handling

---

## 📌 Key Idea
In **Perfect Sum Problem**, multiple subsets can sum to zero due to **zeros in the array**. Handling them correctly depends on **how your DP is structured** — either **Top-Down (Memoization)** or **Bottom-Up (Tabulation)**.

---

## 🔍 1. Memoized (Top-Down Recursive) Version

### ✅ Base Case:
```cpp
if (n == 0) return (target == 0) ? 1 : 0;
```

- This handles the case when **no elements are left**.
- It effectively **fills only the 0th row** of the DP table: `dp[0][target]`
- **Multiple zeros are naturally handled** via recursion in the **transition logic**:
  - Take or not take current element
  - Zeros allow duplication of subset paths, which recursion explores

👉 No need to do anything special for multiple zeros in the base case.

---

## 🔍 2. Tabulation (Bottom-Up) Version

### ✅ Base Case Initialization:
```cpp
for (int i = 0; i <= n; ++i)
    dp[i][0] = 1;
```

- This initializes **first column (`dp[i][0] = 1`)**, meaning:
  - You can always make **sum = 0** by choosing no elements
- This does **not** yet account for the **multiple subsets with sum=0 due to zeros**.

### ✅ Multiple Zeros Handling:
Handled correctly during DP transitions:
```cpp
dp[i][sum] = dp[i-1][sum] + dp[i-1][sum - arr[i-1]];
```

- Every time a zero is encountered:
  - Both **"take"** and **"not take"** will lead to **same sum**, doubling the count
- So **extra subsets due to zeros are added automatically** as DP fills

👉 No need to adjust base case for zero values — transitions take care of it.

---

## ✅ Summary Comparison Table

| Method        | Base Case Initialization             | Handles Zeros? | How Zeros Are Counted         |
|---------------|---------------------------------------|----------------|-------------------------------|
| Memoized      | Only **0th row**: `(target == 0) ? 1` | ✅ Yes         | Through **recursion branches** |
| Tabulation    | **0th column**: `dp[i][0] = 1`        | ✅ Yes         | Through **DP transitions**     |

---

## 💡 Final Insight
> Base case only sets **initial structure** of DP.  
> Actual handling of **multiple combinations (like from zeros)** always happens through the **transition logic**, not base case initialization.
