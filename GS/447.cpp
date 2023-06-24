class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        if(n<3) return 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            map<int,int> mp;
            for(int j=0;j<n;j++){
                if(j==i) continue;
                int dis = (points[i][0]-points[j][0])*(points[i][0]-points[j][0])+(points[i][1]-points[j][1])*(points[i][1]-points[j][1]);
                mp[dis]++;
            }
            for(auto& it: mp){
                ans+=it.second*(it.second-1);
            }
        }
        return ans;
    }
};