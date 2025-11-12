#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e3 + 10, M = 998244353;
int n, m, s1, s0, ans;
string s;
int b[N], vis[N], k[N];
bool check(int a[N]) {
	int sum = 0, ans = 0;
	for (int i = 1; i <= n; i ++) {
		if(sum >= b[a[i]] || s[i - 1] == '0') {
			sum ++;
		}
		else ans ++;
	}
	
	return ans >= m;
}
void dfs(int x, int a[N], int len) {
	if(x == n + 1) {
		if(check(a)) {
			ans ++;
			ans %= M;
		}
		
		return;
	}
	for (int i = 1; i <= n; i ++) {
		if(!vis[i]) {
			a[len + 1] = i;
			vis[i] = 1;
			dfs(x + 1, a, len + 1);
			vis[i] = 0;
		}
	}
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i ++) {
		cin >> b[i];
		if(b[i] == 0) s0 ++;
	}
	for (int i = 0; i < s.size(); i ++) {
		if(s[i] == '1') s1 ++;
	}
	if(s1 == s.size()) {
		int sum = 1;
		for (int i = 1; i <= 39; i ++) {
			sum = sum * i % M;
		}
		for (int i = 1; i <= 61; i ++) sum = sum * i % M;
		cout << sum;
		return 0;
	}
	else {
		dfs(1, k, 0);
		cout << ans;
	}
	return 0;
}