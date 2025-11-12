#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 20;
typedef long long ll;
int n, T, v[N][4], f[N];
ll ans;
bool flagb, flagc;

void init() {
	flagb = flagc = 0;
	ans = 0;
	for (int i = 1; i <= n + 3; i++) {
		v[i][1] = v[i][2] = v[i][3] = 0;
		f[i] = 0;
	}
}


ll dfs(int now, int a, int b, int c, ll ans) {
	if (now == n + 1)
		return ans;
	ll an = 0;
	if (a * 2 < n)
		an = max(dfs(now + 1, a + 1, b, c, ans + (ll)v[now + 1][1]), an);
	if (b * 2 < n)
		an = max(dfs(now + 1, a, b + 1, c, ans + (ll)v[now + 1][2]), an);
	if (c * 2 < n)
		an = max(dfs(now + 1, a, b, c + 1, ans + (ll)v[now + 1][3]), an);
	return an;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> T;
	while (T--) {

		cin >> n;
		init();
		for (int i = 1; i <= n; i++) {
			cin >> v[i][1] >> v[i][2] >> v[i][3];
			f[i] = -v[i][1];
			if (v[i][2])
				flagb = true;
			if (v[i][3])
				flagc = true;
		}
		if (!flagb && !flagc) {
			sort(f + 1, f + n + 1);
			for (int i = 1; i <= n / 2; i++)
				ans += f[i];
			cout << -ans << endl;
			continue;
		} else if (!flagc) {
			for (int i = 1; i <= n; i++)
				ans += max(v[i][1], v[i][2]);
			cout << ans << endl;
			continue;
		}

		ans = dfs(0, 0, 0, 0, (ll)0);
		cout << ans << endl;
	}
	return 0;
}