#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353;
int n, m, a[509], ss;
string b;
bool c[509];

void dfs(int x, int noo, int s) {
	if (s >= m) {
		++ss;
		ss %= 998244353;
		return ;
	}
	if (x > n)
		return ;
	for (int i = 1; i <= n; i++) {
		if (c[i] == 1) {
			continue;
		}
		int p = i, yy = 0, xx = 0;
		c[i] = 1;
		if (b[x - 1] == '0') {
			++noo;
			yy = 1;
		} else {
			if (a[p] > noo) {
				++s;
				xx = 1;
			} else {
				++noo;
				yy = 1;
			}
		}
		dfs(x + 1, noo, s);
		if (yy)
			--noo;
		if (xx)
			--s;
		c[i] = 0;
//		cout << noo << " " << s << endl;
	}
	return ;
}

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> b;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dfs(1, 0, 0);
	cout << ss;
	return 0;
}

