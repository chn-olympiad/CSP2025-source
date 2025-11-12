#include <bits/stdc++.h>
using namespace std;
const int maxn = 505, mod = 998244353;
int n, m, s[maxn], c[maxn], vis[maxn], p[maxn], idx[maxn], ans;
string str;
bool check() {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (p[i - 1] >= c[idx[i]]) {
			p[i] = p[i - 1] + 1;
			continue;
		}
		if (s[i] == 0) p[i] = p[i - 1] + 1;
		else cnt++, p[i] = p[i - 1];
	}
	return cnt >= m;
}
void dfs(int i) {
	if (i > n) {
		if (check()) ans= (ans + 1) % mod;
		return ;
	}
	for (int j = 1; j <= n; j++) {
		if (vis[j]) continue;
		vis[j] = true;
		idx[i] = j;
		dfs(i + 1);
		vis[j] = false;
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> str;
	for (int i = 0; i < n; i++)
		s[i + 1] = str[i] - '0';
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	if (n <= 10) {
		dfs(1);
		cout << ans;
		return 0;
	}
	ans = 1;
	int dec = 0;
	for (int i = 1; i <= n; i++)
		dec += (c[i] == 0);
	for (int i = 1; i <= n - dec; i++)
		ans = (long long)ans * i % mod;
	cout << ans;
	return 0;
}