#include <bits/stdc++.h>
using namespace std;
const int N = 5e3+5;
int n, ans, cnt;
int a[N];
bool vis[N];

void dfs(int sa, int su, int s, int x) {
	for (int i = x; i < n; i++) {
		if (vis[i] == 0) {
			vis[i] = 1;
			dfs(max(sa, a[i]), su + a[i], s + 1, i);
			vis[i] = 0;
		}
	}
	if (s >= 3 && su > 2 * sa) {
		cnt++;
	}
	return ;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		vis[i] = 1;
		cnt = 0;
		dfs(a[i], a[i], 1, i);
		ans += cnt;
		vis[i] = 0;
	}
	cout << ans;
	return 0;
}
