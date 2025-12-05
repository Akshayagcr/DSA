
# 🧠 Understanding DP Table Initialization (Tabulation Method)

## 📍 Why is Initialization Important?
Initialization (base case) in Dynamic Programming (DP) is like the **foundation**. All other values in the table depend on how you start.

In **tabulation (bottom-up DP)**, you **manually set the base cases** before filling the rest of the table.

---

## 💡 Coin Change II — Count Number of Combinations

### `dp[i][j]` Meaning:
> Number of ways to make amount `j` using the first `i` coins.

### Code Snippet:
```cpp
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    // Base case initialization
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
}
```

---

## ✅ Why `dp[i][0] = 1`?

### Logic:
- You can make **amount = 0** by selecting **no coins** — exactly **1 way to do this**.
- So for **every row `i`**, the number of ways to make amount `0` is `1`.

### In Code:
```cpp
for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
}
```

This initializes that **zero amount can always be formed in one way** — by choosing nothing.

---

## ❌ Why not `dp[0][j] = 1`?
- `dp[0][j]` means: ways to make amount `j` using **0 coins**.
- You **cannot form any positive amount `j` using zero coins**, so:
```cpp
dp[0][j] = 0; // Already default if table is initialized with 0
```

---

## 🔁 Summary Table

| Index       | Meaning                                  | Value        |
|-------------|------------------------------------------|--------------|
| `dp[i][0]`  | Ways to make amount `0` with `i` coins    | `1` ✅ One way |
| `dp[0][j]`  | Ways to make amount `j` with `0` coins    | `0` ❌ No way |

---

## 📝 General Tip for Counting Problems (Tabulation)
- **Set `dp[i][0] = 1`** — One way to make amount 0.
- **Default `dp[0][j] = 0`** — No way to make positive amount with 0 items.

---

Happy DP Coding! 💻✨
