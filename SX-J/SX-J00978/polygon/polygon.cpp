#include <bits/stdc++.h>
using namespace std;
long long n, sum = 0, a[5005];

void bfs(long long m, long long x, long long c) {
	if (m > n)
		return ;
	for (int i = x + 1; i <= n; i++) {
		if (m >= 3 && c + a[i] > 2 * a[i])
			sum++, sum %= 998244353;
		bfs(m + 1, i, c + a[i]);
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n ;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	bfs(1ll, 0ll, 0ll);
	cout << sum;
	return 0;
}
