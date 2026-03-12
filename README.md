# Two Sum Problem

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers that add up to the target. You may assume that each input has exactly one solution, and you cannot use the same element twice.


## Implementation Plan

### Solution 1: TwoSumArray
**Approach:** Brute force with nested loops

**Input:** 
- `nums`: Array of integers
- `target`: Integer

**Output:** 
- Array of two indices `[i, j]`

**Implementation:**

1. Use two nested loops to check all pairs
2. For each pair, check if their sum equals the target
3. Return the indices when a match is found
4. If no pair found, return empty array

```python
def twoSumArray(nums, target):
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                return [i, j]
    return []
```

**Time Complexity:** O(n²)  
**Space Complexity:** O(1)

---

### Solution 2: TwoSumHashtable
**Approach:** Hash map for single pass lookup

**Input:** 
- `nums`: Array of integers
- `target`: Integer

**Output:** 
- Array of two indices `[i, j]`

**Implementation:**

1. Create an empty hash map to store seen numbers
2. Iterate through the array once
3. For each number, calculate the complement (target - current number)
4. Check if complement exists in the hash map
5. If found, return the stored index and current index
6. Otherwise, store the current number and its index in the map
7. If no pair found after iteration, return empty array

```python
def twoSumHashtable(nums, target):
    seen = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            return [seen[complement], i]
        seen[num] = i
    return []
```

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

