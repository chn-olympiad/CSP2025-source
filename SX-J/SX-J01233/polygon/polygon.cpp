#include <bits/stdc++.h>
using namespace std;
int gun[5005], n;
bool vis[5005];
int ans = 0;

bool check(int b) {
	int big = 2 * b;
	int all = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 1)
			all += gun[i];
	}
	if (all > big)
		return 1;
	else
		return 0;
}

void dfs(int step, int all, int l) {
	if (step > all) {
		ans++;
		ans %= 998244353;
		return;
	}
	for (int i = l + 1; i <= n; i++) {
		if (vis[i] == 0 && (check(gun[i]) == 1 || step <= 3)) {
			vis[i] = 1;
			dfs(step + 1, all, i);
			vis[i] = 0;
			return ;
		}
	}
	return ;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> gun[i];
	}
	sort(gun + 1, gun + n + 1);
	for (int i = 3; i <= n; i++) {
		dfs(1, i, 0);
	}
	cout << ans;
	return 0;
}
