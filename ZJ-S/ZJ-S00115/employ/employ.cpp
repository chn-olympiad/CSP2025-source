#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#define L(i, l, r, a) for(int i = l; i <= r; i += a)
#define R(i, l, r, a) for(int i = r; i >= l; i -= a)
#define N 510
#define int long long
using namespace std;
const int mod = 998244353;
int n, m, a[N], ans;
string s;
int vis[N], id[N];
void brute(int u) {
	if(u == n + 1) {
		int cnt = 0, res = 0;
		L(i, 1, n, 1) {
			if(s[i - 1] == '0') cnt++;
			else if(cnt >= a[id[i]]) cnt++;
			else res++;
		}
		if(res >= m) ans = (ans + 1) % mod;
		return;
	}
	L(i, 1, n, 1) {
		if(!vis[i]) {
			vis[i] = 1;
			id[u] = i;
			brute(u + 1);
			vis[i] = 0;
		}
	}
}
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m >> s;
	int mn = n + 1;
	L(i, 1, n, 1) cin >> a[i], mn = min(mn, a[i]);
	bool f = 1;
	L(i, 0, n - 1, 1) if(s[i] == '0') f = 0;
	if(m == n) {
		if(f && mn != 0) {
			ans = 1;
			L(i, 1, n, 1) ans = ans * i % mod;
		}
		cout << ans;
		return 0;
	}
	if(f) {
		ans = 1;
		L(i, 1, n, 1) ans = ans * i % mod;
		cout << ans;
		return 0;
	}
	brute(1);
	cout << ans;
	return 0;
}