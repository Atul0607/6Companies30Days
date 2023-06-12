class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int sum=0;
        int f0 = 0;
        for(int i=0;i<n;i++){
            f0+=nums[i]*i;
            sum+=nums[i];
        }
        int ans = INT_MIN;
        for(int i=n-1;i>=0;i--){
            f0 = f0-(nums[i]*(n-1))+(sum-nums[i]);
            ans = max(ans,f0);
        }
        return ans;
    }
};