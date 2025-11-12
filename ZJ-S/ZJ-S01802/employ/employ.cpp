#include <iostream>
#include <cstdio>
using namespace std;
int n, m;
bool s[510];
int c[510];
int ans = 0;
void dfs(int vis[510], int luyong, int k) {
	if (k == n + 1) {
		for (int i = 1; i <= n; i++) {
			cout << vis[i] << " ";
		}
		cout << luyong << " ";
		cout << "\n";
		if (luyong >= m) {
			ans = (ans + 1) % 998244353;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			vis[i] = k;
//			if ()
//			cout << ((k - luyong - 1) >= c[k]) << " " << (s[k]) << "\n";
			if (((k - luyong - 1) >= c[k]) || s[k] == 0) {
				dfs(vis, luyong, k + 1);
			} else {
				dfs(vis, luyong + 1, k + 1);
			}
			vis[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	string ss;
	cin >> ss;
	for (int i = 0; i < ss.size(); i++) {
		s[i + 1] = ss[i] - '0';
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	int vis[510] = {};
	dfs(vis, 0, 1);
	cout << ans;
	return 0;
}
