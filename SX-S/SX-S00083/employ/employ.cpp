#include <bits/stdc++.h>
using namespace std;
#define N 521
#define mod 998244353
typedef long long ll;
int n, m, s[N], c[N], a[N];
char str[N];
ll ans = 0;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++) {
		a[i] = i;
		s[i] = str[i] - '0';
		scanf("%d", c + i);
	}
	if (n <= 18) {
		do {
			int ct = 0, ac = 0;
			for (int i = 1; i <= n; i++) {
				if (s[i] && ct < c[a[i]])
					ac++;
				else
					ct++;
			}
			if (ac >= m)
				ans++;
		} while (next_permutation(a + 1, a + 1 + n));
	} else {
		ans = 1;
		for (int i = 1; i <= n; i++)
			ans = (ans * i) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}
