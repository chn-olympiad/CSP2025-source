#include <bits/stdc++.h>
using namespace std;
long long n, m, c[600], s[600], p = 998244353, ans, f[600], su;
bool v[600];

long long kr() {
	long long a = 0, b;
	bool f = false;
	char cc;
	cc = getchar();
	if (cc == '-') {
		cc = getchar();
		f = true;
	}
	b = cc - '0';
	while (b >= 0 && b <= 9) {
		a = a * 10 + b;
		cc = getchar();
		b = cc - '0';
	}
	if (f) {
		a = a * (-1);
	}
	return a;
}

void pd() {
	su = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 1) {
			if ((i - su - 1) < c[f[i]]) {
				su++;
			}
		}
	}
	if (su >= m) {
		ans++;
	}
}

void bfs(int k) {
	if (k == (n + 1)) {
		pd();
		return;
	} else {
		for (int i = 1; i <= n; i++) {
			if (!v[i]) {
				v[i] = true;
				f[k] = i;
				bfs(k + 1);
				v[i] = false;
			}
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	n = kr();
	m = kr();
	char cc;
	for (int i = 1; i <= n; i++) {
		cc = getchar();
		if (cc == '1') {
			s[i] = 1;
		}
	}
	cc = getchar();
	for (int i = 1; i <= n; i++) {
		c[i] = kr();
	}
	if (n > 18) {
		ans = 1;
		for (long long i = 1; i <= n; i++) {
			ans = (ans *i) % p;
		}
		printf("%lld", ans);
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	bfs(1);
	ans = ans % p;
	printf("%lld", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
