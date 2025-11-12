#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
#define inf 1e9
using ll = long long;
using db = double;
using namespace std;
constexpr int N = 5e2 + 5, M = 1e6 + 5, P = 998244353;
int n, m, c[N];
char s[N];
bool vis[N];
ll ans;
void dfs(int x, int num) {
	if (x > n) {
		if (num >= m) ++ ans;
		return;
	}
	for (int i = 1; i <= n; ++ i)
		if (!vis[i]) {
			vis[i] = true, dfs(x + 1, num + (s[x] == '1' && x - 1 - num < c[i])), vis[i] = false;
		}
	return;
}
bool A = true, B = true;
ll dp[N][N];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> s[i];
		if (s[i] == '0') A = false;
	}
	for (int i = 1; i <= n; ++ i) {
		cin >> c[i];
		if (!c[i]) B = false;
	}
	if (n <= 10) {
		dfs(1, 0);
		cout << ans << '\n';
	}
	else if (m == n) {
		if (!A || !b) cout << "0\n";
		ans = 1;
		for (int i = 2; i <= n; ++ i) ans = ans * i % P;
		cout << ans << '\n';
	}
	return 0;
}