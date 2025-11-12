#include <bits/stdc++.h>
using namespace std;

struct E {
	int a, b, c;
};

const int N = 11000;
E edge[N * 100];
int fa[N], a[12][N], lb[1 << 12];
pair<int, int> f[N][1 << 10];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	vector<int> v;
	for (int i = 1; i <= m; i ++ ) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		edge[i] = {a, b, c};
		v.push_back(c);
	}
	sort(edge + 1, edge + m + 1, [](E x, E y) {return x.c < y.c;});
	for (int i = 1; i <= n; i ++ ) fa[i] = i;
	int T = m;
	m = 0;
	for (int i = 1; i <= T; i ++ ) {
		int a = edge[i].a, b = edge[i].b, c = edge[i].c;
		if (find(a) != find(b)) {
			fa[find(a)] = find(b);
			edge[++ m] = {a, b, c};
		}
	}
	vector<int> w(k + 5);
	for (int i = 0; i < k; i ++ ) {
		scanf("%d", &w[i]);
		for (int j = 1; j <= n; j ++ ) scanf("%d", &a[i][j]), v.push_back(a[i][j]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	unordered_map<int, int> mp;
	for (int i = 0; i < v.size(); i ++ ) mp[v[i]] = i;
	for (int i = 1; i < (1 << k); i ++ ) lb[i] = (int)log2(i & -i);
	for (int i = 1; i <= n; i ++ ) {
		f[i][0] = make_pair(2e9, 0);
		for (int j = 1; j < (1 << k); j ++ )
			f[i][j] = min(f[i][j ^ (j & -j)], make_pair(a[lb[j]][i], lb[j]));
	}
	long long ans = 1e18;
	for (int i = 0; i < (1 << k); i ++ ) {
		long long res = 0;
		for (int l = 0; l < k; l ++ )
			if (i >> l & 1)
				res += w[l];
		vector<E> Ed;
		for (int j = 1; j <= m; j ++ ) {
			Ed.push_back(edge[j]);
		}
		int B = n;
		for (int l = 0; l < k; l ++ )
			if (i >> l & 1) {
				B ++ ;
				for (int j = 1; j <= n; j ++ )
					Ed.push_back({n + 1 + l, j, a[l][j]});
			}
		for (int j = 1; j <= n + k; j ++ ) fa[j] = j;
			for (auto e : Ed) {
			int a = e.a, b = e.b, c = e.c;
			if (find(a) != find(b)) {
				fa[find(a)] = find(b);
				res += c;
				B -- ;
			} 
			}
		
		ans = min(ans, res);
	}
	cout << ans << endl;
	return 0;
}