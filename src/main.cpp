#include <iostream>
#include <vector>
#include "twosum.h"

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = twoSumHashTable(nums, target);
    if (result.size() == 2 && result[0] >= 0) {
        std::cout << "TwoSumHashTable result: [" << result[0] << ", " << result[1] << "]\n";
    } else {
        std::cout << "No valid solution found.\n";
    }

    return 0;
}

