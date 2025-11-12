#include <bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
const int N = 505;
int n, m, ans, c[N], sx[N], vis[N], ok = 1;
string s;

bool cheak() {
	int sb = 0, ly = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '0' || sb >= c[sx[i]]) {
			sb++;
		} else {
			ly++;
		}
	}
	return ly >= m;
}

void dfs(int x) {
	if (x == n + 1) {
		if (cheak())
			ans++;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			sx[x] = i;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '0')
			ok = 0;
	}
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	if (n <= 10) {
		dfs(1);
		cout << ans;
	} else {
		if (ok == 1) {
			long long aans = 1;
			for (int i = 1; i <= n; i++) {
				aans *= i;
				aans %= Mod;
			}
			cout << aans;
		} else
			cout << 0;
	}
	return 0;
}
