#include <bits/stdc++.h>
using namespace std;
int t, n, a[99999], b[99999], c[99999], aa, bb, cc;
long long ans = 0;

void dfs1(int x, int y, int z, int s, long long an) {
	if (s == n + 1) {
		ans = max(an, ans);
		return ;
	}
	if (x < n / 2) {
		an += a[s];
		dfs1(x + 1, y, z, s + 1, an);
		an -= a[s];
	}
	if (y < n / 2) {
		an += b[s];
		dfs1(x, y + 1, z, s + 1, an);
		an -= b[s];
	}
	if (z < n / 2) {
		an += c[s];
		dfs1(x, y, z + 1, s + 1, an);
		an -= c[s];
	}
	return;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		dfs1(0, 0, 0, 1, 0);
		cout << ans << endl;
		ans = 0;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
	}
	return 0;
}

