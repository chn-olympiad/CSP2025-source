#include<bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int N = 10100, M = 1000100, K = 10;
int n, m, k, fa[N], sz[N];
ll sum = 0, ans;
int cst[K], wa[K][N];
struct Edge{
	int u, v, w;
}E[M],ee[N],e[N+N*K],tmp[N+N*K];
bool operator<(Edge x, Edge y) { return x.w < y.w; }
int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int u,int v){
	if(sz[u]>sz[v])
		fa[v] = u;
	else
		fa[u] = v;
}
constexpr int L = 32768, R = 32767;
int f[L];
void qsort(int len){
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= len;i++)
		f[e[i].w & R]++;
	for (int i = 1; i < L;i++)
		f[i] += f[i - 1];
	for (int i = len; i;i--){
		tmp[f[e[i].w & R]--] = e[i];
	}
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= len;i++)
		f[e[i].w >>15]++;
	for (int i = 1; i < L;i++)
		f[i] += f[i - 1];
	for (int i = len; i;i--){
		e[f[tmp[i].w >>15]--] = tmp[i];
	}
}
ll solve(int I){
	int cnt = n - 1;
	for (int i = 1; i <= cnt;i++)
		e[i] = ee[i];
	ll ret = 0;
	for (int i = 1; i <= n+k;i++)
		fa[i] = i,sz[i]=1;
	for (int i = 0, cur = n; i < k;i++){
		if((I>>i)&1){
			ret += cst[i];
			int id = ++cur;
			for (int j = 1; j <= n;j++)
				e[++cnt] = (Edge){id, j, wa[i][j]};
		}
	}
	qsort(cnt);
	for (int i = 1; i <= cnt; i++){
		int fu = find(e[i].u), fv = find(e[i].v);
		if(fu!=fv){
			merge(fu, fv);
			ret += e[i].w;
		}
	}
	return ret;
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	// int st = clock();
	cin >> n >> m >> k;
	for (int i = 1; i <= m;i++)
		cin >> E[i].u >> E[i].v >> E[i].w;
	for (int i = 1; i <= n;i++)
		fa[i] = i,sz[i]=1;
	sort(E + 1, E + 1 + m);
	for (int i = 1, cnt = 0; i <= m; i++){
		int fu = find(E[i].u), fv = find(E[i].v);
		if(fu!=fv){
			merge(fu, fv);
			sum += E[i].w;
			ee[++cnt] = E[i];
		}
	}
	ans = sum;
	for (int i = 0; i < k;i++){
		cin >> cst[i];
		for (int j = 1; j <= n;j++)
			cin >> wa[i][j];
	}
	for (int i = 1; i < (1 << k); i++)
		ans = min(ans, solve(i));
	cout << ans << '\n';
	// cerr << (clock() - st) * 1000.0 / CLOCKS_PER_SEC << "ms\n";
	return 0;
}