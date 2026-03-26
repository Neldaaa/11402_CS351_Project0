# SDS

## Overview
A solution to find two numbers in an array that sum to a target value, returning their indices.

## Requirements
- Input: Array of integers and a target sum
- Output: Indices of two distinct numbers that add up to target
- Constraint: Each input has exactly one valid solution
- Constraint: Cannot use the same element twice

## Design
- **Approach**: Hash map for O(n) time complexity
- **Data Structure**: HashMap to store value-index pairs
- **Algorithm**: Single pass through array, checking if complement exists

## Implementation Details
- Iterate through array once
- For each number, check if (target - number) exists in map
- Store mappings of values to indices
- Return indices when complement found

## Testing
- Test with standard cases (two positive, negative, mixed numbers)
- Test edge cases (array length 2, large numbers)
- Verify correct indices returned (not same element)