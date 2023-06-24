class Solution {
public:
    bool isValid(int r,int c,int n,int m){
        return r>=0 && c>=0 && r<n && c<m;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> ans;
        int n = grid.size();
        int m = grid[0].size();
        set<int> sums;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sums.insert(grid[i][j]);
            }
        }
        for(int i=1;i<=50;i++){
            for(int r=0;r<n;r++){
                for(int c=0;c<m;c++){
                    if(isValid(r-i,c,n,m) && isValid(r,c-i,n,m) && isValid(r+i,c,n,m) && isValid(r,c+i,n,m)){
                        int sum = grid[r+i][c]+grid[r-i][c]+grid[r][c+i]+grid[r][c-i];
                        for(int diag = 1;diag<i;diag++){
                            sum+=grid[r-diag][c+i-diag];
                        }
                        for(int diag = 1;diag<i;diag++){
                            sum+=grid[r-diag][c-i+diag];
                        }
                        for(int diag = 1;diag<i;diag++){
                            sum+=grid[r+diag][c+i-diag];
                        }
                        for(int diag = 1;diag<i;diag++){
                            sum+=grid[r+diag][c-i+diag];
                        }
                        sums.insert(sum);
                    }
                }
            }
        }
        priority_queue<int> pq;
        for(auto it: sums) pq.push(it);
        while(!pq.empty() && ans.size()<3){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};