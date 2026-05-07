# Acceptance Tests

## Objective

Acceptance tests confirm the project meets the user-facing requirements for solving the Two Sum problem and supports automated verification.

## Acceptance Criteria

- The implementation returns the correct indices for both `TwoSumArray` and `TwoSumHashTable`.
- Standard, negative, large, duplicate, and no-solution cases are verified.
- The build process succeeds using CMake and the generated tests are executed.
- CI triggers on `push` and `pull_request` events to `main`.
- The Docker image builds and can execute the same tests.

## Test Scenarios

- `TwoSumArray` returns `[0, 1]` for standard example input.
- `TwoSumHashTable` returns `[0, 1]` for standard example input.
- Both implementations return `[2, 3]` for negative numbers.
- Both implementations return `[0, 1]` for large numbers.
- Both implementations return `[0, 1]` for duplicate values.
- Both implementations return `[-1, -1]` when no pair exists.

## Validation Procedure

1. Build with CMake.
2. Run the `twosum_tests` executable.
3. Ensure output reports `All TwoSum tests passed.`
4. Confirm the CI workflow passes on GitHub.
