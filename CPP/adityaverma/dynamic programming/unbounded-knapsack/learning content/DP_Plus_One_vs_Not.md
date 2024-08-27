
# 🔍 Understanding When to Use `+1` in Dynamic Programming (DP)

## ✅ Why `+1` is NOT Required in Counting Problems (e.g., Coin Change II)

### Goal: Count the **number of combinations/ways** to reach a certain total.

### Example Problem:
> "In how many ways can I make amount `j` using coins?"

You consider two choices:
- **Include current coin** → Add the **number of ways** to make `(j - coin_value)`
- **Exclude current coin** → Use the **number of ways** without the current coin

### `dp[i][j - coin_value]` means:
It represents **how many ways** you can form amount `(j - coin_value)` using coins.

You **do NOT add `+1`**, because:
- You're **not adding a new way**, just **reusing previously calculated counts**.
- Formula becomes:
  ```cpp
  dp[i][j] = include + exclude;
  ```

### Real-life Analogy:
Imagine you have a box of building blocks:
- `dp[i][j - coin_value]` gives you **existing structures**.
- You're **summing possible builds**, not inventing new ways by adding `+1`.

---

## ❌ When `+1` IS Required: Optimization Problems (Min/Max)

### Example: Minimum Number of Coins
> "What is the **minimum number of coins** to make amount `j`?"

Now logic changes:
- If you **include a coin**, you're saying:
  > "To make amount `j`, I use **1 coin (current)** + solution for amount `j - coin_value`"

### Formula becomes:
```cpp
dp[i][j] = min(1 + dp[i][j - coin_value], dp[i - 1][j]);
```

Here, `+1` is necessary because you're counting **number of coins**, not ways.

---

## 🔁 Summary Table

| Problem Type                | Formula                            | Why `+1`?                                      |
|----------------------------|-------------------------------------|-----------------------------------------------|
| Count combinations/ways    | `dp[i][j] = include + exclude`     | ❌ No `+1`: summing ways, not extra per step   |
| Min coins needed           | `dp[i][j] = min(1 + include, exclude)` | ✅ Yes `+1`: counting coins/steps used        |

---

## 📌 Example Code Snippets

### Coin Change (Combinations):
```cpp
if (coin <= j)
    dp[i][j] = dp[i][j - coin] + dp[i - 1][j];  // ✅ NO +1
```

### Coin Change (Minimum Coins):
```cpp
if (coin <= j)
    dp[i][j] = min(1 + dp[i][j - coin], dp[i - 1][j]);  // ✅ +1 required
```

---

## 🔚 Conclusion
- Use **`+1` only when counting steps/items (like min coins)**.
- Do **NOT use `+1` when counting total combinations/ways** — you’re just summing the number of possible paths.

---
