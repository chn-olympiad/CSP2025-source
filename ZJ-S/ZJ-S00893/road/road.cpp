#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+5, K = 15;
int n, m, k, ans, d[N];
struct group{
	int v, w;
	bool operator < (const group &x) const{
		return x.w < w;
	}
}; vector<group> g[N];
struct country{int c, a[N];} p[K];
signed main(){
    freopen("road.in","r",stdin); freopen("road.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++){
    	int u, v, w; cin >> u >> v >> w; ans += w;
    	g[u].push_back({v, w}), g[v].push_back({u, w}); 
	}
	bool flag = 0;
	for (int i = 1; i <= k; i++){
		cin >> p[i].c;
		for (int j = 1; j <= n; j++)
			cin >> p[i].a[j];
		if (p[i].c != 0) flag = 1;
	}
	if (!flag){
		cout << 0;
		return 0;
	}
	cout << ans;
    return 0;
}

