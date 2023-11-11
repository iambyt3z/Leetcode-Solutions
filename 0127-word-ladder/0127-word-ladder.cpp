class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int len = wordList.size();
        bool endWordFound = false;
        unordered_map<string, int> words;
        unordered_map<string, bool> visited;

        for(int i=0; i<wordList.size(); i++) {
            endWordFound = endWordFound || (wordList[i] == endWord);
            words[wordList[i]]++;
        }

        if(!endWordFound) return 0;

        queue<string> q;
        int l=1;
        q.push(beginWord);

        while(q.size()) {
            int w = q.size();
            
            while(w--) {
                string s = q.front();
                if(s == endWord) return l;
                
                q.pop();
                for(int i=0; i<s.length(); i++) {
                    string temp_s = s;

                    for(char ch='a'; ch<='z'; ch++) {
                        temp_s[i] = ch;

                        if(words.find(temp_s) != words.end()) {
                            q.push(temp_s);
                            words.erase(temp_s);
                        }
                    }
                }
            }

            l++;
        }

        return 0;
    }
};