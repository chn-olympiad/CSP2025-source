#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
	T s = 0; int st = 1; char c = getchar();
	while(c < '0' || c > '9'){(c == '-') && (st = -1); c = getchar();}
	while(c >= '0' && c <= '9'){s = (s << 3) + (s << 1) + (c ^ 48); c = getchar();}
	x = s * st;
}
template<typename T> inline void write(T x){
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
//#define int long long
#define LL long long
#define PII pair<int, int>
const int N = 1e4, M = 1e6, K = 10;
struct node{
	int u, v;
	LL w;
};
node e[M + 5];
int a[K + 5][N + 5], c[K + 5], pre[N + 5];
bool vis[K + 5];
int find(int x){
	if(pre[x] == x) return x;
	else return pre[x] = find(pre[x]);
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	read(n), read(m), read(k);
	for(int i = 1; i <= m; ++i){
		int u, v; LL w;
		read(u), read(v), read(w);
		e[i] = (node){u, v, w};
	}
	for(int i = 1; i <= k; ++i){
		read(c[i]);
		for(int j = 1; j <= n; ++j){
			read(a[i][j]);
		}
	}
	sort(e + 1, e + 1 + m, [](node i, node j){
		return i.w < j.w;
	});
	for(int i = 1; i <= n; ++i){
		pre[i] = i;
	}
	LL ans = 0;
	for(int i = 1; i <= m; ++i){
		if(find(e[i].u) == find(e[i].v)) continue;
		LL w = e[i].w, tmp; int tp = 0;
		for(int j = 1; j <= k; ++j){
			tmp = (LL)a[j][e[i].u] + a[j][e[i].v] + (vis[j] ? 0 : c[j]);
			if(w > tmp){
				w = tmp;
				tp = j;
			}
		}
		vis[tp] = 1;
		ans += w;
	}
	write(ans);
	return 0;
}
