#include <iostream>
#include <string.h>
using namespace std;
const int MOD = 998244353;
const int N = 20;
int n, m, c[N], vis[N], ans = 0;
string s;
void dfs(int cnt, int k, int f) {
	if (cnt == n && k >= m) {
		ans++;
		ans %= MOD;
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (f > c[i]) return ; 
		if (!vis[i]) {
			vis[i] = 1;
			if (s[cnt] == '0') dfs(cnt + 1, k, f + 1);
			else dfs(cnt + 1, k + 1, f);
			vis[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	dfs(0, 0, 0);
	cout << ans << '\n';
	return 0;
}
