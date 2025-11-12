
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 500;
const ll md = 998244353;
int p[N], c[N], s[N];
int n, m, flag;
ll ans;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	flag = 1;
	for (int i = 1; i <= n; ++i) {
		scanf("%1d", &s[i]);
		flag &= (s[i] == 1);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
		p[i] = i;
	}
	if (n <= 18) {
		do {
			int ko = 0;
			for (int i = 1; i <= n; ++i) {
				if (s[i] == 0 || ko >= c[p[i]])	ko++;
			}
			ans += (n - ko >= m);
		} while (next_permutation(p + 1, p + 1 + n));
		printf("%lld", ans);
		return 0;
	}
	if (flag) {
		ans = 1;
		for (int i = 1; i <= n; ++i) {
			ans = (ll)ans * i % md;
		}
		printf("%lld\n", ans);
		return 0;
	}
	return 0;
}
