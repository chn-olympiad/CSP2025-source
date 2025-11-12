#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, m, a[505], b[505], aaaa[10005];
bool f[505], te = true;
long long ans;
void dfs(int num, int yes, int no) {
	if (num == n && yes >= m) {
		ans = (ans + 1) % MOD;
		return ;
	}
	if (n - num + yes < m || num >= n) {
		return ;
	}
	for (int i = 1; i <= n; i++) {
		if (f[i] == 0) {
			f[i] = 1;
			aaaa[num] = i;
			if (no >= b[i] || a[num + 1] == 0) {
				dfs(num + 1, yes, no + 1);
			} else {
				dfs(num + 1, yes + 1, no);
			}
			f[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		a[i] = c - '0';
		if (a[i] == 0) {
			te = false;
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	if (n <= 20) {
		dfs(0, 0, 0);
		cout << ans << endl;
	} else if (te) {
		int ssss = 0;
		for (int i = 1; i <= n; i++) {
			if (b[i] == 0) {
				ssss++;
			}
		}
		n -= ssss;
		cout << n << endl;
		ans = 1;
		for (int i = 2; i <= n; i++) {
			ans = (ans * i) % MOD;
		}
		cout << ans << endl;
	} else {
		dfs(0, 0, 0);
		cout << ans << endl;
	}
	return 0;
}
