#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, ans;

struct people {
	int a1, a2, a3;
} a[100005];

struct dui {
	int idx, x;
	bool operator <(const dui &A)const {
		return x > A.x;
	}
};
priority_queue<dui> q1;
priority_queue<dui> q2;
priority_queue<dui> q3;

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
		for (int i = 1; i <= n ; i++) {
			if (a[i].a1 > a[i].a2 && a[i].a1 > a[i].a3) {
				if (cnt1 < n / 2) {
					q1.push({i, a[i].a1 - max(a[i].a2, a[i].a3)});
					ans += a[i].a1;
					cnt1++;
				} else {
					int u = q1.top().idx;
					q1.pop();
					cnt1--;
					ans -= a[u].a1;
					int maxi = max(a[i].a2, a[i].a3), maxu = max(a[u].a2, a[u].a3);
					if (a[i].a1 + maxu > a[u].a1 + maxi) {
						q1.push({i, a[i].a1 - maxi});
						ans += a[i].a1 + maxu;
						cnt1++;
						if (maxu == a[u].a2) {
							q2.push({u, maxu - a[u].a3});
							cnt2++;
						} else {
							q3.push({u, maxu - a[u].a2});
							cnt3++;
						}
					} else {
						q1.push({u, a[u].a1 - maxu});
						ans += a[u].a1 + maxi;
						cnt1++;
						if (maxi == a[i].a2) {
							q2.push({i, maxi - a[i].a3});
							cnt2++;
						} else {
							q3.push({i, maxi - a[i].a2});
							cnt3++;
						}
					}
				}
			} else if (a[i].a2 > a[i].a1 && a[i].a2 > a[i].a3) {
				if (cnt2 < n / 2) {
					q2.push({i, a[i].a2 - max(a[i].a1, a[i].a3)});
					ans += a[i].a2;
					cnt2++;
				} else {
					int u = q2.top().idx;
					q2.pop();
					cnt2--;
					ans -= a[u].a2;
					int maxi = max(a[i].a1, a[i].a3), maxu = max(a[u].a1, a[u].a3);
					if (a[i].a2 + maxu > a[u].a2 + maxi) {
						q2.push({i, a[i].a2 - maxi});
						ans += a[i].a2 + maxu;
						cnt2++;
						if (maxu == a[u].a1) {
							q1.push({u, maxu - a[u].a3});
							cnt1++;
						} else {
							q3.push({u, maxu - a[u].a1});
							cnt3++;
						}
					} else {
						q2.push({u, a[u].a2 - maxu});
						ans += a[u].a2 + maxi;
						cnt2++;
						if (maxi == a[i].a1) {
							q1.push({i, maxi - a[i].a3});
							cnt1++;
						} else {
							q3.push({i, maxi - a[i].a1});
							cnt3++;
						}
					}
				}
			} else {
				if (cnt3 < n / 2) {
					q3.push({i, a[i].a3 - max(a[i].a1, a[i].a2)});
					ans += a[i].a3;
					cnt3++;
				} else {
					int u = q3.top().idx;
					q3.pop();
					cnt3--;
					ans -= a[u].a3;
					int maxi = max(a[i].a2, a[i].a1), maxu = max(a[u].a2, a[u].a1);
					if (a[i].a3 + maxu > a[u].a3 + maxi) {
						q3.push({i, a[i].a3 - maxi});
						ans += a[i].a3 + maxu;
						cnt3++;
						if (maxu == a[u].a2) {
							q2.push({u, maxu - a[u].a1});
							cnt2++;
						} else {
							q1.push({u, maxu - a[u].a2});
							cnt1++;
						}
					} else {
						q3.push({u, a[u].a3 - maxu});
						ans += a[u].a3 + maxi;
						cnt3++;
						if (maxi == a[i].a2) {
							q2.push({i, maxi - a[i].a1});
							cnt2++;
						} else {
							q1.push({i, maxi - a[i].a2});
							cnt1++;
						}
					}
				}
			}
		}
		while (!q1.empty()) {
			q1.pop();
		}
		while (!q2.empty()) {
			q2.pop();
		}
		while (!q3.empty()) {
			q3.pop();
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}