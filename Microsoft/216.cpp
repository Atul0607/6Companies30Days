class Solution {
public:
    vector<vector<int>> ans;
    vector<int> arr;
    void f(int i,int k,int n,vector<int>& vec){
        if(!k || !n){
            if(!k && !n){
                ans.push_back(vec);
            }
            return ;
        }
        for(int j=i;j<=9;j++){
            if(n < i){
                return;
            }
            vec.push_back(j);
            f(j+1,k-1,n-j,vec);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> vec; 
        f(1,k,n,vec);
        return ans;
    }
};