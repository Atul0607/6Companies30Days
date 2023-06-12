int div=0;
        for(int i=0;i<numsDivide.size();i++) div = __gcd(div,numsDivide[i]);
        sort(nums.begin(),nums.end());
        int del = 0;
        int i;
        for(i=0;i<nums.size();i++){
            if(div%nums[i] == 0) break;
            else del++;
        }
        if(i==nums.size()) return -1;
        return del;