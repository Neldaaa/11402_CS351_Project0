# Test Plan

## Purpose

This test plan describes the strategy for verifying both `TwoSumArray` and `TwoSumHashTable` implementations. It covers functional behavior, edge cases, and the automated CI process used to validate the project.

## Test Items

- `twoSumArray(const std::vector<int>&, int)`
- `twoSumHashTable(const std::vector<int>&, int)`
- CMake-based build pipeline
- GitHub Actions CI workflow
- Docker container build and test execution

## Testing Approach

- Unit tests are implemented in `tests/test_twosum.cpp`.
- Each implementation is executed with the same set of predetermined inputs.
- A test runner reports pass/fail status and stops on the first failure.
- CI runs the same tests automatically on push and pull requests.

## Test Cases

1. Standard case: `nums = [2, 7, 11, 15]`, `target = 9` → `[0, 1]`
2. Negative numbers: `nums = [-1, -2, -3, 5]`, `target = 2` → `[2, 3]`
3. Large numbers: `nums = [1000000, 2000000, 3]`, `target = 3000003` → `[0, 1]`
4. Duplicate values: `nums = [3, 3, 4]`, `target = 6` → `[0, 1]`
5. No solution edge case: `nums = [1, 2, 3]`, `target = 10` → `[-1, -1]`

## Success Criteria

- The project compiles successfully with C++20.
- All unit tests must pass.
- CI must build the project and run tests successfully.
- Docker must be able to build the image and run the test executable.
