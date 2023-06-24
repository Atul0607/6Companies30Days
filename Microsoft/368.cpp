class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> dp(n);
        vector<int> res;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0 && dp[j].size()>dp[i].size()) dp[i] = dp[j];
            }
            dp[i].push_back(nums[i]);
            if(res.size() < dp[i].size()) res = dp[i];
        }
        return res;
    } 
};