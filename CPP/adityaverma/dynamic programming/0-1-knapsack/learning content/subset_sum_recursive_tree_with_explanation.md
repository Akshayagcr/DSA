# Subset Sum Recursive Tree (arr = [3, 4, 5], target = 9)

This recursive tree represents all the possible decisions for the subset sum problem, where each node shows the remaining elements to be considered and the current target value. Each branch is labeled with the decision taken — whether to **Include** or **Exclude** the current element. Successful paths where the target becomes 0 are marked with ✅ and unsuccessful paths are marked with ❌.

```
                             ([3, 4, 5], target=9)
                              /               \
                      Include 5               Exclude 5
                          /                       \
                 ([3, 4], target=4)           ([3, 4], target=9)
                     /      \                    /       \
           Include 4       Exclude 4     Include 4       Exclude 4
              /                 \            /                \
        ([3], target=0) ✅   ([3], target=4) ([3], target=5)  ([3], target=9)
                              /    \           /     \          /     \
                    Include 3   Exclude 3  Include 3  Exclude 3 Include 3 Exclude 3
                      /            \         /         \         /         \
           ([], target=1)❌  ([], target=4)❌ ([], t=2)❌ ([], t=5)❌ ([], t=6)❌ ([], t=9)❌
```

## ✅ Successful Path:
- **Include 5 → Include 4 → target becomes 0**
- Subset: **[5, 4]**

## ❌ Failed Paths:
- All other paths result in remaining elements being empty with non-zero target, hence are marked as failed.