#include <bits/stdc++.h>
#define ll int
#define bo bool
using namespace std;
ll T, n, a[100010][5], d[100010], maxx = INT_MIN;
bo e[100010];

void dfs(ll x, ll y) {
	if (x == n + 1) {
		maxx = max(y, maxx);
		return ;
	}
	if (e[x] == 1)
		return ;
	for (int i = 1; i <= 3; i++) {
		if (d[i] + 1 > n / 2 || e[x] == 1)
			continue;
		d[i]++;
		e[x] = 1;
		dfs(x + 1, y + a[x][i]);
		d[i]--;
		e[x] = 0;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "r", stdout);
	cin >> T;
	while (T--) {
		maxx = INT_MIN;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		dfs(1, 0);
		cout << maxx << endl;
	}
	return 0;
}