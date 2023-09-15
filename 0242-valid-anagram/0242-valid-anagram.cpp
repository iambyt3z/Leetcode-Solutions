class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> umaps, umapt;
    for(int i=0; i<s.length(); i++)
      umaps[s[i]]++;

    for(int j=0; j<t.length(); j++)
      umapt[t[j]]++;

    for(auto it=umaps.begin(); it!=umaps.end(); it++) {
      if(umapt.find(it->first) == umapt.end()) return false;

      umapt[it->first] -= it->second;
      if(umapt[it->first] != 0) return false;
      umapt.erase(it->first);
    }

    return (umapt.size() == 0);
  }
};