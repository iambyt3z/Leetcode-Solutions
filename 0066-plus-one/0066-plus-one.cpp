class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int ind = len-1, carry = 1;

        while(ind >= 0 && carry > 0) {
            int sum = digits[ind] + carry;
            digits[ind] = sum % 10;
            carry = sum / 10;
            ind--;
        }

        if(carry > 0) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};