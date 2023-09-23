class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> map{{}, {}, {}};
        
        //Map Creation
        for(int i=0; i<triplets.size(); i++) {
            if(
                triplets[i][0] == target[0] &&
                triplets[i][1] <= target[1] &&
                triplets[i][2] <= target[2]
            ) {
                map[0].push_back(i);
            }
            
            if(
                triplets[i][1] == target[1] &&
                triplets[i][0] <= target[0] &&
                triplets[i][2] <= target[2]
            ) {
                map[1].push_back(i);
            }
            
            if(
                triplets[i][2] == target[2] &&
                triplets[i][0] <= target[0] &&
                triplets[i][1] <= target[1]
            ) {
                map[2].push_back(i);
            }
        }

        return (
            map[0].size() &&
            map[1].size() &&
            map[2].size()
        );
    }
};