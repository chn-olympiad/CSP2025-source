#include <bits/stdc++.h>
using namespace std;
char h[1010];
int cnt[1010];
int n, m;
const int mod = 998244353;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", h);

	for (int i = 0; i < n; i++) {

		if (h[i] == 0) {
			cnt[i] = cnt[i - 1] + 1;
		} else {
			cnt[i] = cnt[i - 1];
		}
	}

	int cnt = 0;

	for (int i = 1; i <= n; i++) {

		int x;
		scanf("%d", &x);

		if (x == 0)
			cnt++;
	}

	long long ans = 1;

	for (int i = 1; i <= n - cnt; i++) {

		ans = (ans * 1ll * i) % mod;
	}

	printf("%lld\n", ans);
	return 0;
}