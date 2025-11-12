#include <bits/stdc++.h>
using namespace std;
const int N = 998244353;
long long dp[5100], n, a[5100], ans, p[5100];

bool check(int dep) {
	long long s = 0, maxa = 0;
	for (int i = 1; i <= dep; i++) {
		maxa = max(maxa, a[p[i]]);
		s += a[p[i]];
	}
	return s > 2 * maxa;
}
















void zuhe(int dep, int id, int maxdep) {
	if (dep > maxdep) {
		if (check(maxdep))
			ans++;
		return;
	}
	for (int i = id + 1; i <= n; i++) {
		p[dep] = i;
		zuhe(dep + 1, i, maxdep);
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	bool flag1 = true;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		flag1 &= (a[i] == 1);
	}
	//È«ÊÇ1(24pts)
	if (flag1) {
		for (int i = 3; i <= n; i++) {
			long long jc1 = 1, jc2 = 1;
			for (int j = (n - i + 1); j <= n; j++) {
				jc1 *= j;
				jc1 %= N;
			}
			for (int j = 1; j <= i; j++) {
				jc2 *= j;
				jc2 %= N;
			}
			ans += ((jc1 % N) / (jc2 % N)) % N;
			ans %= N;
		}
		cout << ans % N << endl;
	} else {
		//baoli!(40pts)
		for (int i = 3; i <= n; i++)
			zuhe(1, 0, i);
		cout << ans % N << endl;
	}

	return 0;
}