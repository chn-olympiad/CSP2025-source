#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int P = 998244353;
int n, m, c[505], b[505], lst;
ll tans;
char s[505];
void dfs(int k) {
	if (k == n + 1) {
		++tans;
		if (tans >= P) tans -= P;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (b[i]) continue;
		b[i] = 1;
		int f = 0;
		if (s[k] == '0' || lst >= c[i]) ++lst, f = 1;
		if (m - (k - lst) <= n - k) dfs(k + 1);
		b[i] = 0;
		if (f) --lst;
	}
}
void sbf() {
	dfs(1);
	printf("%d", tans);
}
int csa() {
	ll ans = 1;
	for (int i = n; i >= 2; i--) ans = ans * i % P;
	return (int)ans;
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	int fl = 1, fr = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &c[i]);
		fl = fl & (s[i] - 48);
		if (fr && !c[i]) fr = 0;
	}
	if (m == n) {
		if (fl && fr) return printf("%d", csa), 0;
		return printf("0"), 0;
	}
	sbf();
	return 0;
}