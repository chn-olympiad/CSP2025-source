#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
string cs;
bool v[505], vis[505];
int c[505];

void dfs(int dep, int cnt) {
	if (dep > n) {
		ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0 && cnt < c[i]) {
			vis[i] = 1;
			if (v[dep] = 1) {
				dfs(dep + 1, cnt + 1);
			} else {
				dfs(dep + 1, cnt);
			}
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> cs;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < n; i++) {
		if (cs[i] == '0') {
			v[i + 1] = 0;
		} else {
			v[i + 1] = 1;
		}
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}