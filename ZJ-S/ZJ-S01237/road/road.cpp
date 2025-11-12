#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e7+9;
ll n, m, k, u, v, w, a[15][N], ans = 0x3f3f3f3f;
ll ljb[5010][5010], s[N];
ll jz[N];
ll calc(){
	ll anss = 0;
	for(ll i=1;i<=k;i++){
		if(jz[i]){
			anss += a[i][0];
			for(ll j=1;j<=n;j++){
				for(ll z=i;z<=n;z++){
					ljb[j][z] = min(ljb[j][z], a[k][j]+a[k][z]);
					ljb[z][j] = min(ljb[z][j], a[k][j]+a[k][z]);
				}
			}
		}
	}
	memset(s, 0, sizeof(s));
	ll now = 1;
	for(ll i=1;i<n;i++){
		s[now] = 1;
		ll mmmin = 0x3f3f3f3f, tto = 0;
		for(ll j=1;j<=n;j++){
			if(now==j) continue;
			if(s[j]){
				continue;
			}
			if(mmmin>ljb[now][j]){
				mmmin = ljb[now][j];
				tto = j;
			}
		}
		now = tto;
		anss += mmmin;
	}
	return anss;
}
void dfs(ll kk){
	if(kk==k+1){
		ans = min(ans, calc());
		return;
	}
	jz[kk] = 1;
	dfs(kk+1);
	jz[kk] = 0;
	dfs(kk+1);
	return;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	scanf("%lld %lld %lld", &n,&m,&k);
	for(ll i=1;i<=m;i++){
		scanf("%lld %lld %lld", &u,&v,&w);
		ljb[u][v] = w;
		ljb[v][u] = w;
	}
	for(ll i=1;i<=k;i++){
		scanf("%lld", &a[i][0]);
		for(ll j=1;j<=n;j++){
			scanf("%lld", &a[i][j]);
		}
	}
	dfs(1);
	printf("%lld", ans);
	return 0;
}
