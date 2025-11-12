#include<bits/stdc++.h>
#define endl '\n'
#define rep(A, B, C) for(int (A) = (B); (A) <= (C); A++)
#define dwn(A, B, C) for(int (A) = (B); (A) >= (C); A--)
#define int long long
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5, K = 15;
vector<pair<int, int> > g[N];
int c[K][N];
int n, m, k;
struct Edge{
	int u, v, w;
}E[M];
bool cmp(Edge a, Edge b){
	return a.w < b.w;
}
int fa[N], sz[N];
void init(){
	rep(i, 1, n) fa[i] = i, sz[i] = 1;
}
int find(int u){
	if(u == fa[u]) return u;
	return fa[u] = find(fa[u]);
}
void merge(int x, int y){
	x = find(x), y = find(y);
	if(sz[x] > sz[y]) swap(x, y);
	if(x == y) return;
	fa[x] = y;
	sz[y] += sz[x];
	return;
}
int MST(){
	sort(E + 1, E + 1 + m, cmp);
	init();
	int ans = 0;
	rep(i, 1, m){
		int u = E[i].u, v = E[i].v;
		u = find(u), v = find(v);
		if(u == v) continue;
		ans += E[i].w;
		merge(u, v);
	}
	return ans;
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	rep(i, 1, m){
		cin >> E[i].u >> E[i].v >> E[i].w;
	}
	bool A = 1;
	if(k == 0) A = 0;
	rep(i, 1, k){
		rep(j, 1, n){
			cin >> c[i][j];
			if(c[i][j]) A = 0;
		}
	}
	if(A){
		cout << 0 << endl;
		return 0;
	}
	int ans = MST();
	cout << ans << endl;
	return 0;
}

