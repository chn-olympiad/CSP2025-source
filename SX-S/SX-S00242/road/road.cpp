#include <bits/stdc++.h>
using namespace std;
long long n, m, k, u, v, w, sum, ans, cnt, book[10005], f[10005];
long long a[10005];

struct node {
	long long u, v, w;
} s[20000006];
map<int, int> m1;

inline bool cmp(node a, node b) {
	return a.w < b.w;
}

inline int find(int x) {
	if (f[x] == x)
		return x;
	else {
		f[x] = find(f[x]);
		return f[x];
	}
}

inline void merge(int x, int y) {
	f[find(y)] = find(x);
}

int main() {

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		s[++cnt] = {u, v, w};
	}
	for (int i = 1; i <= k; i++) {
		cin >> u;
		m1[i] = u;
		for (int j = 1; j <= n; j++) {
			cin >> w;
			if (i == j)
				a[i] = w;
			s[++cnt] = {i, j, w + u};
		}
	}
	stable_sort(s + 1, s + m + n *k + 1, cmp);
	cnt = 1;
	while (sum != n - 1 ) {
		//cout << s[cnt].u << ' ' << s[cnt].v << endl;
		if (find(s[cnt].u) != find(s[cnt].v)) {
			merge(s[cnt].u, s[cnt].v);
			if (m1[s[cnt].u] != 0) {
				if (book[s[cnt].u] == 0) {
					book[s[cnt].u] = 1;
				}

				else
					ans -= m1[s[cnt].u];
			}
			ans += s[cnt].w;
			sum++;
		}
		cnt++;
	}
	for (int i = 1; i <= n; i++) {
		if (book[i] == 1)
			ans += a[i];
	}
	cout << ans;
	return 0;
}
