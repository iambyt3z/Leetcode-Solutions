class Solution {
public:
    int distributeCandies(int n, int limit) {
        int res=0;
        for(int i=0; i<=n; i++) {
            for(int j=0; j<=n-i; j++) {
                int k = n-i-j;
                if(
                    i <= limit &&
                    j <= limit &&
                    k <= limit
                ) res++;
            }
        }

        return res;
    }
};