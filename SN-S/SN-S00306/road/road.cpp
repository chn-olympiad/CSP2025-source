#include<bits/stdc++.h>
using namespace std;

struct Info{
	int u, v, w, t;
	bool operator< (const Info &A) const {
		return w < A.w;
	}
} a[10000000];

int n, m, k, ans, edge, c[10010], d[10010], o[10010], fa[10010];

int find(int x){
	if(fa[x] == x){
		return x;
	}
	return fa[x] = find(fa[x]);
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		fa[i] = i;
	}
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		a[i] = {u, v, w, 0};
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> o[j];
		}
		for(int j = 1; j <= n; j++){
			for(int k = j + 1; k <= n; k++){
				a[++m] = {j, k, o[j] + o[k] + c[i], i};
			}
		}
	}
	sort(a + 1, a + m + 1);
	for(int i = 1; i <= m; i++){
		int u = a[i].u, v = a[i].v, w = a[i].w, t = a[i].t;
		if(edge == n - 1){
			break;
		}
		if(find(u) == find(v)){
			continue;
		}
		if(d[t]){
			w -= c[t];
		}
		d[t] = 1;
		fa[u] = find(v);
		ans += w;
		edge++;
		cout << u << " " << v << " " << w << "\n";
	}
	cout << ans << "\n";
	return 0;
}
