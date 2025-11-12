#include <bits/stdc++.h>

#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

constexpr int MaxN = 2e5 + 10;

struct Str {
	string a;
};
Str s[MaxN][2], q[MaxN][2];

int n, Q;

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> Q;
	for (int i = 1; i <= n; i++)
		cin >> s[i][0].a >> s[i][1].a;
	for (int i = 1; i <= Q; i++) {
		cin >> q[i][0].a >> q[i][1].a;
		int ans = 0;
		int len = q[i][0].a.length();
		for (int j = 1; j <= n; j++) {
			int rlen = s[j][0].a.length();
			for (int l = 0; l < len - rlen; l++) {
				string res1, res2;
				for (int t = 0; t < l; t++) {
					res1 += q[i][0].a[t];
					res2 += q[i][1].a[t];
				}
				res1 += s[j][0].a;
				res2 += s[j][1].a;
				for (int t = l + rlen; t < len; t++) {
					res1 += q[i][0].a[t];
					res2 += q[i][1].a[t];
				}
//				cerr << res1 << " " << res2 << "\n";
				if (res1 == q[i][0].a && res2 == q[i][1].a) {
//					cerr << j << " " << l << "\n";
					++ ans;
				}
			}
		}
		cout << ans << '\n';
	}
}
