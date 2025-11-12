#include <bits/stdc++.h>
#define int register int
#define ll long long
#define db double
#define AKIOI ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
using namespace std;
ll t, n, a[200005], ans, dp1[100005], dp2[100005], dp3[100005];

struct member {
	ll aa, bb, cc;
} c[200005];

bool cmp(member p, member q) {
	return p.aa > q.aa;
}

signed main() {
//	freopen("club.in", "r", stdin);
//	freopen("club.out", "w", stdout);

	AKIOI;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> c[i].aa >> c[i].bb >> c[i].cc;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = n / 2; j >= 1; j--) {
				if (c[j].aa > c[j].bb && c[j].aa > c[j].cc) {
					dp1[j] = dp1[j - 1] + c[j].aa;
					dp2[j] = dp2[j - 1];
					dp3[j] = dp3[j - 1];
				} else if (c[j].bb > c[j].aa && c[j].bb > c[j].cc) {
					dp1[j] = dp1[j - 1];
					dp2[j] = dp2[j - 1] + c[j].bb;
					dp3[j] = dp3[j - 1];
				} else {
					dp1[j] = dp1[j - 1];
					dp2[j] = dp2[j - 1];
					dp3[j] = dp3[j - 1] + c[i].cc;
				}
			}
		}
		cout << dp1[n / 2] + dp2[n / 2] + dp3[n / 2];
	}
	return 0;
}
//expected:25-pts
/*
5pts:强行枚举a2=a3=0时的情况，5pts。
满分解：dp，不过这个代码是强行贪心的，应该只能得不到25pts。
*/