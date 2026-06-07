class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;

        vector<pair<char,int>> seg;

        for (int i = 0; i < s.size();) {
            int j = i;

            while (j < s.size() && s[j] == s[i]) j++;

            seg.push_back({s[i], j - i});

            if (s[i] == '1')
                ones += (j - i);

            i = j;
        }

        int gain = 0;

        for (int i = 1; i + 1 < seg.size(); i++) {
            if (seg[i].first == '1' &&
                seg[i - 1].first == '0' &&
                seg[i + 1].first == '0') {

                gain = max(gain,
                           seg[i - 1].second +
                           seg[i + 1].second);
            }
        }

        return ones + gain;
    }
};
