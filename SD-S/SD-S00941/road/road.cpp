/*
author: WilliamFranklin
AFOed on 2025/11/1

我常常追忆过去，忘了。 

我该在哪里停留？我问我自己。 
*/
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp(Tx, Ty) make_pair(Tx, Ty)
#define For(Ti, Ta, Tb) for(auto Ti = (Ta); Ti <= (Tb); Ti++)
#define Dec(Ti, Ta, Tb) for(auto Ti = (Ta); Ti >= (Tb); Ti--)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define range(Tx) begin(Tx),end(Tx)
const int N = 1e4 + 5, M = 1e6 + 5, INF = 2e9;
int n, m, k;
struct node {
	int u, v, w;
} e[M];
int fa[N * 2];
int c[N];
pair<int, int> a[15][N];
int L[15], W[15];
int LL;
bool cmp(node a, node b) {
	return a.w < b.w;
}
int find(int x) {
	if (fa[x] == x) return x;
	fa[x] = find(fa[x]);
	return fa[x];
}
void U(int x, int y) {
	fa[find(y)] = find(x);
}
node get(int m) {
	node ans = {0, 0, INF};
	For(i, 1, m) {
		while (L[i] <= n && find(W[i] + n) == find(a[W[i]][L[i]].y)) L[i]++;
		if (L[i] <= n && a[W[i]][L[i]].x < ans.w) {
			ans.u = W[i] + n;
			ans.v = a[W[i]][L[i]].y;
			ans.w = a[W[i]][L[i]].x;
		}
	}
	while (LL <= n && find(e[LL].u) == find(e[LL].v)) LL++;
	if (LL <= n && e[LL].w < ans.w) ans = e[LL];
	return ans;
}
int main() {
	assert(freopen("road.in", "r", stdin));
	assert(freopen("road.out", "w", stdout));
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m >> k;
	For(i, 1, m) cin >> e[i].u >> e[i].v >> e[i].w;
	For(i, 1, k) {
		cin >> c[i];
		For(j, 1, n) {
			cin >> a[i][j].x;
			a[i][j].y = j;
		}
		sort(a[i] + 1, a[i] + n + 1);
	}
	sort(e + 1, e + m + 1, cmp);
	int l = 0;
	For(i, 1, n) fa[i] = i;
	For(i, 1, m) {
		if (find(e[i].u) == find(e[i].v)) continue;
		U(e[i].u, e[i].v);
		swap(e[++l], e[i]);
	}
	l++;
	e[l].u = 0, e[l].v = 0, e[l].w = INF;
//	For(i, 1, l) {
//		cout << e[i].u << ' ' << e[i].v << ' ' << e[i].w << '\n';
//	}
	long long ans = 1e18;
	For(i, 0, (1 << k) - 1) {
		int m = 0;
		For(j, 1, k) {
			if ((i >> j - 1) & 1) {
				W[++m] = j;
			}
		}
		For(i, 1, n + k) fa[i] = i;
		For(j, 1, m) L[j] = 1;
		long long now = 0;
		LL = 1;
		For(j, 1, k) if ((i >> j - 1) & 1) now += c[j];
//		cout << now << '\n';
		For(j, 1, n + m - 1) {
			node w = get(m);
			U(w.u, w.v);
			now += w.w;
		}
		ans = min(ans, now);
//		cout << m << ": ";
//		For(i, 1, m) cout << W[i] << ' ';
//		cout << ":   " << now << '\n'; 
	}
	cout << ans;
	return 0;
} 
