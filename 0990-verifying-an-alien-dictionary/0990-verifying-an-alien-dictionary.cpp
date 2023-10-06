class Solution {
public:
    bool comp(string &s1, string &s2, unordered_map<char, int> &order) {
        int len1 = s1.length();
        int len2 = s2.length();
        int i1=0, i2=0;

        while(i1 < min(len1, len2)) {
            if(order[s1[i1]] < order[s2[i2]]) return true;
            else if(order[s1[i1]] > order[s2[i2]]) return false;

            i1++;
            i2++;
        }

        return (len1 <= len2);
    }

    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> umap;
        for(int i=0; i<order.length(); i++)
            umap[order[i]] = i+1;

        for(int i=0; i<words.size()-1; i++) {
            if(!comp(words[i], words[i+1], umap)) return false;
        }

        return true;
    }
};