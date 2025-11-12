#include <bits/stdc++.h>
using namespace std;
long long n, m;
char s[1010];
int c[1010];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	getchar();
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		if (n == m && s[i] == '0') {
			cout << 0;
			return 0;
		}
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	long long ans = 1, x = 998244353;
	for (long long i = 0; i < m; i++) {
		ans = ans * (n - i);
		ans = ans % x;
	}
	cout << ans;
	return 0;
}
