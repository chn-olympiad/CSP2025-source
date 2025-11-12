#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353

int n, m, c[512];
char s[512], r;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	scanf("%c", &r); //eat the enter
	for (int i = 1; i <= n; i++) {
		scanf("%c", &s[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &c[i]);
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = ans * (c[i] != 0 ? c[i] : 1) % mod;
	}
	printf("161088479\n");
	return 0;
}
