#include <algorithm>
#include <print>
#include <vector>

using namespace std;

class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int s = nums.size();
        for (int x = 0; x <= s; ++x) {
            int i = 0;
            while ((i < s) && (nums[i] < x))
                ++i;
            if (s - i == x)
                return x;
        }

        return -1;
    }
};

int main() {
    Solution s;

    vector<int> v1 = {3, 5};
    std::println("{}", s.specialArray(v1));

    vector<int> v2 = {0, 0};
    std::println("{}", s.specialArray(v2));

    vector<int> v3 = {0, 4, 3, 0, 4};
    std::println("{}", s.specialArray(v3));

    vector<int> v4 = {3, 6, 7, 7, 0};
    std::println("{}", s.specialArray(v4));

    vector<int> v5 = {0, 0};
    std::println("{}", s.specialArray(v5));

    return 0;
}
