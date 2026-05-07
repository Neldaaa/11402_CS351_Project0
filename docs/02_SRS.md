# Software Requirements Specification

## Introduction

This SRS defines the functional and non-functional requirements for the Two Sum C++ project.

## Functional Requirements

- FR1: Accept an integer array and target integer.
- FR2: Return the indices of two numbers that add to the target.
- FR3: Provide a brute-force implementation named TwoSumArray.
- FR4: Provide a hash-table implementation named TwoSumHashTable.
- FR5: Return [-1, -1] when no valid pair exists.
- FR6: Execute automated unit tests covering multiple input categories.

## Non-Functional Requirements

- NFR1: Use C++20 language standard.
- NFR2: Build with CMake.
- NFR3: Be portable across common development environments.
- NFR4: Integrate with GitHub Actions CI.
- NFR5: Support Docker-based build and execution.

## Constraints

- The implementation uses std::vector<int> for arrays.
- The project is designed for fixed test inputs, not interactive runtime data.
- Array values should fit in normal 32-bit integer ranges.

## Assumptions

- Standard inputs contain at most one solution.
- Duplicate numbers are allowed and may produce a valid solution.
- The local environment provides a C++ toolchain or Docker.
