# Software Design Specification

## System Overview

The Two Sum project provides two algorithm implementations, a test harness, CI automation, and containerization support.

## Architecture

- src/twosum.h: public function declarations.
- src/twosum.cpp: algorithm implementations.
- src/main.cpp: sample executable entry point.
- 	ests/test_twosum.cpp: automated test harness.
- CMakeLists.txt: build and test configuration.
- .github/workflows/ci.yml: CI pipeline definitions.
- Dockerfile: containerized build and execution environment.

## Data Structures

- std::vector<int> for input arrays and result indices.
- std::unordered_map<int, int> for constant-time lookups in the hash-table solution.

## Algorithms

- 	woSumArray: nested loops, compares every pair, O(n^2) time complexity.
- 	woSumHashTable: one-pass hash map lookup, O(n) time complexity.

## Interfaces

Public interfaces in src/twosum.h:
- std::vector<int> twoSumArray(const std::vector<int>& nums, int target);
- std::vector<int> twoSumHashTable(const std::vector<int>& nums, int target);

## Build Process

- Use CMake to generate build files.
- Compile both the application and test executable.
- Use ctest for test execution.

## Test Design

The test harness verifies both implementations using the same input set and checks expected outputs for normal, edge, duplicate, negative, and stress cases.
