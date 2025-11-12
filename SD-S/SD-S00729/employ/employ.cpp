#include <bits/stdc++.h>
#define N 510
#define MOD 998244353
using namespace std;
int n, m, c[N], ans;
bool vis[N];
string s;
void dfs(int pos, int num) {
	if(pos == n + 1) {
		if(num >= m) ans = (ans + 1) % MOD;
		return;
	}
	if(num + (n - pos + 1) < m) return;
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		if(s[pos - 1] == '0' || pos - 1 - num >= c[i]) {
			vis[i] = 1;
			dfs(pos + 1, num);
			vis[i] = 0;
		} else {
			vis[i] = 1;
			dfs(pos + 1, num + 1);
			vis[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 1; i <= n; i++) cin >> c[i];
	dfs(1, 0);
	cout << ans;
	return 0;
}
