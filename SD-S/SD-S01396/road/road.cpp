#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e6 + 10;
const int N = 1e4 + 10;
ll n, m, k;
struct Edge{
	ll u, v, w, nxt, id;
}edge[M];
ll cnt, head[N], c[20], a[20][N];
void add(ll u, ll v, ll w){
	cnt++;
	edge[cnt].u = u;
	edge[cnt].v = v;
	edge[cnt].w = w;
	edge[cnt].nxt = head[u];
	head[u] = cnt;
}
bool cmp(Edge x, Edge y){
	return x.w < y.w;
}
ll fa[N];
ll find(ll x){
	if(x == fa[x]) return x;
	fa[x] = find(fa[x]);
}
void merge(ll x, ll y){
	ll fx = find(x), fy = find(y);
	if(fx != fy){
		fa[fy] = fx;
	}
	return;
}
inline ll read(){
	ll x = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for(int i = 1; i <= m; i++){
		ll u = read(), v = read(), w = read();
		add(u, v, w);
		add(v, u, w);
	}
	for(int i = 1; i <= k; i++){
		c[i] = read();
		for(int j = 1; j <= n; j++){
			a[i][j] = read();
			if(c[i] == 0){
				add(i, j, a[i][j]);
				add(j, i, a[i][j]);
			}
		}
	}
	for(int i = 1; i <= n; i++) fa[i] = i;
	sort(edge + 1, edge + 1 + m, cmp);
	ll cnt = 0, ans = 0;
	for(int i = 1; i <= m; i++){
		if(cnt == n - 1) break;
		ll u = edge[i].u, v = edge[i].v;
		if(find(u) != find(v)){
			cnt++;
			ans += edge[i].w;
			merge(u, v);
		}
	}
	printf("%lld", ans);
	return 0;
}

