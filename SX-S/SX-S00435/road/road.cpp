#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+10, M = 1e4+10;

struct cs {
	int xb;
	bool lj;
};

struct dl {
	int ca, cb, fy;
	bool xt = 0;
};
dl a[N];
cs d[M];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		d[i].xb = i;
	for (int i = 1; i <= m; i++) {
		cin >> a[i].ca >> a[i].cb >> a[i].fy;
	}
	if (k == 0) {
		int sum = 0, ans = 0;
		while (sum < n) {
			for (int i = 1; i <= n; i++) {
				if (d[a[i].ca].lj == 0 && d[a[i].cb].lj == 0) {
					ans += a[i].fy;
					d[a[i].ca].lj = 1;
					d[a[i].cb].lj = 1;
					sum += 2;
				}
				if (d[a[i].ca].lj == 1 && d[a[i].cb].lj == 0) {
					ans += a[i].fy;
					d[a[i].cb].lj = 1;
					sum++;
				}
				if (d[a[i].cb].lj == 1 && d[a[i].ca].lj == 0) {
					ans += a[i].fy;
					d[a[i].ca].lj = 1;
					sum++;
				}
			}
		}
		cout << ans;
	}

	return 0;
}
