class Solution {
public:
    long long f(long long n, long long L) {
        long long minv = std::max(0LL, n - L);
        long long maxv = std::min(n, L);

        return std::max(0LL, maxv - minv + 1);
    }

    long long distributeCandies(int n, int L) {
        long long ans = 0;

        for (int i = 0; i <= std::min(n, L); i++)
            ans += f((long long)(n - i), (long long)L);

        return ans;
    }
};

