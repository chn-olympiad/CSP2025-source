#include <bits/stdc++.h>
using namespace std;
const int N = 505, MOD = 998244353;
char s[N];
int ot[N], c[N], tmp[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m; scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &c[i]);
		tmp[i] = i;
	}
	for (int i = 2; i <= n; ++i) {
		ot[i] = ot[i - 1] + ((s[i - 1] == '0') ? 1 : 0);
	}
	long long ans = 0;
	do {
		int t = 0, fg = 0;
		for (int i = 1; i <= n; ++i) {
			if (fg + ot[i] < c[tmp[i]] && s[i] == '1')
				++t;
			else if (s[i] != '0')
				++fg;
		}
		if (t >= m) ++ans;
	} while (next_permutation(tmp + 1, tmp + n + 1));
	printf("%lld\n", ans);
	return 0;
}
