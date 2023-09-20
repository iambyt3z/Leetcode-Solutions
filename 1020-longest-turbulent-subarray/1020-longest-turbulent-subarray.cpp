class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int len=arr.size();
        if(len==1) return 1;

        int res=1, l=0, r=0;
        bool dir=true;

        while(r < len-1) {
            if(l==r) {
                if(arr[r] > arr[r+1]) {
                    r++;
                    dir=true;
                }

                else if(arr[r] < arr[r+1]) {
                    r++;
                    dir=false;
                }

                else {
                    r++;
                    l++;
                }

                res = max(res, r-l+1);
            }

            else if(
                (dir && arr[r] < arr[r+1]) ||
                (!dir && arr[r] > arr[r+1])
            ) {
                r++;
                dir = !dir;
                res = max(res, r-l+1);
            }

            else  {
                l=r;
            }
        }

        return res;
    }
};