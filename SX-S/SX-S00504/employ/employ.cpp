#include <bits/stdc++.h>
using namespace std;
const int N = 505, mod = 998244353;
int n, m;
char s[N];
int c[N];

long long solve(int x, int y) {
	long long ans = 1LL;
	for (int i = x - y + 1; i <= x; i++) {
		ans = (ans *i) % mod;
	}
	return ans;
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
//	printf("%lld", qpow(5, 4));
	scanf("%d%d", &n, &m);
	cin >> (s + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &c[i]);
	printf("%lld\n", solve(n, n));
	return 0;
}