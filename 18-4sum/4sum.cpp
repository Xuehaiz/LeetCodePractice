class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> four_sum;
        sort(nums.begin(), nums.end());
        int m = nums.size();
        if (m < 4) return four_sum;
        
        for (int i = 0; i < m - 3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < m - 2 ; j++) {
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                int k = j + 1;
                int l = m - 1;
                while (k < l) {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum < target) {
                        k++;
                        //while (k < l && nums[k] == nums[k-1]) k++;
                    } 
                    else if (sum > target) {
                        l--;
                        //while (k < l && nums[l] == nums[l+1]) l--;
                    }
                    else {
                        vector<int> vec;
                        vec.push_back(nums[i]);
                        vec.push_back(nums[j]);
                        vec.push_back(nums[k]);
                        vec.push_back(nums[l]);
                        four_sum.push_back(vec);
                        vec.clear();
                        k++;
                        while (k < l && nums[k] == nums[k-1]) k++;
                        l--;
                        while (k < l && nums[l] == nums[l+1]) l--;
                    }
                }
            }
        }
        return four_sum;
    }
};