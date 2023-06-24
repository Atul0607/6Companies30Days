class Solution {
public:
    int bob_inc = 0;
    bool dfs(vector<vector<int>>& graph, vector<bool>& vis, int src, unordered_map<int,int>& path,int time){
        path[src] = time;
        vis[src] = true;
        if(src==0) return true;
        for(auto it: graph[src]){
            if(!vis[it]){
                if(dfs(graph,vis,it,path,time+1)) return true;
            }
        }
        path.erase(src);
        return false;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_map<int,int> path;
        vector<bool> vis(n,false);
        dfs(graph,vis,bob,path,0);

        queue<vector<int>> q;
        q.push({0,0,0});
        vis.assign(n,false);
        int ans = INT_MIN;

        while(!q.empty()){
            int src = q.front()[0];
            int time = q.front()[1];
            int income = q.front()[2];
            q.pop();
            vis[src] = true;

            if(path.find(src) == path.end()) income+=amount[src];
            else{
                if(time<path[src]) income+=amount[src];
                else if(time == path[src]) income+=(amount[src]/2);
            }

            if(graph[src].size() == 1 && src!=0) ans=max(ans,income);

            for(auto it: graph[src]){
                if(!vis[it]) q.push({it,time+1,income});
            }
        }
        return ans;
    }
};