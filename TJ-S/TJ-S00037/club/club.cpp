#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int MAXN = 1e5 + 100;

struct S {
    int a, b, c;
//    bool operator < (const S& _) const {
//        return d < _.d;
//    }
} s[MAXN];

int t, n, cnt[4];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    cin.tie(0)->sync_with_stdio(0);

    cin >> t;
    while (t--) {
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        int ans = 0;
        vector<int> v1, v2, v3;
        for (int i = 1; i <= n; i++) {
            cin >> s[i].a >> s[i].b >> s[i].c;
            int mx = max(max(s[i].a, s[i].b), s[i].c);
            ans += mx;
            if (s[i].a == mx) {
                v1.push_back(mx - max(s[i].b, s[i].c));
                cnt[1]++;
            } else if (s[i].b == mx) {
                v2.push_back(mx - max(s[i].a, s[i].c));
                cnt[2]++;
            } else {
                v3.push_back(mx - max(s[i].a, s[i].b));
                cnt[3]++;
            }
        }
        int mc = max(cnt[1], max(cnt[2], cnt[3]));
        if (cnt[1] > n / 2) {
            sort(v1.begin(), v1.end());
            int dt = v1.size() - n / 2;
            for (int j = 0; j < dt; j++) {
                ans -= v1[j];
            }
        } else if (cnt[2] > n / 2) {
            sort(v2.begin(), v2.end());
            int dt = v2.size() - n / 2;
            for (int j = 0; j < dt; j++) {
                ans -= v2[j];
            }
        } else if (cnt[3] > n / 2) {
            sort(v3.begin(), v3.end());
            int dt = v3.size() - n / 2;
            for (int j = 0; j < dt; j++) {
                ans -= v3[j];
            }
        }
        cout << ans << endl;
    }

    return 0;
}
