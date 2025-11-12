#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

int read(){ int x = 0, f = 1; char ch = getchar(); while(!isdigit(ch)){ if(ch == '-') f = -1; ch = getchar(); } while(isdigit(ch)){ x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar(); } return x * f; }

const int N = 1e3 + 10;
int n, m, k, e[N][N], c[N], a[N][N], fa[N], sz[N], e1[N][N], ans, top, flag;
struct node{
	int u, v, w;
	bool operator < (const node &cmp) const { return w < cmp.w; }
}ed[N * N];

int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
} 

signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	n = read(); m = read(); k = read();
	memset(e, 0x3f, sizeof e);
	for(int i = 1; i <= n; ++ i)
		e[i][i] = 0, fa[i] = i;
	for(int i = 1, u, v, w; i <= m; ++ i){
		u = read(); v = read(); w = read();
		e[u][v] = min(e[u][v], w); e[v][u] = e[u][v];
		ed[++ top] = {u, v, w};
	}
	if(!k){
		sort(ed + 1, ed + 1 + top);
		for(int i = 1; i <= top; ++ i){
			int u = find(ed[i].u), v = find(ed[i].v);
			if(u != v){
				fa[u] = v;
				ans += ed[i].w;
			}
		} cout << ans << "\n"; exit(0);
	}
	for(int i = 1; i <= k; ++ i){
		c[i] = read();
		for(int j = 1; j <= n; ++ j)
			a[i][j] = read();
		if(c[i]) flag = 1;
	} 
	if(!flag){
		for(int i = 1; i <= k; ++ i){
			for(int j = 1; j <= n; ++ j)
				for(int f = 1; f <= n; ++ f)
					e[j][f] = min(e[j][f], a[i][j] + a[i][f]);
		} top = 0;
		for(int i = 1; i <= n; ++ i)
			for(int j = i + 1; j <= n; ++ j)
				ed[++ top] = {i, j, e[i][j]};
		sort(ed + 1, ed + 1 + top);
		for(int i = 1; i <= top; ++ i){
			int u = find(ed[i].u), v = find(ed[i].v);
			if(u != v){
				fa[u] = v;
				ans += ed[i].w;
			}
		} cout << ans << "\n"; exit(0);
	} ans = 1e16;
	for(int x = 0; x < (1 << k); ++ x){
		int res = 0, cnt = 0;
		memcpy(e1, e, sizeof e);
		for(int i = 1; i <= n; ++ i)
			fa[i] = i, sz[i] = 1;
		for(int i = 1; i <= k; ++ i){
			if(!((1 << (i - 1)) & x)) continue;
			res += c[i];
			for(int j = 1; j <= n; ++ j)
				for(int f = 1; f <= n; ++ f)
					e1[j][f] = min(e1[j][f], a[i][j] + a[i][f]);
		}top = 0;
		for(int i = 1; i <= n; ++ i)
			for(int j = i + 1; j <= n; ++ j)
				ed[++ top] = {i, j, e[i][j]};
		sort(ed + 1, ed + 1 + top);
		for(int i = 1; i <= top; ++ i){
			int u = find(ed[i].u), v = find(ed[i].v);
			if(u != v){
				if(++ cnt == n - 1) break;
				fa[u] = v;
				res += ed[i].w;
			}
		} ans = min(ans, res);
	} cout << ans << "\n";
	
	return 0;
}

