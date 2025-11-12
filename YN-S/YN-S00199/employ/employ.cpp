#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 550, mod = 998244353;
int n, m;
int a[N];
char s[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	bool f = true;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] != '1')
			f = false;
	}
	int tot = n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 0)
			tot--;
	}
	if (f) {
		ll x = 1;
		for (int i = 1; i <= tot; i++) {
			x = ((x % mod) * i) % mod;
		}
		printf("%lld\n", x);
	}
	if (m == n) {
		if (!f)
			printf("0\n");
		else {
			ll x = 1;
			for (int i = 1; i <= tot; i++) {
				x = ((x % mod) * i) % mod;
			}
			printf("%lld\n", x);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}