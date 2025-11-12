#include <bits/stdc++.h>
using namespace std;
const long long N = 1e4 + 5, M = 2e6 + 5;
long long n, m, k, fa[N], price[15], a[15][N], tot;
struct node {
	long long _u, _v, _w;
};
vector <node> vec;
bool vis[15];
bool cmp(node x, node y) {
	return x._w < y._w;
}
bool flaga = true;
long long get(long long x) {
	if (fa[x] == x)
		return x;
	return fa[x] = get(fa[x]);
}
void merge(long long x, long long y) {
	fa[get(x)] = get(y);
}
long long check(long long x, long long y) {
	long long res = LLONG_MAX, id;
	for (long long i = 1; i <= k; i++) {
		long long tmp = a[i][x] + a[i][y];
		if (!vis[i])
			tmp += price[i];
		if (res > tmp)
			res = tmp, id = i;
	}
	vis[id] = true;
	return res;
}
long long kruskal() {
	sort(vec.begin(), vec.end(), cmp);
	long long ans = 0;
	for (long long i = 1; i <= n; i++)
		fa[i] = i;
	for (auto [u, v, w] : vec) {
		if (get(u) == get(v))
			continue;
		merge(u, v);
		ans += w;
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			vec.push_back({i, j, check(i, j)});
	return ans;
}
long long F() {
	long long sum = 0;
	for (long long i = 1; i <= k; i++)
		if (vis[i])
			sum += price[i];
	return sum;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> k;
	while (m--) {
		long long u, v, w;
		cin >> u >> v >> w;
		vec.push_back({u, v, w});
	}
	for (long long i = 1; i <= k; i++) {
		cin >> price[i];
		for (long long j = 1; j <= n; j++)
			cin >> a[i][j];
	}
	long long ans1 = kruskal(), ans2 = kruskal() + F();
	cout << min(ans1, ans2);
	return 0;
}