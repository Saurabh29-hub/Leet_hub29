class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Create adjacency list
        vector<vector<int>> adj(numCourses);
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]); // course depends on prerequisite
        }

        // Calculate indegree
        vector<int> ind(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                ind[it]++;
            }
        }

        // Push all nodes with 0 indegree
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (ind[i] == 0) q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                ind[it]--;
                if (ind[it] == 0) q.push(it);
            }
        }

        return topo.size() == numCourses;
    }
};
