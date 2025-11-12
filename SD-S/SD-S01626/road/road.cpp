#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e4 + 20, M = 1e6 + 20;

int n, m, k;

struct Edge {
	int a, b, w;
	
	bool operator <(const Edge &h) const {
		return w != h.w ? w < h.w : a != h.a ? a < h.a : b < h.b;
	}
}edges[M], a[11][N], f[N * 12], g[N * 12];

bool st[M];
int p[N], sz[N];
int c[11], C;

int fifa(int x) {
	C ++ ;
	return p[x] == x ? x : p[x] = fifa(p[x]);
}

void init(int n) {
	for (int i = 1; i <= n; ++ i ) p[i] = i, sz[i] = 1;
}

void add(int a, int b) {
	if (sz[a] > sz[b]) swap(a, b);
	sz[b] = max(sz[b], sz[a] + 1);
	p[a] = b;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++ i ) {
		cin >> edges[i].a >> edges[i].b >> edges[i].w;
	}
	sort(edges + 1, edges + m + 1);
	
	init(n);
	int cnt = 0;
	for (int i = 1; i <= m; ++ i ) {
		int a = edges[i].a, b = edges[i].b;
		a = fifa(a), b = fifa(b);
		if (a != b) {
			edges[ ++ cnt] = edges[i];
			add(a, b);
		}
	}
	
	// 只有 cnt 条边是有用的？
	assert(cnt == n - 1);
	
	for (int i = 0; i < k; ++ i ) {
		cin >> c[i];
		for (int j = 1; j <= n; ++ j ) {
			cin >> a[i][j].w;
			a[i][j].a = i + n + 1, a[i][j].b = j;
		}
		sort(a[i] + 1, a[i] + n + 1);
	}
	
	ll res = 2e18;
	for (int s = 0; s < 1 << k; ++ s ) {
		int cnt = n - 1;
		for (int i = 1; i <= cnt; ++ i ) f[i] = edges[i];
		
		// 将 s 中的乡镇城市化
		ll sum = 0;
		for (int i = 0; i < k; ++ i )
			if (s >> i & 1) {
				sum += c[i];
				// 将 a[i] 和 f 合并，归并排序
				
				int x = 1, y = 1, j = 0;
				while (x <= n && y <= cnt) {
					if (a[i][x] < f[y]) {
						g[ ++ j] = a[i][x ++ ];
					} else {
						g[ ++ j] = f[y ++ ];
					}
				}
				while (x <= n) g[ ++ j] = a[i][x ++ ];
				while (y <= cnt) g[ ++ j] = f[y ++ ];
				
//				merge(a[i] + 1, a[i] + n + 1, f + 1, f + cnt + 1, g + 1);
				cnt += n;
				for (int j = 1; j <= cnt; ++ j ) f[j] = g[j];
			}
		
		init(n + k);
		
		int C = 0;
		for (int i = 1; i <= cnt; ++ i ) {
			int a = f[i].a, b = f[i].b;
			a = fifa(a), b = fifa(b);
			if (a != b) {
				sum += f[i].w;
				add(a, b);
				C ++ ;
				if (C == n + k - 1) break;
			}
		}
		
		res = min(res, sum);
	}
	
	cout << res;
	
	return 0;
}
