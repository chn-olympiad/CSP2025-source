#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAXN = 1e4 + 5;
const int MAXM = 1e6 + 5;
const int MAXK = 15;
const long long INF = 0x3f3f3f3f3f3f3f3f;
struct Edge{
	int u, v;
	long long w;
	bool operator<(const Edge &rhs) const{
		return w < rhs.w;
	}
}edges[MAXN << 1];
long long c[MAXK], g[MAXK][MAXN];
int fa[MAXN];
int find(int u){return fa[u] == u ? u : fa[u] = find(fa[u]);}
long long ans = INF;
int n, m, k, sz;

inline long long read(){
	long long num = 0, sign = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9')
		sign = (ch == '-' ? -1 : 1), ch = getchar();
	while(ch >= '0' && ch <= '9')
		num = (num << 1) + (num << 3) + ch - 48,
		ch = getchar();
	return sign > 0 ? num : -num;
}

long long kruskal(){
	sort(edges + 1, edges + 1 + sz);
	for(int i = 1; i <= n; i++) fa[i] = i;
	long long ans = 0, cnt = 0;
	for(int i = 1; i <= sz && cnt < n - 1; i++){
		int u = edges[i].u, v = edges[i].v;
		long long w = edges[i].w;
		if(find(u) == find(v)) continue;
		ans += w, cnt++, fa[find(u)] = find(v);
	}
	return ans;
}

void dfs(int x, int num, int st, long long w){
	if(x > num){
		ans = min(ans, kruskal() + w);
		return;
	}
	for(int i = st; i <= k; i++){
		int tmp = sz;
		for(int u = 1; u <= n; u++)
			for(int v = u; v <= n; v++)
				edges[++sz] = {u, v, g[i][u] + g[i][v]},
				edges[++sz] = {v, u, g[i][u] + g[i][v]};
		dfs(x + 1, num, i + 1, w + c[i]);
		sz = tmp;
	}
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for(int i = 1, u, v, w; i <= n; i++)
		u = read(), v = read(), w = read(),
		edges[++sz] = {u, v, w}, edges[++sz] = {v, u, w};
	for(int i = 1; i <= k; i++){
		c[i] = read();
		for(int j = 1; j <= n; j++)
			g[i][j] = read();
	}
	ans = kruskal();
	for(int i = 1; i <= k; i++)
		dfs(1, i, 1, 0);
	cout<< ans<< "\n";
	fclose(stdin); fclose(stdout);
	return 0;
} 
