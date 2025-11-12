#include <bits/stdc++.h>
using namespace std;
const long long XN=1e4+10;
long long n, m, k, c[20], a[20][XN], ans;
int s[XN][XN];
struct node {
	long long u, v, w;
	node(long long _u, long long _v, long long _w) {
		u = _u; v = _v; w = _w;
	}
};
vector<node> e;
bool cmp(node x, node y) {
	return x.w<y.w;
}
long long fa[XN], sz[XN];
long long gf(long long x) {
	if (fa[x] == x) return x;
	return fa[x]=gf(fa[x]); 
}
void merge(long long x, long long y) {
	long long fx=gf(x), fy=gf(y);
	if (sz[fx] > sz[fy]) swap(fx, fy);
	fa[fx] = fy; sz[fy] += sz[fx];
	return;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(s, 0x3f, sizeof(s));
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		long long u, v, w; cin >> u >> v >> w;
		e.push_back(node(u, v, w));
		s[u][v] = s[v][u] = w;
	}
	for (int i = 1; i <= k; i++) {
		cin >> c[i];
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			for (int l = 1; l < j; l++) {
//				cout << c[i]+a[i][j]+a[i][l] << ' ';
				if (s[j][l]>c[i]+a[i][j]+a[i][l])
					e.push_back(node(j, l, c[i]+a[i][j]+a[i][l]));
			}
//			cout << "\n";
		}
	}
	for (int i = 1; i <= n; i++)
		fa[i] = i, sz[i] = 1;
	sort(e.begin(), e.end(), cmp);
	for (node i : e) {
		long long nu=i.u, nv=i.v, nw=i.w;
		if (gf(nu) != gf(nv)) {
			merge(nu, nv);
			ans += nw;
//			cout << nu << ' ' << nv << ' ' << nw << "\n";
		}
	}
	cout << ans; 
	return 0;
}

