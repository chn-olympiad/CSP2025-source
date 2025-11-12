#include <bits/stdc++.h>
using namespace std;
long long t, n, sum = 1, num = 2;
long long ans;

struct myd {
	long long a1, a2, a3, cha;
} m[200010];
long long a[5];
long long c[5];

bool cmp(myd b, myd d) {
	return b.cha > d.cha;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> t;
	while (t--) {
		memset(c, 0, sizeof c);
		memset(m, 0, sizeof m);
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> m[i].a1 >> m[i].a2 >> m[i].a3;
			a[1] = m[i].a1, a[2] = m[i].a2, a[3] = m[i].a3;
			sort(a + 1, a + 4);
			m[i].cha = a[3] - a[2];
		}
		sort(m + 1, m + 1 + n, cmp);
		for (int i = 1; i <= n; i++) {
			if (m[i].a1 >= m[i].a2 && m[i].a1 >= m[i].a3) {
				if (c[1] < n / 2) {
					ans += m[i].a1;
					c[1]++;
				} else if (m[i].a2 >= m[i].a3) {
					ans += m[i].a2;
					c[2]++;
				} else if (m[i].a3 >= m[i].a2) {
					ans += m[i].a3;
					c[3]++;
				}
			} else if (m[i].a2 >= m[i].a1 && m[i].a2 >= m[i].a3) {
				if (c[2] < n / 2) {
					ans += m[i].a2;
					c[2]++;
				} else if (m[i].a1 >= m[i].a3) {
					ans += m[i].a1;
					c[1]++;
				} else if (m[i].a3 >= m[i].a1) {
					ans += m[i].a3;
					c[3]++;
				}
			} else if (m[i].a3 >= m[i].a1 && m[i].a3 >= m[i].a2) {
				if (c[3] < n / 2) {
					ans += m[i].a3;
					c[3]++;
				} else if (m[i].a1 >= m[i].a2) {
					ans += m[i].a1;
					c[1]++;
				} else if (m[i].a2 >= m[i].a1) {
					ans += m[i].a2;
					c[2]++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}