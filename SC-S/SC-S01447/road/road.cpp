#include <queue>
#include <string>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define fi first
#define se second
#define pii pair<ll , ll>
#define mk make_pair
#define ls x << 1
#define rs x << 1 | 1
using namespace std;
ll const N = 1e4 + 10 , M = 2e6 + 10 , K = 1.1e3 + 10 , P = 15;
ll n , m , k , cnt , fa[N] , c[P] , a[P][N] , ans = 1e18;
struct edge{
	ll u , v , w;
}e[M] , e2[K][N] , ep[M];
bool vis[N];
ll get(ll x){
	if (fa[x] == x) return x;
	return fa[x] = get(fa[x]);
}
void merge(ll u , ll v){
	u = get(u) , v = get(v);
	if (u != v) fa[u] = v;
}
queue <ll> que;
bool cmp(edge x , edge y){
	return x.w < y.w;
}
ll work(edge *e , ll num , ll s){
	ll cnt = 0 , ret = 0;
	for (int i = 1;i <= n + k;i ++) fa[i] = i;
	sort(e + 1 , e + num + 1 , cmp);
	for (int i = 1;i <= num;i ++){
		ll u = e[i].u , v = e[i].v , w = e[i].w;
		if (get(u) != get(v)){
			fa[get(u)] = get(v);
			ret += w;
			e2[s][++ cnt] = e[i];
		}
	}
	return ret;
}
void bfs(){
	for (int i = 1;i <= k;i ++) que.push(1 << i - 1) , vis[1 << i - 1] = 1;
	while (!que.empty()){
		ll u = que.front();
		que.pop();
		vis[u] = 1;
		ll s = 0 , p = 0 , res = 0 , num = 0;
		for (int i = 1;i <= k;i ++){
			if (u & (1 << i - 1)){
				s = u ^ (1 << i - 1);
				p = i;
				break;
			}
		}
		for (int i = 1;i <= k;i ++)
			if (u & (1 << i - 1)) res += c[i] , num ++;
		cnt = 0 , num --;
		for (int i = 1;i < n + num;i ++) ep[++ cnt] = e2[s][i];
		for (int i = 1;i <= n;i ++) ep[++ cnt] = {p + n , i , a[p][i]};
		ans = min(ans , work(ep , cnt , u) + res);
		for (int i = 1;i <= k;i ++)
			if (!(u & (1 << i - 1))){
				ll t = u | (1 << i - 1);
				if (!vis[t]) vis[t] = 1 , que.push(t);
			}
	}
}
signed main(){
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1 , u , v , w;i <= m;i ++){
		cin >> u >> v >> w;
		e[++ cnt] = {u , v , w};
	}
	for (int i = 1;i <= k;i ++){
		cin >> c[i];
		for (int j = 1;j <= n;j ++) cin >> a[i][j];
	}
	ans = min(ans , work(e , m , 0));
	bfs();
	cout << ans << "\n";
	return 0;
}
/*

*/