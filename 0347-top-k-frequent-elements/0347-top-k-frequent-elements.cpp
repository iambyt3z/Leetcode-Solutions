class Solution {
    
#define pi pair<int, int> 
#define mp make_pair
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> freq;
        int len = nums.size();
        for(int i=0; i<len; i++){
            freq[nums[i]]++;
        }
        
        unordered_map <int, int> visited;
        priority_queue <pi, vector<pi>, greater<pi>> minh;
        
        for(int i=0; i<len; i++){
            if(visited.find(nums[i]) == visited.end()){
                minh.push( mp(freq[nums[i]], nums[i]) );
                visited[nums[i]]++;
            }
            
            else continue;
            
            if(minh.size() > k) minh.pop();
        }
        
        vector<int> res;
        while(minh.size()){
            res.push_back(minh.top().second);
            minh.pop();
        }
        
        return res;
    }
};