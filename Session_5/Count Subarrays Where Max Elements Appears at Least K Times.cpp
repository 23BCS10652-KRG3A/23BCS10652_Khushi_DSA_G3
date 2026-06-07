class Solution {
public:
    void generate(vector<int>& nums, int idx, int end,
                  long long sum, vector<long long>& res) {
        if (idx == end) {
            res.push_back(sum);
            return;
        }

        generate(nums, idx + 1, end, sum, res);
        generate(nums, idx + 1, end, sum + nums[idx], res);
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int mid = n / 2;

        vector<long long> left, right;

        generate(nums, 0, mid, 0, left);
        generate(nums, mid, n, 0, right);

        sort(right.begin(), right.end());

        long long ans = LLONG_MAX;

        for (long long x : left) {
            long long target = goal - x;

            auto it = lower_bound(right.begin(), right.end(), target);

            if (it != right.end())
                ans = min(ans, llabs(x + *it - goal));

            if (it != right.begin()) {
                --it;
                ans = min(ans, llabs(x + *it - goal));
            }
        }

        return (int)ans;
    }
};
