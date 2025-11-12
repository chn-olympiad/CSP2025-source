#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353, N = 5010;

int n;
int a[N];
int f[N];

int solve(int x) {
	memset(f, 0, sizeof f);
	f[0] = 1;
	for (int i = 1; i < x; i++)
		for (int j = a[x]; j >= a[i]; --j)
			f[j] = (f[j] + f[j - a[i]]) % MOD;
	int res = 0;
	for (int i = 0; i <= a[x]; i++) res = (res + f[i]) % MOD;
	return res;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	if (a[n] == 1) {
		int ans = 1;
		for (int i = 1; i <= n; i++) ans = ans * 2 % MOD;
		ans -= n + 1 + n * (n - 1) / 2;
		ans = (ans % MOD + MOD) % MOD;
		cout << ans;
		return 0;
	}
	int pro = 4, ans = 0;
	for (int i = 3; i <= n; i++) {
		int res = solve(i);
		ans = (ans + pro - res) % MOD;
		pro = pro * 2 % MOD;
	}
	cout << ans;
	return 0;
}
