#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	while(!isdigit(c)) {
		if(c == '-')
			f = -1;
		c = getchar();
	}
	while(isdigit(c)) {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
const int N = 1e4 + 5;
const int M = 1e6 + 5;
int n, m, k, f[N], c[11];
ll a[11][N], p, ans;
struct Edge {
	int u, v;
	ll w;
} e[M << 3];
bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}
int getf(int x) {
	return x == f[x] ? x : f[x] = getf(f[x]);
}
void kruskal() {
	for(int i = 1; i <= n + k; ++i) f[i] = i;
	sort(e + 1, e + m + 1, cmp);
	ll cnt = 0, sum = 0;
	for(int i = 1; i <= m; ++i) {
		int fu = getf(e[i].u), fv = getf(e[i].v);
		if(fu == fv) continue;
		sum += e[i].w;
		f[fu] = fv;
		if(++cnt == n + k - 1) break;
	}
	ans = sum;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n = read(), m = read(), k = read();
	for(int i = 1; i <= m; ++i) 
		e[i].u = read(), e[i].v = read(), e[i].w = read();
	for(int i = 1; i <= k; ++i) {
		c[i] = read();
		p += c[i];
		for(int j = 1; j <= n; ++j)
			a[i][j] = read();
	}
	if(!k) {
		kruskal();
		cout << ans;
		return 0;
	}
	if(!p) {
		for(int i = 1; i <= k; ++i)
			for(int j = 1; j <= n; ++j)
				e[++m] = (Edge){i + n, j, a[i][j]};
		kruskal();
		cout << ans;
		return 0;
	}
	return 0;
}

