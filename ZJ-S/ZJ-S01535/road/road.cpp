#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x & (-x))
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5;
int fa[N], n, m, k;
struct edge{
	int u, v, w;
}e[M], t[N];
struct graph{
	int to, w;
};
bool cmp(edge x, edge y){return x.w < y.w;}
vector<graph> G[N];
int vlg[20][N], c[20], h[20][N];
int f[1050][N], vis[1050], dp[1050];
void sol(int x){
	if(vis[x])return;
	vis[x] = 1;
	if(x == lowbit(x)){
		int pos = log2(lowbit(x));
		for(int i = 1;i < n;i ++)f[x][i] = min(f[0][i], h[pos + 1][i]);
//		cout << '*' << pos << '\n';
//		for(int i = 1;i < n;i ++)cout << f[x][i] << ' ';
//		cout << '\n';
		return;
	}
	int q = lowbit(x), p = x - q;
	sol(q), sol(p);
	for(int i = 1;i <= n;i ++)
		f[x][i] = min(f[q][i], f[p][i]);
	return;
}
int find(int x){
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i ++)cin >> e[i].u >> e[i].v >> e[i].w;
	for(int i = 1;i <= k;i ++){
		cin >> c[i];
		for(int j = 1;j <= n;j ++)cin >> vlg[i][j];
	}
	sort(e + 1, e + m + 1, cmp);
	for(int i = 1;i <= n;i ++)fa[i] = i;
	int cnt = 0;
	for(int i = 1;i <= m;i ++){
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int fu = find(u), fv = find(v);
		if(fu == fv)continue;
		fa[fu] = fa[fv];
		t[++ cnt] = {u, v, w};
	}
	for(int i = 1;i < n;i ++){
		int u = t[i].u, v = t[i].v;
//		cout << u << ' ' << v << '\n';
		for(int j = 1;j <= k;j ++){
			h[j][i] = vlg[j][u] + vlg[j][v];
		}
	}
//	for(int i = 1;i <= k;i ++){
//		for(int j = 1;j < n;j ++){
//			cout << h[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	for(int i = 1;i < n;i ++)f[0][i] = t[i].w, dp[0] += f[0][i];
	vis[0] = 1;
	for(int i = 1;i <= (1 << k) - 1;i ++){
		sol(i);
		int x = i, y = 0;
		while(x){
			y += c[(int)(log2(lowbit(x)) + 1)];x -= lowbit(x);
		}
		for(int j = 1;j < n;j ++)dp[i] += f[i][k];
		dp[i] += y;
//		cout << i << '\n';
//		for(int j = 1;j < n;j ++)cout << f[i][j] << ' ';
//		cout << '\n';
	}
	int ans = 10000000000000;
	for(int i = 0;i <= (1 << k) - 1;i ++)ans = min(dp[i], ans);
	cout << ans << '\n';
	return 0;
}