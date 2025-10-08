class Solution {
public:
    int bs(const vector<int>& p, long long v, long long s, int m) {
        int i = 0;
        int j = m - 1;
        int res = -1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if ((long long)v * p[mid] >= s) {
                res = mid;        // first index that satisfies product >= s
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return res;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            long long v = spells[i];
            int indv = bs(potions, v, success, m);
            ans[i] = (indv == -1 ? 0 : m - indv);
        }
        return ans;
    }
};
