#include <bits/stdc++.h>
using namespace std;
long long t, n, ans = 0;

struct st {
	long long bh, dy, de, ds, vis;
} a[1000000];

void dfs(long long dep, long long b1r, long long b2r, long long b3r, long long b1, long long b2, long long b3) {
	if (dep > n) {
		if (ans <= b1 + b2 + b3)
			ans =  b1 + b2 + b3;
		return;
	}
	if (b1r < n / 2 && a[dep].vis == 0) {
		a[dep].vis = 1;
		dfs(dep + 1, b1r + 1, b2r, b3r, b1 + a[dep].dy, b2, b3);
		a[dep].vis = 0;
	}
	if (b2r < n / 2 && a[dep].vis == 0) {
		a[dep].vis = 1;
		dfs(dep + 1, b1r, b2r + 1, b3r,  b1, b2 + a[dep].de, b3);
		a[dep].vis = 0;
	}
	if (b3r < n / 2 && a[dep].vis == 0) {
		a[dep].vis = 1;
		dfs(dep + 1, b1r, b2r, b3r + 1, b1, b2, b3 + a[dep].ds);
		a[dep].vis = 0;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].dy >> a[i].de >> a[i].ds;
			a[i].bh = i;
		}
		dfs(1, 0, 0, 0, 0, 0, 0);
		cout << ans << "\n";
		for (int i = 1; i <= n; i++) {
			a[i].dy = 0;
			a[i].de = 0;
			a[i].ds = 0;
			a[i].bh = 0;
			a[i].vis = 0;
		}
	}



	return 0;
}