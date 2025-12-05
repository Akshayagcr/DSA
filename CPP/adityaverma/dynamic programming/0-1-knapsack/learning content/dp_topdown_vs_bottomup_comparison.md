
# 🧠 Top-Down vs Bottom-Up DP Table Comparison (Subset Sum Example)

## 📌 Problem Statement: Subset Sum
> Given an array `arr = {3, 1, 5}` and `target = 5`, check whether there exists a subset with sum equal to the target.

---

## 🔍 DP Table Meaning
- `t[i][j] = 1`: Sum `j` is achievable using first `i` elements.
- `t[i][j] = 0`: Sum `j` is **not** achievable using first `i` elements.
- `t[i][j] = -1`: (Top-Down only) **Not yet computed**.

---

## 🆚 DP Table Comparison

| i \ j | 0 | 1 | 2 | 3 | 4 | 5 |
|--------|---|---|---|---|---|---|
| **Top-Down (only needed states)** | |
| 0 | 1 | 0 | -1 | -1 | -1 | 0 |
| 1 | 1 | 1 | -1 | 1 | -1 | -1 |
| 2 | 1 | 1 | -1 | 1 | 1 | -1 |
| 3 | 1 | 1 | -1 | 1 | 1 | 1 |
| **Bottom-Up (fully filled)** | |
| 0 | 1 | 0 | 0 | 0 | 0 | 0 |
| 1 | 1 | 0 | 0 | 1 | 0 | 0 |
| 2 | 1 | 1 | 0 | 1 | 1 | 0 |
| 3 | 1 | 1 | 0 | 1 | 1 | 1 |

---

## ✅ Conclusion

| Aspect | Top-Down (Memoization) | Bottom-Up (Tabulation) |
|--------|-------------------------|--------------------------|
| Lazy filling | ✅ Only needed cells | ❌ Fills all cells |
| Space Optimization | Difficult | Easy with 1D DP |
| Intermediate values | Partially filled | Fully filled |
| End result | ✅ Correct | ✅ Correct |

---

## 💡 Code Snippets (Side by Side)

### Top-Down DP (Memoization)
```cpp
class Solution {
public:
    vector<vector<int>> t;

    bool subsetSum(int n, int target, vector<int>& arr) {
        if (target == 0) return true;
        if (n == 0) return false;

        if (t[n][target] != -1) return t[n][target];

        if (arr[n - 1] <= target) {
            bool include = subsetSum(n - 1, target - arr[n - 1], arr);
            bool exclude = subsetSum(n - 1, target, arr);
            return t[n][target] = include || exclude;
        }
        return t[n][target] = subsetSum(n - 1, target, arr);
    }

    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        t.assign(n + 1, vector<int>(target + 1, -1));
        return subsetSum(n, target, arr);
    }
};
```

---

### Bottom-Up DP (Tabulation)
```cpp
class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<bool>> t(n + 1, vector<bool>(target + 1, false));

        for (int i = 0; i <= n; i++) t[i][0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (arr[i - 1] <= j) {
                    t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i - 1]];
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][target];
    }
};
```

---

## 🧪 Test Case Example
```cpp
int main() {
    Solution sol;
    vector<int> arr = {3, 1, 5};
    int target = 5;
    cout << (sol.isSubsetSum(arr, target) ? "Yes" : "No") << endl;
    return 0;
}
```
