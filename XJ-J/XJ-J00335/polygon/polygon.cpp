#include <bits/stdc++.h>
using namespace std;
int n;
long long a[5007];
long long s[5007];
const int M = 998244353;
long long pw(long long x) {
	long long ans = 1;
	if (x == 1) return 2ll;
	while (x > 0) {
		if (x % 2 != 0) {
			x--;
			ans = ans * 2 % M;
		}
		ans = ans * ans % M;
		x /= 2;
	}
	return ans;
}
long long dfs(long long max, long long sum, int dir, int num) {
	if (sum > max && num >= 3) {
		return pw((long long)dir) % M;
	}
	if (sum + s[dir] <= max) return 0;
	if (dir == 1) {
		if (!max) {
			return 0ll;
		}
		if (num < 2) {
			return 0ll;
		}
		if (num >= 2 && sum + a[dir] > max) {
			return 1;
		}
		return 0;
	}
	if (!max) {
		return (dfs(a[dir], 0ll, dir - 1, 1) + dfs(0ll, 0ll, dir - 1, 0)) % M;
	}
	return (dfs(max, sum + a[dir], dir - 1, num + 1) + dfs(max, sum, dir - 1, num)) % M;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + a[i];
	}
	cout << dfs(0ll, 0ll, n, 0);
} 

