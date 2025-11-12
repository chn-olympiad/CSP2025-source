#include <bits/stdc++.h>
using namespace std;
int n, m, ans, flag = 1;
int c[1000];
int vis[1000];
string s;

void dfs(int dep, int cntg, int cntbg) {
	if (n - cntbg < m )
		return;
	if (dep > n) {
		if (cntg >= m)
			ans++;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 1)
			continue;
		if (s[dep - 1] - '0' == 0 || cntbg >= c[i]) {
//			cout << 'a' << dep + 1 << " " << cntg << " " << cntbg + 1 << i << "\n";
			vis[i] = 1;
			dfs(dep + 1, cntg, cntbg + 1);
			vis[i] = 0;
		} else {
//			cout << 'b' << dep + 1 << " " << cntg + 1 << " " << cntbg << i << "\n";
			vis[i] = 1;
			dfs(dep + 1, cntg + 1, cntbg);
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}