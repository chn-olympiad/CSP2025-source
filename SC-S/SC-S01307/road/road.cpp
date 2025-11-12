#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e6 + 10, K = 15, N = 1e4 + 10;
const ll INF = 1e18;
struct EDGE{
	ll u, v;
	ll w;
	friend bool operator < (EDGE x, EDGE y){
		return x.w < y.w;
	}
}edge[M], ed[M + K * N];
ll c[K], a[K][N], ans;
ll n, m, k, fa[N + K];
int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
bool vis[K];
void dfs(int t){
	if(t > k){
		for(int i = 1; i <= n + k; i++) fa[i] = i;
		int pedge = m;
		for(int i = 1; i <= m; i++) ed[i] = edge[i];
		ll sum = 0;
		for(int i = 1; i <= k; i++){
			if(vis[i]){
				sum += c[i];
				for(int j = 1; j <= n; j++){
					ed[++pedge] = {i + n, j, a[i][j]};
				}
			}
		}
		sort(ed + 1, ed + pedge + 1);
		for(int i = 1; i <= pedge; i++){
			int u = ed[i].u, v = ed[i].v;
			ll w = ed[i].w;
			u = find(u), v = find(v);
			if(u != v){
				fa[v] = u;
				sum += w;
			}
		}
		ans = min(ans, sum);
		return;
	}
	vis[t] = 1;
	dfs(t + 1);
	vis[t] = 0;
	dfs(t + 1);
}
void read(ll &x){
	x = 0;
	char c = getchar();
	while(!('0' <= c && c <= '9')) c = getchar();
	while('0' <= c && c <= '9') {
		x = (x << 1) + (x << 3) + c - '0';
		c = getchar();
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n), read(m), read(k);
	for(int i = 1; i <= m; i++){
		ll u, v, w;
		read(u), read(v), read(w);
		edge[i] = {u, v, w};
	}
	for(int i = 1; i <= k; i++){
		read(c[i]);
		for(int j = 1; j <= n; j++) read(a[i][j]);
	}
	ll cnt = 0, _m = m;
	while(_m){
		cnt++;
		_m >>= 1;
	}
	bool FA = true;
	for(int i = 1; i <= k; i++){
		if(c[i]) FA = false;
		bool hav = false;
		for(int j = 1; j <= n; j++){
			if(!a[i][j]) hav = true;
		}
		if(!hav) FA = false;
	}
	if((1ll << k) * m * cnt <= 200000000){
		ans = INF;
		dfs(1);
		printf("%lld\n", ans);
	}else if(FA){
		for(int i = 1; i <= n + k; i++) fa[i] = i;
		int pedge = m;
		for(int i = 1; i <= m; i++) ed[i] = edge[i];
		ll sum = 0;
		for(int i = 1; i <= k; i++){
			sum += c[i];
			for(int j = 1; j <= n; j++){
				ed[++pedge] = {i + n, j, a[i][j]};
			}
		}
		sort(ed + 1, ed + pedge + 1);
		for(int i = 1; i <= pedge; i++){
			int u = ed[i].u, v = ed[i].v;
			ll w = ed[i].w;
			u = find(u), v = find(v);
			if(u != v){
				fa[v] = u;
				sum += w;
			}
		}
		printf("%lld\n", sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}