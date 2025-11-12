#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, m;
long long ans;
string s;
int c[100010];
bool flag[100010];
void dfs(int cnt, int out, int pass) {
	if (pass == m) {
		long long p = 1;
		for (int i = 1; i <= n - cnt + 1; i++) p = p * i % MOD;
		ans = (ans + p) % MOD;
		return;
	}
	if (cnt == n + 1 || out > n - m) return;
	for (int i = 1; i <= n; i++) {
		if (flag[i]) continue;
		flag[i] = true;
		if (out >= c[i] || s[cnt-1] == '0') dfs(cnt + 1, out + 1, pass);
		else dfs(cnt + 1, out, pass + 1);
		flag[i] = false;
	}
}
int main () {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	std::ios::sync_with_stdio (false);
	std::cin.tie (0); std::cout.tie (0);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}

