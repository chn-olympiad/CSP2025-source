#include <bits/stdc++.h>
using namespace std;
int c[5000];
bool vis[5000];
string s;
int n, m, ord[5000], cnt;

bool cmp() {
	int ct = 0;
	int fai = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '0') {
			fai++;
		} else if (fai >= c[ord[i]]) {
			fai++;
		} else {
			ct++;
		}
	}
	if (ct >= m) {
//		for (int i = 1; i <= n; i++) {
//			cout << ord[i] << ' ';
//		}
//		cout << endl;
		return 1;
	} else
		return 0;
}

void dfs (int x) {
	if (x > n) {
//		for (int i = 1; i <= n; i++) {
//			cout << ord[i] << ' ';
//		}
//		cout << endl;
		if (cmp()) {
			cnt++;
			cnt %= 998244353;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			ord[x] = i;
			vis[i] = 1;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	bool flag = 1;
	for (int j = 1; j <= n; j++) {
		cin >> c[j];
		if (c[j] == 0)
			flag = 0;
	}
	if (m == n) {
		if (flag) {
			long long ans = 1;
			for (int i = 2; i <= n; i++) {
				ans = (ans * i) % 998244353;
			}
			cout << ans;
			return 0;
		} else {
			cout << 0;
			return 0;
		}

	}
	dfs(1);
//	long long ans = 1;
//	for (int i = 2; i <= n; i++) {
//		ans = (ans * i) % 998244353;
//	}
//	cout << ans;
	cout << cnt << endl;
	return 0;
}