#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
bool mode = 1;
long long a[5005], n, sum, ans;
void dfs(int last) {
	if (sum > a[last] * 2) ans++, ans %= MOD;
	if (last == n) return;
	for (int i = last + 1; i <= n; i++) {
		sum += a[i];
		dfs(i);
		sum -= a[i];
	}
	return ;
}
void solve1() {
	sort(a + 1, a + 1 + n);
	dfs(0);
	cout << ans;
	return;
}
long long mem[505][50005];
int dfs2(int last) {
	long long res = 0;
	if (sum > a[last] * 2) res++;
	if (last == n) return mem[last][sum] = res;
	if (mem[last][sum]) return mem[last][sum];
	for (int i = last + 1; i <= n; i++) {
		sum += a[i];
		res += dfs2(i);
		res %= MOD;
		sum -= a[i];
	}
	return mem[last][sum] = (res % MOD);
}
void solve2() {
	cout << dfs2(0);
	return;
}
long long fpow(int x) {
	if (x == 0) return 1;
	if (x == 1) return 2;
	long long p = fpow(x / 2);
	if (x & 1) {
		return p * p % MOD * 2 % MOD;
	}
	return p * p % MOD;
}
void solve3() {
	ans = fpow(n) - 1;
	ans += MOD;
	ans -= n;
	ans -= n * (n - 1) / 2;
	cout << ans % MOD;
	return;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > 1) mode = 0;
	}
	if (n <= 20) solve1();
	else if (n <= 500) {
		solve2();
	}
	else if (mode) {
		solve3();
	}
	return 0;
}
