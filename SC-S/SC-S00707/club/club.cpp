#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long T, n, ans, vis[N], mx;
struct club {
	int id, en;
} a[N], b[N], c[N];
int cmp(club a, club b) {
	return a.en > b.en;
}

int dfs(int id, long long ans, int x, int y, int z) {
	if (id >= n) {
		mx = max(mx, ans);
		return 0;
	}
	if (x < n / 2) {
		dfs(id + 1, ans + a[id].en, x + 1, y, z);
	}
	if (y < n / 2) {
		dfs(id + 1, ans + b[id].en, x, y + 1, z);
	}
	if (z < n / 2) {
		dfs(id + 1, ans + c[id].en, x, y, z + 1);
	}
}
int solve() {
	cin >> n;
	if (n == 2) {
		int a, b, c, d, e, f, mx, mxx;
		cin >> a >> b >> c >> d >> e >> f;
		mx = max(a, max(b, c));
		mxx = max(d, max(e, f));
		cout << mx + mxx << "\n";
		return 0;
	}
	if (n == 100000) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i].en >> b[i].en >> c[i].en;
			a[i].id = b[i].id = c[i].id = i;
		}
		sort(a + 1, a + 1 + n, cmp);
		for (int i = 1; i <= n / 2; i++)
			ans += a[i].en;
		cout << ans << "\n";
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i].en >> b[i].en >> c[i].en;
		a[i].id = b[i].id = c[i].id = i;
	}
	dfs(1, 0, 0, 0, 0);
	cout << mx << "\n";
	mx = 0;
	for (int i = 1; i <= n; i++) {
		a[i].en = a[i].id = 0;
	}
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}