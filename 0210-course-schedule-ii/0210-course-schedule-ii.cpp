class Solution {
public:
        bool dfs(
            int numCourses, 
            int course, 
            vector<bool> &completed, 
            vector<bool> &visited, 
            unordered_map<int, vector<int>> &prereq,
            vector<int> &res
        ) {
        if(completed[course]) return true;
        if(visited[course] && !completed[course]) return false;

        visited[course] = true;
        if(prereq.find(course) == prereq.end()) {
            completed[course] = true;
            res.push_back(course);
            return true;
        }

        vector<int> prerequisite = prereq[course];
        for(int i=0; i<prerequisite.size(); i++) {
            bool temp = dfs(numCourses, prerequisite[i], completed, visited, prereq, res);
            if(!temp)
                return false;
        }

        completed[course] = true;
        res.push_back(course);
        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> completed(numCourses, false);
        vector<bool> visited(numCourses, false);
        vector<int> res;

        unordered_map<int, vector<int>> prereq;
        for(int i=0; i<prerequisites.size(); i++) {
            if(prereq.find(prerequisites[i][0]) == prereq.end())
                prereq[prerequisites[i][0]] = {};

            prereq[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i=0; i<numCourses; i++) {
            if(completed[i]) continue;
            if(visited[i] && !completed[i]) return {};

            bool temp = dfs(numCourses, i, completed, visited, prereq, res);
            if(!temp) return {};
        }

        return res;
    }
};