#include <bits/stdc++.h>
using namespace std;
int n, m, k, head[10005], u[1000005], v[1000005], w[1000005], a[10005][15], f[10015], b[10005][15], c[15];
pair<int, int> p[1000005], p2[10005];

int find(int x) {
	if (f[x] != x)
		return f[x] = find(f[x]);
	return x;
}

long long A(int x) {
	cout << x << ' ';
	long long ans = 0;
	int cnt = 0, b2[15], k2 = 0, cnt2[15], cnt3 = 1;
	for (int i = 1; i <= k; i++)
		if (x & (1 << (i - 1))) {
			b2[++k2] = i;
			ans += c[i];
		}
	for (int i = 0; i <= k; i++)
		cnt2[i] = 1;
	a[0][0] = INT_MAX;
	while (cnt < n + k2) {
//		cout << cnt << ' ';
		int y = 0, u2, v2;
		for (int i = 1; i <= k2; i++)
			if (cnt2[b2[i]] <= n && a[cnt2[b2[i]]][b2[i]] < a[cnt2[y]][y])
				y = b2[i];
//		cout << w[cnt3] << ' ' << y << ' ' << cnt2[y] << ' ' << a[cnt2[y]][y];
		if (cnt2[y] > n || cnt3 <= m && w[cnt3] < a[cnt2[y]][y]) {
			u2 = find(u[cnt3]);
			v2 = find(v[cnt3]);
			cnt3++;
		} else {
			u2 = find(y + n);
			v2 = find(b[cnt2[y]][y]);
			cnt2[y]++;
		}
		if (u2 != v2) {
			f[u2] = v2;
			if (cnt2[y] > n)
				ans += w[cnt3];
			else if (cnt3 > m)
				ans += a[cnt2[y]][y];
			else
				ans += min(w[cnt3], a[cnt2[y]][y]);
			cnt++;
		}
	}
	return ans;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
		p[i] = make_pair(w[i], i);
	}
	for (int i = 1; i <= n; i++)
		f[i] = i;
	sort(p + 1, p + m + 1);
	long long ans = 0, cnt = 0, cnt2 = 1;
	while (cnt < n - 1) {
		int u2 = find(u[cnt2]), v2 = find(v[cnt2]);
		if (u2 != v2) {
			f[u2] = v2;
			ans += w[cnt2];
			cnt++;
		}
		cnt2++;
	}
	printf("%lld", ans);
	return 0;
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/