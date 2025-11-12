#include<bits/stdc++.h>
#define int long long
#define PII pair< int, int >

using namespace std;

const int N = 2e6 + 5, mod = 998244353;
int n, m, k, fa[N], cnt, b[N], c[N], daan, g[N/1000][N/1000];
pair< int, PII > edge[N];

template< typename T, typename ... L > inline void read(T &x){
	bool f = true;
	x = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9'){
		if (ch == '-') f = !f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9'){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	x = (f ? x : -x);
	return ;
}
template< typename T, typename ... L > inline void read(T &a, L && ... b){
	read(a);
	read(b ...);
}
int ksm(int a, int b, int p){
	int ans = 1;
	while (b){
		if (b & 1) ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}
int find(int x){ return (fa[x] == x ? x : fa[x] = find(fa[x])); }
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out","w",stdout);
	read(n, m, k);
	if (!k){
		for (int i = 1; i <= n; i++) fa[i] = i;
		for (int i = 1; i <= m; i++){
			int u, v, w;
			read(u, v, w);
			edge[++cnt] = {w, {u, v}};
		}
		sort(edge + 1, edge + cnt + 1);
		for (int i = 1; i <= cnt; i++){
			int x = find(edge[i].second.first), y = find(edge[i].second.second);
			if (x == y) continue;
			daan += edge[i].first;
			fa[x] = y;
		}
		printf("%lld", daan);
		return 0;
	}
	if (n <= 1000){
		for (int i = 1; i <= n; i++) fa[i] = i;
		memset(g, 0x3f, sizeof g);
		for (int i = 1; i <= m; i++){
			int u, v, w;
			read(u, v, w);
			g[u][v] = g[v][u] = min(g[u][v], w);
		}
		for (int i = 1; i <= k; i++){
			read(c[i]);
			for (int j = 1; j <= n; j++){
				read(b[j]);
				for (int k = 1; k < j; k++) g[j][k] = g[k][j] = min(g[j][k], c[i] + b[j] + b[k]);
			}
		}
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				if (g[i][j] != 0x3f3f3f3f3f3f3f3f)
					edge[++cnt] = {g[i][j], {i, j}};
			}
		}
		sort(edge + 1, edge + cnt + 1);
		for (int i = 1; i <= cnt; i++){
			int x = find(edge[i].second.first), y = find(edge[i].second.second);
			if (x == y) continue;
			daan += edge[i].first;
			fa[x] = y;
		}
		printf("%lld", daan);
		return 0;
	}
	for (int i = 1; i <= n; i++) fa[i] = i;
	memset(g, 0x3f, sizeof g);
	for (int i = 1; i <= m; i++){
		int u, v, w;
		read(u, v, w);
		edge[++cnt] = {w, {u, v}};
	}
	for (int i = 1; i <= k; i++){
		read(c[i]);
		int kkk = 0;
		for (int j = 1; j <= n; j++){
			read(b[j]);
			if (!b[j]) kkk = j;
		}
		for (int j = 1; j <= n; j++) edge[++cnt] = {b[j] + c[i], {kkk, j}};
	}
	sort(edge + 1, edge + cnt + 1);
	for (int i = 1; i <= cnt; i++){
		int x = find(edge[i].second.first), y = find(edge[i].second.second);
		if (x == y) continue;
		daan += edge[i].first;
		fa[x] = y;
	}
	printf("%lld", daan);
	return 0;
}
//freopen("a.in", "w", stdin);
//freopen("a.in", "r", stdout);
//freopen("a.out", "w", stdin);
//freopen("a.out", "r", stdout);

