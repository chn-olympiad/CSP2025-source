#include <bits/stdc++.h>
using namespace std;

const int N = 5000, A = 5000, MOD = 998244353;

int a[N + 5], f[N + 5][A + 5];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		memset(f, 0, sizeof(f));
		f[i][0] = 1;
		for (int j = i; j < n; j++)
			for (int k = 0; k <= a[i] + 1; k++) {
				int to = k + a[j + 1] > a[i] ? a[i] + 1 : k + a[j + 1];
				f[j + 1][to] = (f[j + 1][to] + f[j][k]) % MOD;
				f[j + 1][k] = (f[j + 1][k] + f[j][k]) % MOD;
			}
		sum = (sum + f[n][a[i] + 1]) % MOD;
	}
	cout << sum << '\n';
	return 0;
}
