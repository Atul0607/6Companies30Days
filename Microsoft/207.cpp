class Solution {
public:
    bool topologicalSort(vector<vector<int>> &graph, vector<int> &indegree){
        int count = 0;
        queue<int> q;
        for(int i=0; i<indegree.size(); i++)
            if(indegree[i] == 0) q.push(i);
        while(q.empty() == false){
            int curr = q.front();
            q.pop();
            for(auto i: graph[curr]){
                indegree[i] -= 1;
                if(indegree[i] == 0) {
                    q.push(i);
                }
            }
            count++;
        }
        return graph.size() == count;
    }
    bool canFinish(int nC, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(nC);
        vector<int> indegree(nC, 0);
        for(auto v: prerequisites){
            graph[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        bool ans = topologicalSort(graph, indegree);
        return ans;
    }
};