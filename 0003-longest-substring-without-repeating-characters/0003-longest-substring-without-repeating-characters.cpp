class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> umap;
        int len = s.length(), res = 0;

        if(len == 0) return 0;

        int start = 0, end = 0;
        bool expand = true;
        char lastRepeated = '0';

        res = 1;
        umap[s[0]] = 1;

        while(start <= end && start < len && end < len) {
            if(expand) {
                end++;
                if(end == len) break;

                umap[s[end]]++;

                if(umap.find(s[end]) != umap.end() && umap[s[end]] > 1) {
                    lastRepeated = s[end];
                    expand = false;
                }

                else {
                    res = max(res, end - start + 1);
                }
            }

            else {
                umap[s[start]]--;
                
                if(s[start] == lastRepeated) {
                    lastRepeated = '0';
                    expand = true;
                }

                start++;
            }
        }

        return res;
    }
};