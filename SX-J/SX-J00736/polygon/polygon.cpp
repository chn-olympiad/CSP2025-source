#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, a[5009], ans;

void dfs(int c, int sum, int mx, int cnt) {
	if (c == n) {
		if (sum > mx * 2 && cnt > 2)
			ans = (ans + 1) % 998244353;
		return;
	}
	dfs(c + 1, sum + a[c + 1], max(mx, a[c + 1]), cnt + 1);
	dfs(c + 1, sum, mx, cnt);
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dfs(0, 0, 0, 0);
	cout << ans;
	return 0;
}
