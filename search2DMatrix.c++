class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& nums, int target) {
            int n=nums.size();
            int m=nums[0].size();
            int i=0,j=m-1;
            while(i<n && j>=0) {
                if(nums[i][j]==target) return true;
                else if(nums[i][j]>target){
                    j--;
                }else {
                    i++;
                }
            }
            return false;
        }
    };