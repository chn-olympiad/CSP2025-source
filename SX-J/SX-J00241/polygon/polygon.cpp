#include <bits/stdc++.h>
using namespace std;
const int N = 998244353;
int n, ans, a[5003], maxx;

void dfs(int x, int sum, int ma, int beg) {
	if (x == 0) {
		if (sum > 2 * ma) {
			ans = (ans + 1) % N;
		}
		return ;
	}
	for (int i = beg + 1; i <= n; i++) {
		dfs(x - 1, sum + a[i], max(ma, a[i]), i);
	}
	return ;
}

long long qpow(int a, int b) {
	long long res = 1, x = a;
	while (b != 0) {
		if (b & 1)
			res = res * x % N;
		x = x * x % N;
		b >>= 1;
	}
	return res;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}
	if (n == 3) {
		if (a[1] + a[2] + a[3] > 2 * maxx)
			cout << 1;
		else
			cout << 0;
	} else {
		sort(a + 1, a + 1 + n);
		if (a[n] == 1) {
			ans = (qpow(2, n) - n - 1 - (n*(n - 1) / 2) + N) % N;
			printf("%d", ans);
		} else {
			for (int i = 3; i <= n; i++) {
				dfs(i, 0, 0, 0);
			}
			printf("%d", ans);
		}
	}
	return 0;
}