class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int j = n - 1;
        int i = j - 1;
        while (i >= 0) {
            while (i < j) {
                if (nums[i] < nums[j]) {
                    swap(nums[i], nums[j]);
                    sort(nums.begin() + i + 1, nums.end());
                    return;
                } else {
                    j--;
                }
            }
            j = n - 1;
            i--;
        }
        sort(nums.begin(), nums.end());
    }
};