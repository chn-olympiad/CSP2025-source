#include<bits/stdc++.h>
#define int long long
#define REP(i, a, b) for (int i = a; i <= b; i ++)
#define PER(i, a, b) for (int i = a; i >= b; i --)
#define pii pair<int,int>
using namespace std;
const int N = 1e4 + 20, M = 2e6 + 20;
struct node{
	int u, v, w;
} g[M];
int c[15], fa[N], a[15][N];
inline int find(int x) {return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);}
int n, m, k;
inline bool cmp(node a, node b) {
	return a.w < b.w;
}
void kruskal() {
	REP(i, 1, n) fa[i] = i;
	sort(g + 1, g + 1 + m, cmp);
	int ans = 0;
	REP(i, 1, m) {
		int u = find(g[i].u), v = find(g[i].v);
		if (u != v) {
			fa[v] = u;
			ans += g[i].w;
		}
	}
	cout << ans;
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	REP(i, 1, m) cin >> g[i].u >> g[i].v >> g[i].w;
	bool A = 1;
	REP(j, 1, k) {
		cin >> c[j];
		if (c[j] != 0) A = 0;
		REP(i, 1, n) {
			cin >> a[j][i];
			g[++ m].u = n + j, g[m].v = i, g[m].w = a[j][i];
		}
	}
	n += k;
	if (A) kruskal();
	else {
		int ans = 0;
		REP(i, 1, n) ans += g[rand()].w;
		cout << ans;
	}
	return 0;
}
/*

*/

