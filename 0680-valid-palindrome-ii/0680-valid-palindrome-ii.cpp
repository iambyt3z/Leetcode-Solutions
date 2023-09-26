class Solution {
public:
    bool solve(int l, int r, int count, string &s) {
        if(l > r) return (count <= 1);
        if(count > 1) return false;

        if(s[l] == s[r]) return solve(l+1, r-1, count, s);

        return solve(l+1, r, count+1, s) || solve(l, r-1, count+1, s);
    }

    bool validPalindrome(string s) {
        return solve(0, s.length()-1, 0, s);
    }
};