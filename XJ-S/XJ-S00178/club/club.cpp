#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e5 + 11;
int n, a[N][3], c[N], a1[N];
ll ans;

inline void dfs(int i, int x, int y, int z, ll sum) {
	if (i == n + 1) {
		if (x > n / 2 || y > n / 2 || z > n / 2)
			return;
		ans = max(ans, sum);
		return;
	}
	c[i] = 1;
	if (x > n / 2 || y > n / 2 || z > n / 2)
		return;
	dfs(i + 1, x + 1, y, z, sum + a[i][c[i]]); 
	c[i] = 2;
	if (x > n / 2 || y > n / 2 || z > n / 2)
		return;
	dfs(i + 1, x, y + 1, z, sum + a[i][c[i]]);
	c[i] = 3;
	if (x > n / 2 || y > n / 2 || z > n / 2)
		return;
	dfs(i + 1, x, y, z + 1, sum + a[i][c[i]]);
}

inline bool cmp(const int &x, const int &y) {
	return x > y;
} 

inline void solve() {
	memset(a, 0, sizeof(a));
	memset(a1, 0, sizeof(a1));
	ans = 0;
	scanf("%d", &n);
	int ok1 = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++)
			scanf("%d", &a[i][j]);
		if (a[i][2] != 0 || a[i][3] != 0)
			ok1 = 0;	
	}
	if (ok1) {
		for (int i = 1; i <= n; i++)
			a1[i] = a[i][1];
		sort(a1 + 1, a1 + n + 1, cmp);
		ll cnt = 0;
		for (int i = 1; i <= n / 2; i++)
			cnt += a1[i];
		printf("%lld\n", cnt);
		return;
	}
	dfs(1, 0, 0, 0, 0);
	printf("%lld\n", ans);
	return;
}

int main() {	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	while (T--)
		solve();
	return 0;
}
