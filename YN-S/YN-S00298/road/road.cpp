#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
typedef long long LL;
const int N = 2e6 + 10;

namespace problem {

int n, m, k;
struct edge {
	int u, v;
	LL w;
} e[N];
int val[N << 2];
int fa[N];
int find(int p) {
	return (fa[p] == p ? p : fa[p] = find(fa[p]));
}
int a[20][N], c[N];
bool cmp(edge x, edge y) {
	return x.w < y.w;
}
edge tmp[N];
edge tp[N];
void solve() {
	std::cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		std::cin >> e[i].u >> e[i].v >> e[i].w;
	}
	std::sort(e + 1, e + m + 1, cmp);
	e[m + 1].w = inf;
	for (int i = 1; i <= k; i++) {
		std::cin >> c[i];
		for (int j = 1; j <= n; j++) {
			std::cin >> a[i][j];
		}
	}
	LL ans = inf;
	for (int i = 0; i < (1 << k); i++) {
		//std::cerr << i << ' ' << ans << "\n";
		LL sum = 0;
		int nn = n, len = 0;
		for (int j = 0; j < k; j++) {
			if (((1 << j)&i)) {
				nn++;
				sum += c[j + 1];
//				std::cerr << c[j + 1] << " ffyrfdyt";
				for (int o = 1; o <= n; o++) {
					tmp[++len].u = nn;
					tmp[len].v = o;
					tmp[len].w = a[j + 1][o];
				}
			}
		}
		std::sort(tmp + 1, tmp + len + 1, cmp);
		tmp[len + 1].w = inf;
		for (int o = 1; o <= nn; o++) {
			fa[o] = o;
		}
		int l = 1, r = 1;
		int cnt = 0;
		for (int o = 1; o <= m + len; o++) {
//			std::cout << e[l].u << " " << e[l].v << " " << e[l].w << "\n";
//			std::cout << tmp[r].u << " " << tmp[r].v << " " << tmp[r].w << "\n";
			if (e[l].w <= tmp[r].w) {
				tp[o] = e[l];
				l++;
			} else {
				tp[o] = tmp[r];
				r++;
			}
//			std::cout << tp[o].u << " " << tp[o].v << "\n";
			if (find(tp[o].u) != find(tp[o].v)) {
				fa[find(tp[o].u)] = find(tp[o].v);
				sum += tp[o].w;
				cnt++;
			}
//			std::cerr << nn << " " << cnt << " " << sum << " :";
//			for (int kk = 1; kk <= nn; kk++)
//				std::cout << fa[kk] << " ";
//			std::cout << "\n";
			if (cnt == nn - 1) {
				break;
			}
		}
//		if (cnt != nn - 1)
//			std::cout << "sasfe";
		ans = std::min(ans, sum);
//		std::cout << sum << "\n";
	}
	std::cout << ans;
}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	problem::solve();
	return 0;
}