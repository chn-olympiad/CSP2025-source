#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 1e6 + 10;
int n, m, k;
struct edge{
	int u, v;
	ll w;
};
edge e[N];
ll f[N];

int find(int x){
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}

bool cmp(edge x, edge y){
	return x.w < y.w; 
}

ll kruskal(){
	ll ans = 0;
	for (int i = 1; i <= n; i ++){
		f[i] = i;
	}
	for (int i = 1; i <= m; i ++){
		int pa = e[i].u, pb = e[i].v;
		ll ab = e[i].w;
		if (find(pa) != find(pb)){
			f[find(pb)] = find(pa);
			ans += e[i].w;
		}
	}
	return ans;
}

int main(){
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++){
		edge x;
		cin >> x.u >> x.v >> x.w;
		e[i].u = x.u;
		e[i].v = x.v;
		e[i].w = x.w;
	}
	for (int i = 1; i <= k; i ++){
		ll qqq;
		for (int j = 1; j <= n; j ++){
			cin >> qqq;
		}
	}
	sort(e + 1, e + m + 1, cmp);
	cout << kruskal();
	
	return 0;
}
