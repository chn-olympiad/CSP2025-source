#include<bits/stdc++.h>
using namespace std;
long long n, m, k , ans , x;
char lj;
struct node {
	int u, v, w;
} e[100010] , fw[5];
bool cmp(node& x, node & y) {
	return x.w < y.w;
}
vector<int> g[100010];
struct dsu {
	vector<int>pa,size;
	int cnt;
	dsu(int n) {
		pa.resize(n + 1);
		cnt = n;
		for (int i = 0; i <pa.size(); i++) {
			pa[i] = i;
		}
	}
	int find(int x) {
		if(x == pa[x]) return pa[x];
		return find(pa[x]);
	}
	void merge(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return ;
		pa[y] = x;
		cnt--;
	}
	int pd(int x, int y) {
		return find(pa[x]) == find(pa[y]);
	}
};
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	if(k == 0) {
		struct dsu uf(n);
		for (int i = 1; i <= m; i++) {
			cin >> e[i].u >> e[i].v >> e[i].w;
			if(e[i].u > e[i].v) swap(e[i].u , e[i].v);
		}
		sort(e + 1, e + m + 1 , cmp);
		for (int i = 1; i <= m ; i++) {
			if(uf.cnt == 1) {
				break;
			}
			if(uf.pd(e[i].u,e[i].v)) {
				continue;
			} else {
				uf.merge(e[i].u,e[i].v);
				ans += e[i].w;
			}
		}
		cout << ans;
	}
	else{
		vector<node> ed(m);
		for (int i = 1; i <= m; i++) {
			cin >> ed[i].u >> ed[i].v >> ed[i].w;
			if(ed[i].u > ed[i].v) swap(ed[i].u , ed[i].v);
		}
		for(int i = 1; i <= k; i++){
			cin >> lj;
			g[i].push_back(-1);
			for (int j = 1; j <= n; j++){
				cin >> x;
				g[i].push_back(x);
			}
		}
		for (int h = 1; h <= k; h++){
			for (int i = 1; i <= n; i++){
				for (int j = i + 1; j <= n; j++){
					fw[1].u = i, fw[1].v = j , fw[1].w = g[h][i] +g[h][j]; 
					ed.push_back(fw[1]);
				}
			}		
		}
		sort(ed.begin(),ed.end(),cmp);
		struct dsu uf(ed.size());
		for (int i = 1; i <= ed.size(); i++) {
			if(uf.cnt == 1) {
				break;
			}
			if(uf.pd(ed[i].u,ed[i].v)) {
				continue;
			} else {
				uf.merge(ed[i].u,ed[i].v);
				ans += ed[i].w;
			}
		}
		cout << ans;
	}
	return 0;
}
