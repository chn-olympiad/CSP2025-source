#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define upl(i, s, t, d) for(long long i = (s); i <= (t); i += (d))
#define dol(i, s, t, d) for(long long i = (s); i >= (t); i -= (d))
#define int long long
void INIT() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
}

const int MAXN = 1e4 + 100, MAXM = 3e6 + 100;
struct Edge {
	int u, v, w;
	int ex; // 这条边包含哪个乡村 
}G[MAXM];
bool cmp (const Edge &a, const Edge &b) {
	return a.w < b.w;
}
int cnt;

bool vex[MAXN]; // 乡村是否城市化 
int c[MAXN], w[MAXN]; 

struct Union_Set {
	int fa[MAXN];
	void init(int n) {
		upl(i, 1, n, 1)
			fa[i] = i;
	}
	int find(int x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
}U;

signed main() {
	INIT();
	
	int n, m, k;
	cin >> n >> m >> k;
	
	if(k == 0) {
		upl(i, 1, m, 1) {
			int u, v, w;
			cin >> u >> v >> w;
			G[++cnt] = {u, v, w, 0};
		}
		int ans = 0;
		U.init(n);
		sort(G + 1, G + 1 + cnt, cmp);
		upl(i, 1, cnt, 1) {
			int u = G[i].u, v = G[i].v, w = G[i].w, ex = G[i].ex;
			if(U.find(u) != U.find(v)) {
				U.fa[U.fa[u]] = U.fa[v];
				ans += w;
			}
		} 
		cout << ans;
		return 0;
	}
	
	static int ha[1020][1020]; // (i, j) 之间的最小边权 
	upl(i, 1, m, 1) {
		int u, v, w;
		cin >> u >> v >> w;
		G[++cnt] = {u, v, w, 0};
		ha[u][v] = ha[v][u] = w;
	}
	
	upl(i, 1, k, 1) {
		cin >> c[i];
		upl(j, 1, n, 1)
			cin >> w[j];
		upl(j, 1, n, 1) {
			upl(l, j + 1, n, 1) {
				if(w[j] + w[l] + c[i] < ha[j][l] || ha[j][l] == 0) {
					G[++cnt] = {j, l, w[j] + w[k] + c[i], i};
					ha[j][l] = w[j] + w[k] + c[i];
				}
			}
		}
	}
	
	int ans = 0;
	U.init(n);
	sort(G + 1, G + 1 + cnt, cmp);
	upl(i, 1, cnt, 1) {
		int u = G[i].u, v = G[i].v, w = G[i].w, ex = G[i].ex;
		cout << u << " " << v << " " << w << " " << ex << "\n";
		if(U.find(u) != U.find(v)) {
			U.fa[U.fa[u]] = U.fa[v];
			ans += w;
			if(ex) {
				if(!vex[ex]) // 暂未建设 
					vex[ex] = 1;
				else
					ans -= c[ex];
			}
		}
	} 
	cout << ans;
	return 0;
}

