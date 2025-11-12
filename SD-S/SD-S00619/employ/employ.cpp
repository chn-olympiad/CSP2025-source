#include <bits/stdc++.h>

using namespace std;

const int N = 510, mod = 998244353;

int n, m;
string s;
int c[N];
int chs[N];
bool vis[N];

int ans = 0;
void dfs(int k) {
	if (k == n) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (i - cnt - 1 < c[chs[i]]) {
				cnt += (s[i] == '1');
			}
		}
		if (cnt >= m) ans++;
		return;
	}
	
//	if (n - k + cnt < m) return;
//	if (k == n) {
//		ans = (ans + 1) % mod;
//		return;
//	}
	
//	if (k == n) {
//		if (cnt >= m) ans++;
//	}
	
//	for (int i = 1; i <= n; i++) {
//		if (!vis[i]) {
//			vis[i] = true;
//			if (cnt < c[i]) {
//				cnt += (s[k + 1] == '1');
//				dfs(k + 1);
//				cnt -= (s[k + 1] == '1');
//			} else {
//				dfs(k + 1);
//			}
//			vis[i] = false;
//		}
//	}
//	
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			chs[k + 1] = i;
			dfs(k + 1);
			vis[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	cin >> n >> m;
	cin >> s;
	s = ' ' + s;
	
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	
	dfs(0);
	
	cout << ans << '\n';
	
	return 0;
}
