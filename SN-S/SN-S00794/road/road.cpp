#include <bits/stdc++.h>
using namespace std;

namespace gxk {
	void main() ;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	gxk::main();
	return 0;
}

#define int long long
namespace gxk {
	const int maxn = 10020, maxm = 1000020, maxk = 15;
	
	int n, m, k, c[maxk], a[maxk][maxn];
	struct edge {
		int u, v, w;
	} E[maxm], e[maxn];
	int cnt = 0;
	
	struct bingchaji {
		int fa[maxn], depp[maxn];
		void init(int kk) {
			for (int i = 1; i <= kk; i++) {
				fa[i] = i;
				depp[i] = 1;
			}
			return ;
		}
		int find(int x) {
			if (fa[x] != x) fa[x] = find(fa[x]);
			return fa[x];
		}
		void merge(int x, int y) {
			x = find(x), y = find(y);
			if (x == y) return ;
			if (depp[x] > depp[y]) {
				fa[y] = x;
			} else {
				fa[x] = y;
				if (depp[x] == depp[y]) depp[y]++;
			}
			return ;
		}
	} bcz;
	
	bool cmp(edge a, edge b) {
		return a.w < b.w;
	}
	
	int ans2, anss, A;
	
	void main() {
		A = 1;
		cin >> n >> m >> k;
		bcz.init(n);
		for (int i = 1; i <= m; i++) {
			cin >> E[i].u >> E[i].v >> E[i].w;
		}
		sort(E + 1, E + 1 + m, cmp);
		for (int i = 1; i <= m; i++) {
			if (bcz.find(E[i].u) != bcz.find(E[i].v)) {
				e[++cnt] = E[i];
				bcz.merge(E[i].u, E[i].v);
			}
		}
		for (int i = 1; i <= k; i++) {
			cin >> c[i];
			if (c[i] > 0) A = 0;
			int flag = 0;
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				if (!a[i][j]) flag = 1;
			}
			if (!flag) A = 0;
		}
		anss = (int)1e16;
		int lll = 0;
		if (A) lll = (1 << k) - 1;
		for (int i = (1 << k) - 1; i >= lll; i--) {
			ans2 = 0;
			cnt = n - 1;
			for (int d = 1; d <= cnt; d++) {
				E[d] = e[d];
			}
			int j = i, sum = 0;
			for (int d = 1; d <= k; d++) {
				if (j & 1) {
					sum++;
					ans2 += c[d];
					for (int ii = 1; ii <= n; ii++) {
						E[++cnt] = {n + sum, ii, a[d][ii]};
					}
//					cout << d << ' ';
				}
				j >>= 1;
			}
//			cout << '\n';
			bcz.init(n + sum);
			sort(E + 1, E + 1 + cnt, cmp);
			for (int i = 1; i <= cnt; i++) {
				if (bcz.find(E[i].u) != bcz.find(E[i].v)) {
					bcz.merge(E[i].u, E[i].v);
					ans2 += E[i].w;
//					cout << E[i].u << ' ' << E[i].v << '\n';
				}
			}
			anss = min(anss, ans2);
		}
		cout << anss << '\n';
		
		return ;
	}
}
