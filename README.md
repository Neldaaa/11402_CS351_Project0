# Two Sum Problem

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers that add up to the target. You may assume that each input has exactly one solution, and you cannot use the same element twice.


## Requirements

### Programming Language
- C++ 20
- STL `vector` for array handling

### Implementations Required
1. **TwoSumArray** - Brute force nested loop approach
2. **TwoSumHashtable** - Hash map single-pass approach

### Test Cases
- Standard case: `nums = [2, 7, 11, 15], target = 9` → `[0, 1]`
- Negative numbers: `nums = [-1, -2, -3, 5], target = 2` → `[2, 3]`
- Large numbers: `nums = [1000000, 2000000, 3], target = 3000003` → `[0, 1]`
- Duplicate values: `nums = [3, 3, 4], target = 6` → `[0, 1]`
- No solution edge case handling

### GitHub Integration
- GitHub Actions workflow for CI/CD
- Automated testing on push and pull requests
- Build verification

### Docker Support
- `Dockerfile` for containerized build environment
- C++ 20 compiler support (GCC 10+ or Clang 10+)
- Automated docker image build on repository updates


## Detail about Github Actions
### CI/CD Pipeline Configuration

The GitHub Actions workflow automatically triggers on:
- Push events to `main` branch
- Pull requests to `main` branch

### Workflow Steps

1. **Checkout Code** - Fetches repository contents
2. **Setup C++ Environment** - Configures GCC 10+ or Clang 10+ compiler
3. **Build Project** - Compiles C++ 20 code with CMake
4. **Run Unit Tests** - Executes test cases for both implementations:
    - `TwoSumArray` brute force validation
    - `TwoSumHashtable` hash map validation
5. **Test Coverage** - Verifies all test cases pass:
    - Standard, negative, large, duplicate, and edge cases
6. **Docker Build** - Builds containerized image for consistent environments
7. **Artifact Generation** - Archives build artifacts and test reports

### Automated Checks
- Build status badge in repository
- Automatic PR status checks
- Failure notifications
- Test report summaries