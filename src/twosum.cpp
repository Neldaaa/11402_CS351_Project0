#include "twosum.h"
#include <unordered_map>

std::vector<int> twoSumArray(const std::vector<int>& nums, int target) {
    for (size_t i = 0; i < nums.size(); ++i) {
        for (size_t j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                return {static_cast<int>(i), static_cast<int>(j)};
            }
        }
    }
    return {-1, -1};
}

std::vector<int> twoSumHashTable(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> valueToIndex;
    valueToIndex.reserve(nums.size());

    for (size_t i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        auto it = valueToIndex.find(complement);
        if (it != valueToIndex.end()) {
            return {it->second, static_cast<int>(i)};
        }
        valueToIndex[nums[i]] = static_cast<int>(i);
    }

    return {-1, -1};
}
 
