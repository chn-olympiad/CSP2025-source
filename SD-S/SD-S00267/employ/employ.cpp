#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, o, cnt;
string S;
int c[10000];
bool use[10001];
void dfs(int k, int s) {
	if (k > n) {
		if (s >= m) {
			cnt++;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (use[i]) continue;
		use[i] = 1;
		if (k - 1 - s >= c[i]) {
			dfs(k + 1, s);
		} else {
			dfs(k + 1, s + (S[k - 1] == '1'));
		}
		use[i] = 0;
	}
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cin >> S;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	bool ff = 1;
	for (char c : S) if (c != '1') ff = 0;
	if (ff) {
		cnt = 1;
		for (int i = 1; i <= n; i++) {
			cnt = (cnt * i) % 998244353;
		}
		cout << cnt;
		return 0; 
	}
	dfs(1, 0);
	cout << cnt;
	return 0;
}
