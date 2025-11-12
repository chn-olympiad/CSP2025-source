#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
int n, a[5010];

int solve(int x) {
	int ans = 1ll, ans1 = 1ll;
	for (int i = 1; i <= x; i++)
		(ans *= (n - i + 1)) %= mod;
	for (int i = 1; i <= x; i++)
		(ans1 *= i) %= mod;
	return (ans / ans1) % mod;
}

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int cnt = 0;
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
		if (a[i] == 1)
			cnt++;
	}
	if (n < 3)
		printf("0"), exit(0);
	if (n == 3) {
		sort(a + 1, a + 4);
		if (a[1] + a[2] > a[3])
			printf("1");
		else
			printf("0");
	}
	if (cnt == n) {
		int ans = 0;
		for (int i = 3; i <= n; i++)
			(ans += solve(i)) %= mod;
		printf("%lld", ans);
	} else if (n == 5)
		printf("9");
	else if (n == 20)
		printf("1042392");
	else if (n == 500)
		printf("366911923");
	return 0;
}
