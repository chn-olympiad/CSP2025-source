#include <bits/stdc++.h>
using namespace std;

void file() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
}

long long n, a[5005], f[5005][5005];

int main() {
	file();
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	f[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 5000; j++) {
			f[i][j] = f[i - 1][j] % 998244353;
			if (j >= a[i])
				(f[i][j] += f[i - 1][j - a[i]]) %= 998244353;
		}
		f[i][5001] = f[i - 1][5001] % 998244353;
		for (int j = 5001 - a[i]; j <= 5001; j++)
			(f[i][5001] += f[i - 1][j]) %= 998244353;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 5000; j >= 0; j--)
			(f[i][j] += f[i][j + 1]) %= 998244353;
	long long ans = 0;
	for (int i = 3; i <= n; i++)
		(ans += f[i - 1][a[i] + 1]) %= 998244353;
	cout << ans;
	return 0;
}
