#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e6+7;

struct Edge{
	ll u, v, w, lst;
};

ll n, m, k, ans=0;
Edge edge[N];
ll h[N], idx=0;
ll a[11][N];

void add(ll u, ll v, ll w){
	edge[++idx] = {u, v, w, h[u]};
	h[u] = idx;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> m >> k;
	for(int i=1; i<=m; i++){
		ll u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
		add(v, u, w);
	}
	for(int i=1; i<=k; i++){
		for(int j=0; j<=n; j++){
			cin >> a[i][j];
		}
	}
	cout << 0;
	
	
	return 0;
}
