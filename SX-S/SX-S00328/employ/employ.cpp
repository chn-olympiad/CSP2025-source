#include <bits/stdc++.h>
using namespace std;
const int N = 505;
const int MOD = 998244353;
int s[N], p[N];
int fac[N];

int main() {
	freopen("employ3.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	fac[1] = 1;
	for (int i = 2; i < N; i++) {
		fac[i] = (1ll * fac[i - 1] * i) % MOD;
	}
	int n, m, cnt = 0;
	cin >> n >> m;
	string a;
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		p[i + 1] = a[i] - '0';
		if (p[i + 1] == 1)
			cnt++;
	}
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	if (cnt == n) {
		cout << fac[n];
	} else if (m > cnt) {
		cout << 0;
	}
	return 0;
}