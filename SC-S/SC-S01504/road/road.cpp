#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef unsigned long long ull;
const int N = 1e4 + 15;
int n,m,k;
ll res[1 << 10],ans = 1e18;
vector<array<int,3>> ed;
struct DSU {
	int fa[N],sz[N];
	DSU() {
		iota(fa,fa + N,0);
		fill(sz,sz + N,1);
	}
	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
	bool merge(int u,int v) {
		u = find(u),v = find(v);
		if(u == v) return 0;
		if(sz[u] > sz[v]) swap(u,v);
		return sz[fa[u] = v] += sz[u],1;
	}
	bool same(int u,int v) {
		return find(u) == find(v);
	}
} ds[1 << 10];
void solve() {
	cin >> n >> m >> k;
	ed.reserve(m + k * n + 5);
	for(int i = 1,u,v,w;i <= m;i ++) {
		cin >> u >> v >> w;
		ed.push_back({w,u,v});
	}
	for(int i = 1,w;i <= k;i ++) {
		cin >> res[1 << (i - 1)];
		for(int j = 1;j <= n;j ++) {
			cin >> w;
			ed.push_back({w,j,n + i});
		}
	}
	for(int i = 1;i < (1 << k);i ++) {
		if(i == (i & -i)) continue;
		res[i] = res[i ^ (i & -i)] + res[i & -i];
	}
	sort(ed.begin(),ed.end());
	for(auto e : ed) {
		int w = e[0],u = e[1],v = e[2];
		for(int i = 0;i < (1 << k);i ++) {
			if(v > n && !(i >> (v - n - 1) & 1)) continue;
			if(ds[i].merge(u,v)) {
				res[i] += w;
			}
		}
	}
	for(int i = 0;i < (1 << k);i ++) {
		ans = min(ans,res[i]);
	}
	cout << ans << "\n";
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t = 1;
//	cin >> t;
	while(t --) solve();
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/