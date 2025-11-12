#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1000;
const int mod = 998244353; 
int n, m;
ll ans;
char s[N];
int c[N];
bool vis[N];
int p[N];
void check () {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '0' or cnt >= c[p[i]]) {
			cnt++;
		}
	}
	if (n - cnt >= m) ans++;
	ans %= mod;
}
void dfs (int now) {
	if (now > n) {
		check();
		return;
	} 
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			p[now] = i;
			dfs (now + 1);
			vis[i] = 0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf ("%d%d%s", &n, &m, s + 1);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &c[i]);
	}
	dfs (1);
	printf ("%lld", ans);
	return 0;
}
//3 2 101 1 1 2
