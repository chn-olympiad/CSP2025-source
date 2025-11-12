#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int N = 5e3 + 7, M = 1e4;
int n, a[N], sum[N], dp[N][N];
const int mod = 998244353;
void IOS() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	return ;
}
void file() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	return ;
}
void __init() {
	file();
//	IOS();
	return ;
}
LL ans = 0;
bool vis[N];
void dfs(int x, int sum, int num) {
	if (sum > 2 * a[x] && num >= 3) {
		++ans;
	}
	for (int i = x; i <= n; ++i) {
		if (!vis[i]) {
			vis[i] = 1;
			dfs(i, sum + a[i], num + 1);
			vis[i] = 0;
		}
	}
	return ;
}
int Max;
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		Max = max (Max, a[i]);
	}
	sort (a + 1, a + n + 1);
	if (n <= 10) {
		dfs(1, 0, 0);
		cout << ans % mod << '\n';
		return ;
	}
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
	}
	if (Max == 1) {
		
	}
	return ;
}
int main() {
	__init();
	LL _ = 1;
//	cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}
