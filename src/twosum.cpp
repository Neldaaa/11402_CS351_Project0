#include <vector>
#include <unordered_set>
#include <unordered_map>

// Two-pointer approach implementation
std::vector<int> twoSumArray(const std::vector<int>& nums, int target) {
    // Handle empty input
    if (nums.empty()) {
        return {-1, -1};
    }
    
    std::vector<int> result;
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            result.push_back(left);
            result.push_back(right);
            break;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    // Return [-1, -1] if no pair found
    if (result.empty()) {
        return {-1, -1};
    }
    
    return result;
}

// Hash table approach implementation
std::vector<int> twoSumHashTable(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> seen;
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (seen.find(complement) != seen.end()) {
            return {seen[complement], i};
        }
        seen[nums[i]] = i;
    }
    return {};
}