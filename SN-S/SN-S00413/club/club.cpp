#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int t, n, a[N][3], fl, b[N], fl2, c[N];
vector<int> v1, v2, v3;
int a1, a2, a3, res;

void dfs(int k, int l1, int l2, int l3, int now) {
	if (k > n) {
		res = max(res, now);
		return;
	}
	if ((l1 + 1) <= n / 2) {
		if (now + a[k][0] + (c[n] - c[k - 1]) <= res) {
			return;
		}
		dfs(k + 1, l1 + 1, l2, l3, now + a[k][0]);
	}
	if ((l2 + 1) <= n / 2) {
		if (now + a[k][1] + (c[n] - c[k - 1]) <= res) {
			return;
		}
		dfs(k + 1, l1, l2 + 1, l3, now + a[k][1]);
	}
	if ((l3 + 1) <= n / 2) {
		if (now + a[k][2] + (c[n] - c[k - 1]) <= res) {
			return;
		}
		dfs(k + 1, l1, l2, l3 + 1, now + a[k][2]);
	}
	return;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		fl = 1;
		fl2 = 1;
		a1 = a2 = a3 = 0;
		v1.clear();
		v2.clear();
		v3.clear();
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
			if (a[i][1] || a[i][2]) {
				fl = 0;
			}
			if (a[i][2]) {
				fl2 = 0;
			}
			b[i] = a[i][0];
			if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) {
				v1.push_back(i);
				a1 += a[i][0];
			} else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) {
				v2.push_back(i);
				a2 += a[i][1];
			} else {
				v3.push_back(i);
				a3 += a[i][2];
			}
			c[i] = c[i - 1] + max(a[i][0], max(a[i][1], a[i][2]));
		}
		if (fl) {
			sort(b + 1, b + n + 1, greater<int>());
			int ans = 0;
			for (int i = 1; i <= n / 2; i++) {
				ans += b[i];
			}
			printf("%d\n", ans);
		} else {
			int s1 = v1.size(), s2 = v2.size(), s3 = v3.size();
			if (s1 <= n / 2 && s2 <= n / 2 && s3 <= n / 2) {
				printf("%d\n", a1 + a2 + a3);
			} else {
				if (fl2) {
					int dd = max(s1, s2) - n / 2, jss = 0;
					vector<int> js;
					if (s1 > s2) {
						for (int i = 0; i < v1.size(); i++) {
							js.push_back(a[v1[i]][0] - a[v1[i]][1]);
						}
					} else {
						for (int i = 0; i < v2.size(); i++) {
							js.push_back(a[v2[i]][1] - a[v2[i]][0]);
						}
					}
					sort(js.begin(), js.end());
					for (int i = 0; i < dd; i++) {
						jss += js[i];
					}
					printf("%d\n", a1 + a2 - jss);
				} else {
					res = 0;
					dfs(1, 0, 0, 0, 0);
					printf("%d\n", res);
				}
			}
		}
	}
	return 0;
}
