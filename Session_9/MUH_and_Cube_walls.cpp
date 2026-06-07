#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w;
    cin >> n >> w;

    vector<long long> bear(n), ele(w);

    for (int i = 0; i < n; i++) cin >> bear[i];
    for (int i = 0; i < w; i++) cin >> ele[i];

    if (w == 1) {
        cout << n << '\n';
        return 0;
    }

    vector<long long> A, B;

    for (int i = 1; i < n; i++)
        A.push_back(bear[i] - bear[i - 1]);

    for (int i = 1; i < w; i++)
        B.push_back(ele[i] - ele[i - 1]);

    int m = B.size();

    vector<int> lps(m, 0);

    for (int i = 1, len = 0; i < m;) {
        if (B[i] == B[len]) {
            lps[i++] = ++len;
        } else {
            if (len)
                len = lps[len - 1];
            else
                i++;
        }
    }

    int ans = 0;

    for (int i = 0, j = 0; i < A.size();) {
        if (A[i] == B[j]) {
            i++;
            j++;

            if (j == m) {
                ans++;
                j = lps[j - 1];
            }
        } else {
            if (j)
                j = lps[j - 1];
            else
                i++;
        }
    }

    cout << ans << '\n';
    return 0;
}
