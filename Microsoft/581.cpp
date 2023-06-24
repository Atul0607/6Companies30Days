class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX,maxi=INT_MIN;
        bool flag = false;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) flag = true;
            if(flag) mini = min(mini,nums[i]);
        }
        flag = false;
        for(int i=n-2;i>=0;i--){
            if(nums[i] > nums[i+1]) flag = true;
            if(flag) maxi=max(maxi,nums[i]);
        }
        int st=0,end=n-1;
        for(st=0;st<n;st++){
            if(mini < nums[st]) break;
        }
        for(end = n-1;end>=0;end--){
            if(maxi>nums[end]) break;
        }
        return end-st<0?0:end-st+1;
    }
};