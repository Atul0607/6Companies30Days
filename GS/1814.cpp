class Solution {
public:
    int mod = 1e9+7;
    int reverseDigits(int num)
    {
        int rev_num = 0;
        while (num > 0) {
            rev_num = rev_num * 10 + num % 10;
            num = num / 10;
        }
        return rev_num;
    }
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> revnums;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            revnums.push_back(reverseDigits(nums[i]));
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]-revnums[i]) != mp.end()){
                ans+=(mp[nums[i]-revnums[i]])%mod;
                ans%=mod;
            }
            mp[nums[i]-revnums[i]]++;
        }
        return ans;
    }
};