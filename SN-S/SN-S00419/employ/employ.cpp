#include <bits/stdc++.h>
#define MOD 998244353
#define ll long long
#define Maxn 505

using namespace std;

ll n, m, c[Maxn], res, t[Maxn];
bool vis[Maxn], fl[Maxn];
string s;

void check() {
	int cnt = 0, num = 0;
	for (int i = 1; i <= n; i ++) {
		if (vis[i] && cnt < c[t[i]]) {
			num ++;
		} else {
			cnt ++;
		}
	} if (num >= m) { res ++; }
}

void dfs(int x) {
	if (x == n + 1) {
		check();
		return ;
	}
	
	for (int i = 1; i <= n; i ++) {
		if (!fl[i]) {
			fl[i] = 1, t[x] = i;
			dfs(x + 1), fl[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m >> s;
	for (ll i = 1; i <= n; i ++) {
		vis[i] = s[i - 1] - '0';
		cin >> c[i];
	}
	
	if (m == n) {
		bool fl = 1;
		for (ll i = 1; i <= n; i ++) {
			if (c[i] == 0) { fl = 0; break; }
			if (vis[i] == 0) { fl = 0; break; }
		} if (fl == 1) {
			res = 1;
			for (ll i = 1; i <= n; i ++) { res = res * i % MOD; }
			cout << res;
		} else { cout << 0; }
		return 0;
	}
	if (n <= 10) {
		res = 0, dfs(1), cout << res;
		return 0;
	} cout << 0;
	return 0;
}
