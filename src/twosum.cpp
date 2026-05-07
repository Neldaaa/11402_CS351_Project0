#include "twosum.h" 
#include <vector>
#include <unordered_set>
#include <unordered_map>

// Two-pointer approach implementation
// Brute force approach - works on unsorted arrays
std::vector<int> twoSumArray(const std::vector<int>& nums, int target) {
    if (nums.empty()) {
        return {-1, -1};
    }

    for (int i = 0; i < (int)nums.size() - 1; i++) {
        for (int j = i + 1; j < (int)nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

// Hash table approach implementation
std::vector<int> twoSumHashTable(const std::vector<int>& nums, int target) {
    // Handle empty input
    if (nums.empty()) {
        return {-1, -1};
    }
    
    std::unordered_map<int, int> seen;
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (seen.find(complement) != seen.end()) {
            return {seen[complement], i};
        }
        seen[nums[i]] = i;
    }
    
    // Return [-1, -1] if no pair found
    return {-1, -1};
}