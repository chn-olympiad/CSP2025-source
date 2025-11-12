#include<bits/stdc++.h>
using namespace std;
int read() {
	char c = getchar();
	int x = 0, f = 1;
	while(c < '0' || c > '9') {
		if(c == '-')f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
void write(long long x) {
	if(x < 0) {
		putchar('-');
		x = -x;
	} if(x > 9)write(x / 10);
	putchar((x % 10) + '0');
}
const int N = 1e4 + 10, M = 1e6 + 10, MOD = 1e9 + 7;
int n, m, k, fa[N], tot, rem[N], val[11], fr[11], to[N][11], wei[N][11], idx[11], siz[N];
long long ans;
int find(int x) {
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
void merge(int u, int v) {
	if(siz[u] < siz[v])swap(u, v);
	siz[u] += siz[v];
	fa[v] = u;
}
struct Edge {
	int u, v, w;
}e[M], tmp[N];
bool cmp(Edge x, Edge y) {
	return x.w < y.w;
}
void solve(int st) {
	long long sum = 0;
	for(int i = 1; i <= n; i++)fa[i] = i, siz[i] = 1;
	for(int i = 1; i <= k; i++)
		if((1 << (i - 1)) & st) {
			sum += val[i];
			idx[i] = 1;
		}
	for(int i = 1; i <= tot; i++) {
		int u, v;
		for(int j = 1; j <= k; j++)
			while(idx[j]) {
				if(wei[idx[j]][j] > e[i].w)break;
				u = find(fr[j]), v = find(to[idx[j]][j]);
				if(u != v) {
					merge(u, v);
					sum += wei[idx[j]][j];
				}
				if(++idx[j] == n)idx[j] = 0;
			}
		u = find(e[i].u), v = find(e[i].v);
		if(u != v) {
			merge(u, v);
			sum += e[i].w;
		}
	}
	ans = min(ans, sum);
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for(int i = 1; i <= n; i++)fa[i] = i, siz[i] = 1;
	for(int i = 1; i <= m; i++)e[i].u = read(), e[i].v = read(), e[i].w = read();
	sort(e + 1, e + m + 1, cmp);
	for(int i = 1; i <= m; i++) {
		int u = find(e[i].u), v = find(e[i].v);
		if(u != v) {
			rem[++tot] = i;
			merge(u, v);
			ans += e[i].w;
		}
	}
	for(int i = 1; i <= tot; i++)e[i] = e[rem[i]];
	for(int i = 1; i <= k; i++) {
		val[i] = read();
		for(int j = 1; j <= n; j++)
			tmp[j].v = j, tmp[j].w = read();
		sort(tmp + 1, tmp + n + 1, cmp);
		val[i] += tmp[1].w;
		fr[i] = tmp[1].v;
		for(int j = 2; j <= n; j++)to[j - 1][i] = tmp[j].v, wei[j - 1][i] = tmp[j].w;
	}
	for(int st = 1; st < (1 << k); st++)solve(st);
	write(ans);
	return 0;
}