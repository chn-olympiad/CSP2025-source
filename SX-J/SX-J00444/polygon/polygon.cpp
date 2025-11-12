#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int n, a[5009], s;
bool b[5009];

void dfs(int x, int ss, int maa, int u) {
	if (x > n) {
		return ;
	}
	int p = 0;
	for (int i = u; i <= n; i++) {
		if (b[i] == 0) {
			b[i] = 1;
			p = a[i];
			ss += p;
			int ma = max(p, maa);
			u = i;
			if (x >= 3) {
				if (ss > 2 * ma) {
					++s;
					s %= MOD;
				}
			}
			dfs(x + 1, ss, ma, u);
			b[i] = 0;
			ss -= p;
		}
	}
	return ;
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n < 3) {
		cout << 0;
		return 0;
	}
	dfs(1, 0, 0, 1);
	cout << s;
	return 0;
}
