#include<bits/stdc++.h>
using namespace std;
#define IO cin.tie(0);cout.tie(0);
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int N = 1e6;

struct E{
	int u,v;
	ll w;
};

int n,m,k;
vector<E> e;
ll ans = INF;
int dad[N+20];

int findx(int x){
	if (dad[x] == x) return x;
	return dad[x] = findx(dad[x]);
}
int hebing(int x, int y){
	dad[findx(x)] = findx(y);
}
ll check(ll res){
	for (int i = 1; i<=n+k; i++) dad[i] = i;
	sort(e.begin(), e.end(), [](E a, E b){
		return a.w < b.w;
		});
	for (int i = 0; i<e.size(); i++){
		int u = e[i].u;
		int v = e[i].v;
		if (findx(u) == findx(v)) continue;
		hebing(u,v);
		res += e[i].w;
		if (res > ans) return INF;
	}
	return res;
}

int main(){
	IO;
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin>>n>>m>>k;
	for (int i = 1; i<=m; i++){
		int u,v,w;
		cin>>u>>v>>w;
		e.push_back({u,v,w});
	}
	ans = check(0);
	// 不连通检查 
	int father = findx(1);
	for (int i = 1; i<=n; i++){
		if (dad[i] == i && i != father){
			ans = INF;
			break;
		}
	}
	
	ll ks = 0;
	for (int i = 1; i<=k; i++){
		ll c;
		ll res = ks;
		cin>>c;
		res += c;
		for (int j = 1; j<=n; j++){
			ll w;
			cin>>w;
			e.push_back({i+n, j, w});
		}
		res = check(res);
		if (res < ans) {
			ans = res;
			ks += c;
		}
	}
	cout << ans << '\n';
	return 0;
}
