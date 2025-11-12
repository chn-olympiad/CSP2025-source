#include <bits/stdc++.h>
using namespace std;
int c[505], n, m, sum, vis[505], maxxpass;
string s;

void dfs(int i, int pass, int ans) {
	vis[i] = 1;
	if (s[ans - 1] == '0') {
		pass++;
	} else if (pass >= c[i]) {
		pass++;
	}

	if (ans == n && n - pass >= m) {
		sum++;
		vis[i] = 0;
		return;
	}

	if (n - pass < m) {
		vis[i] = 0;
		return;
	}


	//时间复杂度大头
	for (int j = 1; j <= n; j++) {
		if (vis[j] == 0) {
			dfs(j, pass, ans + 1);
		}
	}

	vis[i] = 0;

	return;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, 0, 1);
	}
	cout << sum % 998 % 244 % 353;
	//2n
	return 0;
}