#include <bits/stdc++.h>

#define ll long long
#define pii pair<int, int>
#define mkpr make_pair
#define fir first
#define sec second

using namespace std;

const int maxn = 1e5 + 7;
const int inf  = 0x3f3f3f3f;
const int mod  = 998244353;

int n, m, c[maxn];
char s[maxn];
int p[maxn];
signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d%s", &n, &m, s + 1);
	for (int i = 1; i <= n; ++i) scanf("%d", c + i);
	for (int i = 1; i <= n; ++i) p[i] = i;
	ll ans = 0;
	do {
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (cnt >= c[p[i]]) {
				++cnt;
				continue;
			}
			if (s[i] == '0') ++cnt;
		}
		if (n - cnt >= m) ++ans, ans %= mod;
	} while(next_permutation(p + 1, p + n + 1));
	printf("%lld\n", ans);
	return 0;
}

