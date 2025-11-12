#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
const int N = 2e4 + 10, M = 2e6 + 10;
inline ll read(){
	ll x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-')
		  f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
inline void write(ll x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9)
	  write(x / 10);
	putchar(x % 10 + '0');
}
struct edge{
	int u, v, w;
	inline bool operator<(const edge&rhs)const{
		return w < rhs.w;
	}
}e[M];
ll ans = 1e18;
int n, m, k, cnt;
int fa[N], c[N], siz[N];
bool vis[M];
inline int getfa(int u){
	if(u != fa[u])
	  return fa[u] = getfa(fa[u]);
	return fa[u];
}
inline void merge(int x, int y){
	if(siz[x] > siz[y])
	  swap(x, y);
	fa[x] = y;
	siz[y] += siz[x];
}
inline void Kruskal(int S){
	ll sum = 0;
	int lim = 0;
	for(int i = 1; i <= n + k; ++i)
	  fa[i] = i, siz[i] = 1;
	for(int i = 1; i <= k; ++i){
		if((S >> (i - 1)) & 1){
			sum += c[i];
			++lim;
		}
	}
	if(sum >= ans)
	  return ;
	int num = 0;
	for(int i = 1; i <= cnt && num < n + lim; ++i){
		if(e[i].u > n && !((S >> (e[i].u - n - 1)) & 1))
		  continue;
		int u = getfa(e[i].u), v = getfa(e[i].v);
		if(u == v)
		  continue;
		vis[i] = 1;
		++num;	
		sum += e[i].w;
		if(sum >= ans)
		  return ;
//		cerr << e[i].u << ' ' << e[i].v << ' ' <, e[i].v
		merge(u, v);
	}
//	cerr << sum << ' ' << S << '\n'; 
	ans = min(ans, sum);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for(int i = 1; i <= m; ++i)
	  e[++cnt] = {(int)read(), (int)read(), (int)read()};
	sort(e + 1, e + cnt + 1);
	Kruskal(0);
	cnt = 0;
	for(int i = 1; i <= m; ++i)
	  if(vis[i])
	    e[++cnt] = e[i];
	for(int i = 1; i <= k; ++i){
		c[i] = read();
		for(int j = 1; j <= n; ++j)
		  e[++cnt] = {n + i, j, (int)read()};
	}
	sort(e + 1, e + cnt + 1);
	for(int S = 1; S < (1 << k); ++S)
	  Kruskal(S);
	write(ans);
	return 0;
}
