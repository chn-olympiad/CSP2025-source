#include <bits/stdc++.h>
using namespace std;
const int XN=5e3+10;
int n, a[XN], ans;
void dfs(int cnt, int sum, int xn) {
	if (cnt > n) {
		if (sum > 2*xn)
			ans++;
		return;
	}
	for (int i = cnt; i <= n+1; i++)
		dfs(i+1, sum+a[i], max(xn, a[i]));
	return;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
