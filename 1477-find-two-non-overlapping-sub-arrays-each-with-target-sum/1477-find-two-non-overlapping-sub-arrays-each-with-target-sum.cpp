class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int INF = n + 1;
        vector<int> best(n, INF);

        int l = 0;
        int curr = 0;
        int minLen = INF;
        int ans = INF;

        for (int r = 0; r < n; r++) {
            curr += arr[r];

            while (curr > target) {
                curr -= arr[l];
                l++;
            }

            if (curr == target) {
                int len = r - l + 1;

                if (l > 0 && best[l - 1] != INF) {
                    ans = min(ans, len + best[l - 1]);
                }

                minLen = min(minLen, len);
            }

            best[r] = minLen;
        }

        return ans == INF ? -1 : ans;
    }
};