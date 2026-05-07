#include <iostream>
#include <vector>
#include <string>
#include "twosum.h"

static bool equalPairs(const std::vector<int>& a, const std::vector<int>& b) {
    return a.size() == 2 && b.size() == 2 && a[0] == b[0] && a[1] == b[1];
}

static std::string formatVector(const std::vector<int>& vec) {
    std::string result = "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        result += std::to_string(vec[i]);
        if (i + 1 < vec.size()) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}

static void runTest(const std::string& name,
                    const std::vector<int>& nums,
                    int target,
                    const std::vector<int>& expected,
                    std::vector<int> (*solver)(const std::vector<int>&, int)) {
    std::vector<int> result = solver(nums, target);
    if (!equalPairs(result, expected)) {
        std::cerr << "FAILED: " << name << "\n";
        std::cerr << "  input nums=" << formatVector(nums) << ", target=" << target << "\n";
        std::cerr << "  expected=" << formatVector(expected) << "\n";
        std::cerr << "  actual=" << formatVector(result) << "\n";
        std::exit(EXIT_FAILURE);
    }
}

int main() {
    const std::vector<int> empty = {};
    const std::vector<int> single = {5};
    const std::vector<int> pair = {1, 2};
    const std::vector<int> standard = {2, 7, 11, 15};
    const std::vector<int> negative = {-1, -2, -3, 5};
    const std::vector<int> large = {1000000, 2000000, 3};
    const std::vector<int> duplicates = {3, 3, 4};
    const std::vector<int> mixedDuplicates = {1, 3, 3, 4};
    const std::vector<int> zeros = {0, 0, 0, 0};
    const std::vector<int> lastPair = {5, 1, 2, 8, 9};
    const std::vector<int> negativesAndPositives = {-4, 2, 6, 8, -2};
    std::vector<int> stress;
    stress.reserve(10000);
    for (int i = 1; i <= 10000; ++i) {
        stress.push_back(i);
    }

    runTest("Empty input returns no solution (array)", empty, 7, {-1, -1}, twoSumArray);
    runTest("Empty input returns no solution (hashtable)", empty, 7, {-1, -1}, twoSumHashTable);
    runTest("Single element returns no solution (array)", single, 5, {-1, -1}, twoSumArray);
    runTest("Single element returns no solution (hashtable)", single, 5, {-1, -1}, twoSumHashTable);
    runTest("Two elements exact pair (array)", pair, 3, {0, 1}, twoSumArray);
    runTest("Two elements exact pair (hashtable)", pair, 3, {0, 1}, twoSumHashTable);
    runTest("Standard case (array)", standard, 9, {0, 1}, twoSumArray);
    runTest("Standard case (hashtable)", standard, 9, {0, 1}, twoSumHashTable);
    runTest("Negative numbers (array)", negative, 2, {2, 3}, twoSumArray);
    runTest("Negative numbers (hashtable)", negative, 2, {2, 3}, twoSumHashTable);
    runTest("Large numbers (array)", large, 3000000, {0, 1}, twoSumArray);
    runTest("Large numbers (hashtable)", large, 3000000, {0, 1}, twoSumHashTable);
    runTest("Duplicate values (array)", duplicates, 6, {0, 1}, twoSumArray);
    runTest("Duplicate values (hashtable)", duplicates, 6, {0, 1}, twoSumHashTable);
    runTest("Mixed duplicate solution (array)", mixedDuplicates, 6, {1, 2}, twoSumArray);
    runTest("Mixed duplicate solution (hashtable)", mixedDuplicates, 6, {1, 2}, twoSumHashTable);
    runTest("All zeros target zero (array)", zeros, 0, {0, 1}, twoSumArray);
    runTest("All zeros target zero (hashtable)", zeros, 0, {0, 1}, twoSumHashTable);
    runTest("Last pair solution (array)", lastPair, 17, {3, 4}, twoSumArray);
    runTest("Last pair solution (hashtable)", lastPair, 17, {3, 4}, twoSumHashTable);
    runTest("Mixed negative and positive (array)", negativesAndPositives, 4, {1, 4}, twoSumArray);
    runTest("Mixed negative and positive (hashtable)", negativesAndPositives, 4, {1, 4}, twoSumHashTable);
    runTest("Stress case 10000 elements (array)", stress, 19999, {9998, 9999}, twoSumArray);
    runTest("Stress case 10000 elements (hashtable)", stress, 19999, {9998, 9999}, twoSumHashTable);

    std::cout << "All TwoSum tests passed.\n";
    return EXIT_SUCCESS;
}
