#include <bits/stdc++.h>
using namespace std;

inline int read();
void write(int);
void writeln(int);

const int N = 1e4 + 5;
int n, m, k, fa[200005], c[105], tot;
bool vis[20005];
long long ans = 1e18, res;
int getfa(int x) { return fa[x] == x ? x : fa[x] = getfa(fa[x]); }
struct Edge {
	int u, v, w;
} a[1500005];

signed main() {
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	n = read(), m = read(), k = read();
	for(int i = 1; i <= n; i++) vis[i] = 1;
	for(int i = 1; i <= m; i++) {
		int X = read(), Y = read(), Z = read();
		a[++tot] = (Edge){X, Y, Z};
	}
	for(int i = 1; i <= k; i++) {
		c[i] = read();
		for(int j = 1; j <= n; j++) {
			int x = read();
			a[++tot] = (Edge){i + n, j, x};
		}
	}
	sort(a + 1, a + tot + 1, [&](Edge a, Edge b) { return a.w < b.w; });
	for(int s = 0; s < (1 << k); s++) {
		for(int i = 1; i <= n + k; i++) fa[i] = i;
		res = 0; int ex = 0;
		for(int i = 1; i <= k; i++) {
			if((s >> (i - 1)) & 1) res += c[i], ex++;
			vis[i + n] = ((s >> (i - 1)) & 1);
		}
		int cnt = 0, i = 1;
		while(cnt < n + ex - 1) {
			int x = a[i].u, y = a[i].v, z = a[i].w; i++;
			if(!vis[x] || !vis[y]) continue;
			int fx = getfa(x), fy = getfa(y);
			if(fx == fy) continue;
			cnt++, res += z, fa[fx] = fy;
		}
		ans = min(ans, res);
	}
	printf("%lld\n", ans);
	
	return 0;
}

inline int read() {
	int res = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') f = (ch == '-' ? -1 : 1), ch = getchar();
	while(ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = getchar();
	return res * f;
}

void write(int x) {
	static int sta[35];
	int top = 0;
	do {
		sta[top++] = x % 10;
		x /= 10;
	} while(x);
	while(top) putchar(sta[--top] ^ 48);
}

void writeln(int x) {
	write(x);
	putchar('\n');
}
