class Solution {
public:
    bool isPalindrome(int l, int r, string &s) {
        while(l <= r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }

        return true;
    }

    bool validPalindrome(string s) {
        int l=0, r=s.length()-1;

        while(l<=r) {
            if(s[l] != s[r]) {
                return 
                    isPalindrome(l, r-1, s) ||
                    isPalindrome(l+1, r, s);
            }

            l++;
            r--;
        }

        return true;
    }
};