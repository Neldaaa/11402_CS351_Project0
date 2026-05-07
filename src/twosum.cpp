#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numMap; // value -> index
    
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        // Check if complement exists in map
        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }
        
        // Store current number and its index
        numMap[nums[i]] = i;
    }
    
    return {-1, -1}; // No solution found
}