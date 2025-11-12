#include <bits/stdc++.h>
using namespace std;
int n;
long long a[10005], k;
int maxx;

void dfs(int x, long long now, int sum) {
	if (x > n) {
		maxx = max(maxx, sum);
		return;
	}
	if (now == k) {
		sum++;
		dfs(x + 1, a[x + 1], sum);
	}
	if (sum + (n - x + 1) <= maxx)
		return;
	dfs(x + 1, a[x + 1], sum);
	for (int i = x + 1; sum + (n - i + 1) > maxx; i++) {
		now = now ^a[i];
		dfs(i, now, sum);
	}
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == k)
			maxx++;
	}
	int t = maxx;
	dfs(1, a[1], 0);
	if (maxx < n)
		cout << maxx;
	else
		cout << t;
	return 0;
}
