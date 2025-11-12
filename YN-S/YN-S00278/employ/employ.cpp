#include <bits/stdc++.h>
using namespace std;
int n, m, ans;
string s;
int a[505];
bool vis[505];
int c[505];
const int mod = 998244353;

bool ch() {
	bool mianshi[505];
	int pepole = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			int m = 0;
			for (int k = 1; k <= n; k++) {
				if (mianshi[i])
					m++;
				if (m >= a[c[i]]) {
					break;
					mianshi[i] = 1;
				}
			}
			if (m >= a[c[i]])
				mianshi[i] = 1;
		}
		if (s[i] == '0' || mianshi[i])
			mianshi[i] = 1;
		else
			pepole++;
	}
	return pepole >= m;
}

void dfs(int dep) {
	if (dep == n + 1) {
		if (ch()) {
			ans++;
			ans %= mod;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			c[dep] = i;
			dfs(dep + 1);
			vis[i] = 0;
			c[dep] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (n <= 10) {
		dfs(1);
		cout << ans;
	} else
		cout << 0;
	return 0;
}
