// ==========================================================
//  Unit tests for Two Sum (Project 0)
//  Output: one line per test case with input -> result details.
//  All test cases run even if one fails; summary printed at end.
// ==========================================================
#include <iostream>
#include <string>
#include <vector>
#include "twosum.h"

static int g_passed = 0;
static int g_failed = 0;
static int g_testNo = 0;

static bool equalPairs(const std::vector<int>& a, const std::vector<int>& b) {
    return a.size() == 2 && b.size() == 2 && a[0] == b[0] && a[1] == b[1];
}

static std::string fmt(const std::vector<int>& vec, size_t maxItems = 6) {
    std::string s = "[";
    size_t n = vec.size();
    for (size_t i = 0; i < n && i < maxItems; ++i) {
        s += std::to_string(vec[i]);
        if (i + 1 < n && i + 1 < maxItems) s += ",";
    }
    if (n > maxItems) s += ",... " + std::to_string(n) + " items";
    s += "]";
    return s;
}

// Run one test case and print a single aligned result line, e.g.:
// [T01] Standard case ............. PASS  nums=[2,7,11,15] target=9 -> [0,1]
static void runTest(const std::string& name,
                    const std::vector<int>& nums,
                    int target,
                    const std::vector<int>& expected,
                    std::vector<int> (*solver)(const std::vector<int>&, int)) {
    ++g_testNo;
    std::vector<int> result = solver(nums, target);
    bool ok = equalPairs(result, expected);

    char id[8];
    std::snprintf(id, sizeof(id), "[T%02d] ", g_testNo);
    std::string label = std::string(id) + name + " ";
    std::cout << label;
    for (size_t i = label.size(); i < 38; ++i) std::cout << '.';

    if (ok) {
        std::cout << " PASS  nums=" << fmt(nums) << " target=" << target
                  << " -> " << fmt(result) << "\n";
        ++g_passed;
    } else {
        std::cout << " FAIL  nums=" << fmt(nums) << " target=" << target
                  << " expected=" << fmt(expected) << " got=" << fmt(result) << "\n";
        ++g_failed;
    }
}

// Run the same test case against BOTH implementations.
static void runBoth(const std::string& name,
                    const std::vector<int>& nums,
                    int target,
                    const std::vector<int>& expected) {
    runTest(name + " (array)", nums, target, expected, twoSumArray);
    runTest(name + " (hashtable)", nums, target, expected, twoSumHashTable);
}

int main() {
    std::cout << "============================================================\n";
    std::cout << "  Two Sum - Unit Test Suite\n";
    std::cout << "  Goal: return indices of two numbers that add up to target\n";
    std::cout << "  Implementations: brute-force array  |  hash table O(n)\n";
    std::cout << "============================================================\n";

    std::vector<int> stress;
    stress.reserve(10000);
    for (int i = 1; i <= 10000; ++i) stress.push_back(i);

    std::cout << "\n-- Basic cases --\n";
    runBoth("Standard case",        {2, 7, 11, 15},      9,       {0, 1});
    runBoth("Two elements pair",    {1, 2},              3,       {0, 1});
    runBoth("Last pair solution",   {5, 1, 2, 8, 9},     17,      {3, 4});

    std::cout << "\n-- Special values --\n";
    runBoth("Negative numbers",     {-1, -2, -3, 5},     2,       {2, 3});
    runBoth("Negative + positive",  {-4, 2, 6, 8, -2},   4,       {0, 3});
    runBoth("Large numbers",        {1000000, 2000000, 3}, 3000000, {0, 1});
    runBoth("Duplicate values",     {3, 3, 4},           6,       {0, 1});
    runBoth("Mixed duplicates",     {1, 3, 3, 4},        6,       {1, 2});
    runBoth("All zeros, target 0",  {0, 0, 0, 0},        0,       {0, 1});

    std::cout << "\n-- Edge cases (no solution) --\n";
    runBoth("Empty input",          {},                  7,       {-1, -1});
    runBoth("Single element",       {5},                 5,       {-1, -1});
    runBoth("No matching pair",     {1, 2, 5},           100,     {-1, -1});

    std::cout << "\n-- Performance --\n";
    runBoth("Stress: 10000 elements", stress,            19999,   {9998, 9999});

    std::cout << "\n------------------------------------------------------------\n";
    std::cout << "  Result: " << g_passed << "/" << (g_passed + g_failed)
              << " test cases passed\n";
    std::cout << "============================================================\n";

    return g_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
