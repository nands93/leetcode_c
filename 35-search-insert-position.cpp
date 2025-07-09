//https://leetcode.com/problems/search-insert-position/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] >= target) {
                return i;
            }
        }
        return nums.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    int result = sol.searchInsert(nums, target);
    // Expected output: 2
    cout << result << endl;
    return result;
}