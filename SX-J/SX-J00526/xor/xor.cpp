#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k, a[500010];
ll ps[500010];

bool check(ll x) {
	if (1 > x && x > n)
		return false;
	ll cnt = 0;
	for (int l = 1; l <= n; l++)
		for (int r = l + 1; r <= n; r++)
			if ((ps[r] ^ ps[l - 1]) == k)
				cnt++;
	for (int i = 1; i <= n; i++)
		if (a[i] == k)
			cnt++;

	return cnt >= x;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	scanf("%d%d", &n, &k);
	ps[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		ps[i] = 1ll * ps[i - 1] ^ a[i];
	}

	ll L = 0, R = n + 1;
	while (L + 1 < R) {
		ll mid = (L + R) / 2;
		if (check(mid))
			L = mid;
		else
			R = mid;

	}

	// 二分的是最少数量

	printf("%lld\n", L);
}
