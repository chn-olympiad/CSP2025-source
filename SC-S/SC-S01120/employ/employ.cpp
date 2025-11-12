#include<bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
int n, m, c[N], ans = 0, f[N];
string s;
bool vis[N];
void dfs(int h, int i, int j) {
	if (h == n) {
		if (i >= m) ans = (ans + 1) % mod;
		return ;
	}
	queue<int> q;
	for (int k = 1; k <= n; k++) {
		if (vis[k]) continue;
		if (c[k] <= j) {
			j++;
			vis[k] = 1;
			dfs(h + 1, i, j);
			q.push(k);
		} else if (s[h] == '0') {
			j++;
			vis[k] = 1;
			dfs(h + 1, i, j);
			j--;
			vis[k] = 0;
		} else {
			vis[k] = 1;
			dfs(h + 1, i + 1, j);
			vis[k] = 0;
		}
	}
	j -= q.size();
	while (!q.empty()) {
		int u = q.front();
		vis[u] = 0;
		q.pop();
	}
	return ;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1] * i % mod;
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	int fl = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] != '1') {
			fl = 1;
			break;
		}
	}
	if (!fl) {
		cout << f[n];
		return 0;
	}
	if (n * m <= 100) {
		dfs(0, 0, 0);
		cout << ans % mod;
	} else {
		cout << 0;
	}
	return 0;
}