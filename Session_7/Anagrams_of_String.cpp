class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size(), m = p.size();

        if (m > n) return ans;

        vector<int> pFreq(26, 0), winFreq(26, 0);

        for (char c : p) pFreq[c - 'a']++;

        for (int i = 0; i < n; i++) {
            winFreq[s[i] - 'a']++;

            if (i >= m)
                winFreq[s[i - m] - 'a']--;

            if (winFreq == pFreq)
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};
