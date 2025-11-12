#include <bits/stdc++.h>

using namespace std;

int n;
int len[10000009];
int a[1000009];
long long number;

void dfs(int x, int num, int ans, int maxn) {
	if (num >= 3 && (ans > (maxn * 2))) {
		number = (number + 1) % 998244353;
	}
	if (x == n) {
		return ;
	}
	for (int i = x + 1; i <= n ; i++) {
		a[num + 1] = len[i];
		dfs(i, num + 1, ans + len[i], max(maxn, len[i]));
	}
	return ;
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> len[i];
	}
	dfs(0, 0, 0, INT_MIN);
	cout << number % 998244353;
	return 0;
}
