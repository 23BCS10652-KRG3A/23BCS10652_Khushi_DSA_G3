class Solution {
public:
    vector<vector<int>> rects;
    vector<long long> prefix;
    long long total;

    Solution(vector<vector<int>>& rects) {
        this->rects = rects;

        total = 0;

        for (auto &r : rects) {
            long long cnt =
                1LL * (r[2] - r[0] + 1) *
                (r[3] - r[1] + 1);

            total += cnt;
            prefix.push_back(total);
        }
    }

    vector<int> pick() {
        long long k = rand() % total + 1;

        int idx = lower_bound(prefix.begin(),
                              prefix.end(),
                              k) - prefix.begin();

        auto &r = rects[idx];

        int x = r[0] + rand() % (r[2] - r[0] + 1);
        int y = r[1] + rand() % (r[3] - r[1] + 1);

        return {x, y};
    }
};
