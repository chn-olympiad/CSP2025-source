#include<bits/stdc++.h>
using namespace std;

namespace z {
	
const int M = 1e6 + 5, N = 1.2e5 + 5;
//#define int long long
int n, m, k, c[15], w[15][N];
struct edge {
	int u, v, w;
	edge(int _u=0, int _v=0, int _w=0){u=_u,v=_v,w=_w;}
	bool operator<(const edge &rhs) const {
		return w < rhs.w; 
	}
} a[M], b[N], ed[N]; 
int sz[N], fa[N];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
	x = find(x), y = find(y);
	if(sz[x] > sz[y]) swap(x, y);
	fa[x] = y;
	sz[y] += sz[x];
} 
void init() {
	for(int i = 1; i <= n + k + 1; i++)
		fa[i] = i, sz[i] = 1;
} 
bool same(int x, int y){
	return find(x)==find(y);
}
void main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
//	cerr<<n<<" "<<m<<" "<<k<<'\n';
	for(int i = 1; i <= m; i++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	for(int i = 0; i < k; i++) {
		cin >> c[i];
		for(int j = 1; j <= n; j++)
			cin >> w[i][j];
	}
	sort(a + 1, a + m + 1);
	int cur = 0;
	init();
	for(int i = 1; i <= m; i++) {
		if(same(a[i].u, a[i].v)) continue;
		merge(a[i].u, a[i].v);
		b[++cur] = a[i];
	}
	long long ans = 1e18;
	for(int mask = 0; mask < (1 << k); mask++) {
		int tmpcur = cur;
		long long sum = 0, cnt = n;
		for(int i = 1; i <= cur; i++) ed[i] = b[i];
		for(int j = 0; j < k; j++) {
			if(mask >> j & 1) {
				sum += c[j]; cnt++;
				for(int i = 1; i <= n; i++){
					ed[++tmpcur] = edge(cnt, i, w[j][i]);
				}
			}
		}
		sort(ed + 1, ed + tmpcur + 1);
		init();
		for(int i = 1; i <= tmpcur; i++) {
			if(same(ed[i].u, ed[i].v)) continue;
			merge(ed[i].u, ed[i].v); sum += ed[i].w;
		}
		ans = min(ans, sum);
	}
	cout << ans << '\n';
}
	
//#undef int
	
} 

int main() {
	z::main();
	return 0;
}
