#include <bits/stdc++.h>
using namespace std;
int a[5005], n, m, s, c;
bool f[5005];

void dfs(int ii, int x) {
	if (ii == n) {
		if (s > m)
			c++;
		return;
	}
	for (int i = ii; i <= x; i++) {
		if (!f[i])
			continue;
		s += a[i];
		f[i] = 0;
		dfs(ii + 1, x );
		f[i] = 1;
		s -= a[i];
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= n - 2; i++) {

		for (int j = n - i + 1; j >= 2; j--) {
			m = a[n - j + 1];
			dfs(i, j);
			s = 0;
		}
	}
	cout << c;
	return 0;
}