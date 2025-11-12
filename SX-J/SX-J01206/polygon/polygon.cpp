#include <bits/stdc++.h>
using namespace std;
int a[11111111];
int f[11111111];
long long n, ans = 0;

void dfs(int dep, int q) {
	if (q > 2 * a[dep]) {
		if (dep >= 3 && dep <= n)
			ans++;
		//cout << dep << " " << q << endl;
		q = 0;
		return;
	}
	for (int i = dep; i <= n; i++) {
		if (f[a[i]] == 0) {
			q = q + a[i];
			f[a[i]] = 1;
			dfs(dep + 1, q);
			f[a[i]] = 0;
		}
		if (f[a[i]] == 1)
			q = q - a[i];
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
	dfs(1, 0);
	cout << ans % 998244353 << endl;
}
