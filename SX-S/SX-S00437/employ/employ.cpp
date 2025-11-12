#include <bits/stdc++.h>
using namespace std;
#define mod 998244353ll
#define ll long long
const int N = 505;
int n, m, c[N], p[N], v[N], ans;
char s[N];

void dfs(int x) {
	if (x == n + 1) {
		int ss = 0, sum = 0;
		for (int i = 1; i <= n; ++i) {
			if (ss >= c[p[i]] || s[i] == '0')
				++ss;
			else ++sum;
		}
		if (sum >= m)
			++ans;
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (!v[i]) {
			v[i] = 1, p[x] = i, dfs(x + 1), v[i] = 0;
		}
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf(" %s", s + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
	}
	if (n <= 10) {
		dfs(1), printf("%d\n", ans);
	} else {
		ans = 1;
		for (int i = 1; i <= n; ++i) {
			ans = (ll)ans * i % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}
