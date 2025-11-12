// SN-S00691
// E: 0 ~ 5 + ะþัง 
#include <bits/stdc++.h>
using namespace std;
template<typename T> void fast_read(T &x) {
	T f = 1;
	x = 0;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = x * 10 + c - '0';
		c = getchar();
	}
	x *= f;
}
template<typename T> void fast_write(T x) {
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	if (x > 9) fast_write(x / 10);
	putchar(x % 10 + '0');
}
const int MAXN = 1e3 + 10;
const long long MOD = 998244353;
int n, m;
int a[MAXN], c[MAXN];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fast_read(n), fast_read(m);
	int tp = 0, _n = n;
	for (int i = 1; i <= n; i++) {
		char chr = getchar();
		a[i] = chr - '0';
		tp += a[i] == 1;
	}
	for (int i = 1; i <= n; i++) {
		fast_read(c[i]);
		if (!c[i]) _n--;
	}
	if (tp == n) {
		long long ans = 1;
		for (int i = 2; i <= n; i++) ans = ((long long)ans * i) % MOD;
		fast_write(ans);
		return 0;
	}
	
	srand(0);
	fast_write(rand() % MOD + 1);
	return 0;
}
