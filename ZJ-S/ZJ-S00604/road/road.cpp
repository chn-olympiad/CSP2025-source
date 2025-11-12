#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 50, M = 1.1e6 + 10;
int n, m, k, c[11], a[11][N], len[N];
vector <pair<int, int> > p[N];
int fa[M];
long long ans;

struct node {
	int u, v, w;
	bool operator> (const node& other) const {
		return w > other.w;
	}
};

node edge[M];

bool cmp(node xx, node yy) {
	return xx.w < yy.w;
}

int find(int x) {
	if (fa[x] == x) return x;
	fa[x] = find(fa[x]);
	return fa[x];
}

void kruskal() {
	sort(edge, edge + m, cmp);
	int now = 0;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 0; i < m; i++) {
		if (find(edge[i].u) != find(edge[i].v)) {
			ans += edge[i].w;
			now++;
			fa[find(edge[i].u)] = find(edge[i].v);
		}
		if (now == n - 1) break;
	}
	cout << ans;
}

long long k2() {
	sort(edge, edge + m, cmp);
	int now = 0;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 0; i < m; i++) {
		if (find(edge[i].u) != find(edge[i].v)) {
			ans += edge[i].w;
			now++;
			fa[find(edge[i].u)] = find(edge[i].v);
		}
		if (now == n - 1) break;
	}
	return  ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
		p[edge[i].u].push_back(make_pair(edge[i].v, edge[i].w));
		p[edge[i].v].push_back(make_pair(edge[i].u, edge[i].w));
		len[edge[i].u]++;
		len[edge[i].v]++;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	if (k == 0) {
		kruskal();
	}
	else {
		bool f = 0;
		for (int i = 1; i <= k; i++) {
			if (c[i]) f = 1;
			else {
				bool g = 0;
				for (int j = 1; j <= n; j++) {
					if (!a[i][j]) g = 1;
				}
				if (!g) f = 1;
			}
		}
		if (!f) {
			int pos = m;
			for (int i = 1; i <= k; i++) {
				for (int j = 1; j <= n; j++) {
					edge[pos] = (node){n + i, j, a[i][j]};
					pos++;
				}
			}
			n = n + k;
			m = pos;
			kruskal();
		}
		else {
			long long res = 1e18, anss = 0;
			for (int i = 0; i < (1 << k); i++) {
				int mm = m, nn = n;
				int t = __builtin_popcount(i);
				for (int j = 0; j < k; j++) {
					if (i & (1 << j)) {
						anss += c[j + 1];
						for (int l = 1; l <= n; l++) {
							edge[m] = (node){n + j + 1, l, a[j + 1][l]};
							m++;
						}
					}
				}
				n = n + t;
				res = min(res, anss + k2());
			}
			cout << res << '\n';
		}
	}
	
	return 0;
}
