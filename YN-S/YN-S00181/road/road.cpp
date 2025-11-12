#include <bits/stdc++.h>
using namespace std;
long long n, m, k, b[1000000], vis[1000000], jg = LONG_LONG_MAX, ans = 0;
vector<long long>a[2005];
set<long long>v;

void dfs(long long dep) {
	if (dep > m) {
		long long flag = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			jg = min(jg, ans);
		}
		ans = 0;
		return;
	}
	if (vis[a[dep][0]] == 0 || vis[a[dep][1]] == 0) {
		vis[a[dep][0]] = 1, vis[a[dep][1]] = 1;
		ans += a[dep][2];
		dfs(dep + 1);
		vis[a[dep][0]] = 0, vis[a[dep][1]] = 0;
	}
	dfs(dep + 1);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		long long x, y, z;
		cin >> x >> y >> z;
		a[i].push_back(x);
		a[i].push_back(y);
		a[i].push_back(z);
	}
	for (int i = 1; i <= k; i++) {
		long long x, y;
		cin >> x;
		for (int j = 1; j <= n; j++) {
			cin >> y;
			b[i] = min(b[i], x + y);
		}
	}
	if (k == 0) {
		dfs(1);
		cout << jg << "\n";
	} else {
		long long cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += b[i];
		}
		cout << cnt << "\n";
	}




	return 0;
}