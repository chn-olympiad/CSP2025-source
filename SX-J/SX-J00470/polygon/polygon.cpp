#include <bits/stdc++.h>
using namespace std;
int n;
int a[10000];
long long ans;

void dfs(int x, int sum, int cnt) {
	if (sum >= 3) {
		if (cnt > 2 * a[x - 1]) {
			ans++;
		}
	}
	if (sum < n) {
		for (int i = x; i < n; i++)
			dfs(i + 1, sum + 1, cnt + a[i]);
	}

}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n - 2; i++) {
		dfs(i + 1, 1, a[i]);
	}
	cout << ans % 998244353 << endl;
	return 0;
}
