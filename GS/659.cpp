class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        map<int,int> freq,need;
        for(int it: nums) freq[it]++;
        for(int i: nums){
            if(freq[i] <= 0) continue;
            else if(need[i] > 0){
                freq[i]--;
                need[i]--;
                need[i+1]++;
            }else if(freq[i] >0 && freq[i+1] >0 && freq[i+2] >0){
                freq[i]--;
                freq[i+1]--;
                freq[i+2]--;
                need[i+3]++;
            }else{
                return false;
            }
        }
        return true;
    }
};