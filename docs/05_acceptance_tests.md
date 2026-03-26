# Acceptance Test

## TwoSum Problem

### Test Case 1: Valid Pair Found
**Given:** `nums = [2, 7, 11, 15]`, `target = 9`  
**When:** Finding two numbers that sum to target  
**Then:** Return `[0, 1]` (indices of 2 and 7)

### Test Case 2: Multiple Valid Pairs
**Given:** `nums = [3, 3]`, `target = 6`  
**When:** Finding two numbers that sum to target  
**Then:** Return `[0, 1]`

### Test Case 3: No Valid Pair
**Given:** `nums = [1, 2, 3]`, `target = 10`  
**When:** Finding two numbers that sum to target  
**Then:** Return empty result or appropriate error indicator

### Test Case 4: Negative Numbers
**Given:** `nums = [-1, -2, -3, 5, 6]`, `target = 4`  
**When:** Finding two numbers that sum to target  
**Then:** Return `[3, 4]` (indices of -1 and 5, or equivalent valid pair)

### Test Case 5: Large Numbers
**Given:** `nums = [1000000, 2000000, 3000000]`, `target = 5000000`  
**When:** Finding two numbers that sum to target  
**Then:** Return `[1, 2]`