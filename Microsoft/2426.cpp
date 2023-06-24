class Solution {
public:
    long long count = 0;
    void Count(vector<int>& v,int st,int mid,int end,int diff){
        int l = st,r= mid+1;
        while(l<=mid && r<=end){
            if(v[l] <= (v[r]+diff)){
                count+=(end-r+1);
                l++;
            }else{
                r++;
            }
        }
        sort(v.begin()+st,v.begin()+end+1);
    }
    void mergesort(vector<int>& v,int st,int end,int diff){
        if(st==end) return;
        int mid = st+(end-st)/2;
        mergesort(v,st,mid,diff);
        mergesort(v,mid+1,end,diff);
        Count(v,st,mid,end,diff);
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int> v;
        int n = nums1.size();
        for(int i=0;i<n;i++) v.push_back(nums1[i]-nums2[i]);
        mergesort(v,0,n-1,diff);
        return count;
    }
};