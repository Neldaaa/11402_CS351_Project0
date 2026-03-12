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
