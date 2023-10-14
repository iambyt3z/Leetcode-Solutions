class Solution {
public:
    unordered_map<int, int> calcPrereq(
        int course,
        vector<bool> &visited,
        unordered_map<int, vector<int>> &prereq,
        unordered_map<int, unordered_map<int, int>> &allPrereqs
    ) {
        if(visited[course])
            return allPrereqs[course];

        visited[course] = true;
        unordered_map<int, int> prereqForCourse;
        vector<int> pr = prereq[course];

        for(int i=0; i<pr.size(); i++) {
            prereqForCourse[pr[i]]++;

            unordered_map<int, int> prOfPr = calcPrereq(pr[i], visited, prereq, allPrereqs);

            for(auto it=prOfPr.begin(); it!=prOfPr.end(); it++)
                prereqForCourse[it->first]++;
        }

        allPrereqs[course] = prereqForCourse;
        return prereqForCourse;
    }

    vector<bool> checkIfPrerequisite(
        int numCourses, 
        vector<vector<int>>& prerequisites, 
        vector<vector<int>>& queries
    ) {
        vector<bool> completed(numCourses, false);
        vector<bool> visited(numCourses, false);
        unordered_map<int, unordered_map<int, int>> allPrereqs;

        unordered_map<int, vector<int>> prereq;
        for(int i=0; i<prerequisites.size(); i++) {
            if(prereq.find(prerequisites[i][1]) == prereq.end())
                prereq[prerequisites[i][1]] = {};

            prereq[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<bool> res;
        for(int i=0; i<queries.size(); i++) {
            int u = queries[i][0], v = queries[i][1];

            if(allPrereqs.find(v) != allPrereqs.end()) {
                unordered_map<int, int> pr = allPrereqs[v];
                res.push_back( (pr.find(u) != pr.end()) );
                continue;
            }

            unordered_map<int, int> pr = calcPrereq(v, visited, prereq, allPrereqs);
            res.push_back( (pr.find(u) != pr.end()) );
        }

        return res;
    }
};