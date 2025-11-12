#include <bits/stdc++.h>
using namespace std;
int c[1000], a[1000], ans = 0;
bool st[1000];
int n, m;
string s;

void dfs(int u) {
	if (u == n ) {
//		for (int i = 0; i < u; i++) {
//			cout << a[i] << " ";
//		}
//		cout << endl;
		int cnt = 0, wl = 0;
		for (int i = 0; i < u; i++) {
			//	cout << "a[i]=" << a[i] << "  wl=" << wl << endl;
			if (wl >= a[i])
				continue;
			else {
				if (s[i] == '1') {
					cnt++;
				} else
					wl += 1;
			}
			//	cout << cnt << " " << wl << " " << endl;
		}

		if (cnt >= m) {
			ans++;
			ans %= 998244353;
		}
		//cout << ans << endl;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (!st[i]) {
			a[u] = c[i];
			st[i] = true;
			dfs(u + 1);
			a[u] = 0;
			st[i] = false;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	memset(st, false, sizeof(st));
	memset(a, 0, sizeof(a));
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	dfs(0);
	cout << ans % 998244353 ;
	return 0;
}
