#include<bits/stdc++.h>
#define int long long
#define ll long long
#define PII pair<int, int>
#define Kg putchar(' ')
#define Ed putchar('\n')
bool __begin__;
using namespace std;
const ll N = 2e4 + 10, M = 2e6 + 10, inf = 1e9, INF = 1e18;
template<class T> inline void read(T &x){x = 0;int f = 1;char ch = getchar();for(; ch < '0' || ch > '9'; ch = getchar()){if(ch == '-'){f = -1;}}for(; ch >= '0' && ch <= '9'; ch = getchar()){x = (x << 3) + (x << 1) + (ch ^ 48);}x *= f;}
template<class T> inline void print(T x){if(x < 0){putchar('-'), print(-x);}else if(x < 10){putchar(x ^ 48);}else{print(x / 10), putchar((x % 10) ^ 48);}}
int n, m, k;
int u, v, w;
int a[11][N], c[11];
//set<pair<int, PII>>st;
struct edge{
	int u, v, w;
}e[M], e2[N];
int fa[N], f1, f2;
int find(int x){
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}
int cmp(edge x, edge y){
	return x.w < y.w;
}
int ans = INF, res, cnt, sum;
bool __end__;
signed main(){
//	printf("%dMB\n", (int)(&__begin__ - &__end__) >> 20);
//	freopen("road4.in", "r", stdin);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n), read(m), read(k);
	for(int i = 1; i <= m; i++){
		read(u), read(v), read(w);
		e[i] = {u, v, w};
//		st.insert({w, {u, v}});
	}
	for(int i = 1; i <= k; i++){
		read(c[i]);
		for(int j = 1; j <= n; j++) read(a[i][j]);
	}
	for(int i = 1; i <= n; i++) fa[i] = i;
	sort(e + 1, e + m + 1, cmp);
	for(int i = 1; i <= m; i++){
		u = e[i].u, v = e[i].v, w = e[i].w;
		f1 = find(u), f2 = find(v);
		if(f1 != f2){
			fa[f1] = f2;
			e2[++cnt] = e[i];
		}
	}
//	for(int i = 1; i < n; i++){
//		print(e2[i].u), Kg, print(e2[i].v), Kg, print(e2[i].w), Ed;
//	}
	for(int I = 0; I < 1 << k; I++){
		res = sum = 0;
		cnt = 0;
		for(int i = 1; i < n; i++) e[++cnt] = e2[i];
		for(int i = 1; i <= k; i++){
			if(!(I >> (i - 1) & 1)) continue;
			res += c[i];
			sum++;
			for(int j = 1; j <= n; j++){
				e[++cnt] = {n + sum, j, a[i][j]};
//				st.insert({a[i][j], {n + sum, j}});
			}
		}
		if(res > ans) break;
		for(int i = 1; i <= n + sum; i++) fa[i] = i;
		sort(e + 1, e + cnt + 1, cmp);
		for(int i = 1; i <= cnt; i++){
			u = e[i].u, v = e[i].v, w = e[i].w;
			f1 = find(u), f2 = find(v);
			if(f1 != f2){
				fa[f1] = f2;
				res += w;
			}
		}
//		print(sum), Kg;
//		print(res), Ed;
		ans = min(ans, res);
	}print(ans);
	return 0;
}

