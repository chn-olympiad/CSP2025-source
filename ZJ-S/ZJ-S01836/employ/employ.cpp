#include <bits/stdc++.h>
using namespace std;
int a[505], p[505];
bool v[505];
string s;
const int MOD = 998244353;
int n, m, ans;
int count() {
	int res = 0;
	for (auto i : s) res += (i == '1');
	return res;
}
void dfs(int x, int fq, int jj) {
	if (x == n + 1) {
		int fq = 0, jj = 0;
		for (int i = 1; i <= n; i++) {
			if (fq + jj >= a[p[i]]) fq++;
			else if (s[i] == '0') jj++;
		}
//		cout << jj << ' ' << fq << '\n';
		if (n - jj - fq >= m) ans++;
		ans %= MOD;
		return;
	}
	for (int i = 1; i <= n; i++) {
		int nf = fq, nj = jj;
		if (!v[i]) {
			if (fq + jj >= a[i]) nf++;
			else if (s[x] == '0') nj++;
			if (n - nj - nf < m) continue;
			v[i] = 1;
			p[x] = i;
			dfs(x + 1, nf, nj);
			v[i] = 0;
		}
	}
	return;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (n <= 500) {
		dfs(1, 0, 0);
		cout << ans;
		return 0;
	}
	return 0;
}
//8
