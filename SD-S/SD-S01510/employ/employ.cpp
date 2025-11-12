#include<bits/stdc++.h>

using namespace std;
int n, m;
string s;
const int N = 510, MOD = 998244353;
int p[N], c[N], t[N];
int ans;
void dfs(int k) {
	if (k == n + 1) {
		int sum = 0, peo = 0;
		for (int i = 1; i <= n; i ++) {
			if (peo == m) {
				break;
			}
			if (sum < c[p[i]] && s[i - 1] == '1') peo ++;
			else sum ++;
		}
		if (peo == m) {
			ans ++;
			ans %= MOD;
		}
		return;
	}
	for (int i = 1; i <= n; i ++) {
		if (!t[i]) {
			p[k] = i;
			t[i] = 1;
			dfs(k + 1);
			p[k] = 0;
			t[i] = 0;
		}
	}
}
int jie(int n) {
	if (n == 1) {
		return 1;
	}
	return n * (jie(n - 1) % MOD) % MOD; 
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i ++) cin >> c[i];
	bool b = 1;
	for (int i = 0; i < s.length(); i ++) {
		if (s[i] != '1'){
			b = 0;
			break;
		}
	}
	if (b) {
		cout << jie(n) % MOD;
		return 0;
	}
	if (m == 1) {
		for (int i = 1; i <= n; i ++) {
			if (c[i] > 0) {
				ans = (ans + jie(n - 1)) % MOD;
			}
		}
		cout << jie(n) % MOD << endl;
		cout << ans;
		return 0;
	}
	dfs(1);
	cout << ans % MOD;
	return 0;
}
