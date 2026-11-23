#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        if (n <= 1) return;

        k %= n;
        if (k == 0) return;

        // 1. Reverse the entire array
        reverse(nums.begin(), nums.end());
        // 2. Reverse the first k elements
        reverse(nums.begin(), nums.begin() + k);
        // 3. Reverse the remaining n - k elements
        reverse(nums.begin() + k, nums.end());
    }
};  