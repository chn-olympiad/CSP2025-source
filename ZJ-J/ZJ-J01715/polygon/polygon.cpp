#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 5e3+10, mod = 998244353;
int n, ans, a[maxn], b[maxn];
bool f[maxn];
void dfs(int x) {
	if (x == n+1) {
		int mx = 0, cnt = 0, sum = 0;
		for (int i = 1; i <= n; i++) {
			if (f[i]) {
				cnt++;
				mx = a[i];
				sum += a[i];
			}
		}
		if (cnt >= 3 && sum > 2*mx) ans = (ans+1) % mod;
		return;
	}
	f[x] = 1;
	dfs(x+1);
	f[x] = 0;
	dfs(x+1);
}
void work1() {
	sort(a, a+n+1);
	dfs(1);
	cout << ans;
}
void work2() {
	for (int i = 3; i <= n; i++) {
		b[i] = 1;
		for (int j = n; j >= i; j--) {
			b[i] = (1ll * b[i] * j) % mod;
		}
	}
	int res = 0;
	for (int i = 3; i <= n; i++) 
		res = (1ll * res + 1ll * b[i]) % mod;
	cout << res;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	if (n <= 50) work1();
	else work2();
	return 0;
}
