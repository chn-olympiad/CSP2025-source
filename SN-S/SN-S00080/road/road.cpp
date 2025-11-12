//刘益铭 SN-S00080 西安高新第一中学
#include<bits/stdc++.h>
#define ll long long

const int N = 2e4 + 5;
const int M = 15;

int n,m,k,c[M],a[M][N],fa[N];

ll ans = 1e18,cnt;

struct node {
	int u,v;
	ll w;
};

std::vector<node> e;

std::vector<node> d;

bool vis[M];

bool cmp(node x,node y) {
	return x.w < y.w;
}

int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void unionn(int x,int y) {
	x = find(x);
	y = find(y);
	if(x == y) return;
	fa[x] = y;
}

void kruskal() {
	for(int i = 1;i<=n+k;i++) fa[i] = i;
	sort(d.begin(),d.end(),cmp);
	ll sum = 0;
	for(auto it : d) {
		int u = it.u;
		int v = it.v;
		ll w = it.w;
		if(find(u) != find(v)) {
			unionn(u,v);
			sum += w;
		}
	}
	ans = std::min(ans,sum + cnt);
	d.clear();
}

void solve() {
	cnt = 0;
	for(auto it : e) d.push_back(it);
	for(int i = 1;i<=k;i++) {
		if(vis[i]) {
			cnt += c[i];
			for(int j = 1;j<=n;j++) d.push_back({j,n+i,a[i][j]});
		}
	}
	kruskal();
}

void dfs(int x) {
	if(x > k) {
		solve();
		return;
	}
	dfs(x+1);
	vis[x] = true;
	dfs(x+1);
	vis[x] = false;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	std::cin >> n >> m >> k;
	for(int i = 1;i<=m;i++) {
		int u,v;
		ll w;
		std::cin >> u >> v >> w;
		e.push_back({u,v,w});
		d.push_back({u,v,w});
	}
	for(int i = 1;i<=k;i++) {
		std::cin >> c[i];
		for(int j = 1;j<=n;j++) std::cin >> a[i][j];
	}
	dfs(1);
	std::cout << ans;
	return 0;
} 
