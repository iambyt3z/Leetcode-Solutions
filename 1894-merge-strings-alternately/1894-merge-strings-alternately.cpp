class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1=0, l2=0;
        string res = "";

        while(l1 < word1.length() || l2 < word2.length()) {
            if(l1 < word1.length()) {
                res += word1[l1];
                l1++;
            }

            if(l2 < word2.length()) {
                res += word2[l2];
                l2++;
            }
        }

        return res;
    }
};