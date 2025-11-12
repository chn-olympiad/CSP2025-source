#include <cstdio>
#include <algorithm>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int MAXSZ = 1 << 20;
char ch, buf[MAXSZ], *p1, *p2;
#define ge() (p1 == p2 && (p2 = buf + fread(p1 = buf, 1, MAXSZ, stdin), p1 == p2) ? EOF : *p1++)
template <typename T_T>
inline void read(T_T &x) {
	x = 0;
	
	while (ch < '0' || '9' < ch) ch = ge();
	while ('0' <= ch && ch <= '9') {
		x = x * 10 + (ch ^ 48);
		ch = ge();
	}
}
template <typename T_T>
inline void write(T_T x) {
	if (x > 9) write(x / 10);
	putchar(x % 10 | 48);
}
template <typename T_T>
inline T_T max(T_T a, T_T b) {return a > b ? a : b;}
template <typename T_T>
inline T_T min(T_T a, T_T b) {return a < b ? a : b;}

const int N = 1e4 + 15, M = 1e6 + 5, K = 15;
struct Ryan {
	int u, v;
	ll w;
	
	bool operator<(const Ryan &other) {
		return w < other.w;
	}
}edge[M + N * 10];
int n, m, k, fa[N], biao;
ll c[K], a[K][N];
bool vis[N];

int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return ;
	fa[x] = y;
}
ll Kruskal(int szcnt, int sz) {
	int cnt = 0;
	ll sum = 0;
	
	for (int i = 1; i <= sz; i++) {
		int u = edge[i].u, v = edge[i].v;
		ll w = edge[i].w;
		if (find(u) == find(v)) continue;
		
		merge(u, v);
		sum += w;
		vis[i] = true;
		if (++ cnt == szcnt - 1)
			return sum;
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	read(n), read(m), read(k);
	for (int i = 1; i <= m; i++)
		read(edge[i].u), read(edge[i].v), read(edge[i].w);
	
	bool F = true;
	for (int i = 1; i <= k; i++) {
		read(c[i - 1]);
		F &= (c[i - 1] == 0);
		for (int j = 1; j <= n; j++)
			read(a[i - 1][j]), F &= (a[i - 1][j] == 0);
	}
	if (F) {
		puts("0");
		fclose(stdin); fclose(stdout);
		return 0;
	}
	
	std::sort(edge + 1, edge + m + 1);
	for (int j = 1; j <= n; j++) fa[j] = j;
	ll ans = Kruskal(n, m);
	int temp = m;
	for (int mask = 1; mask < (1 << k); mask++) {
		int node = 0;
		ll sum = 0;
		
		for (int j = 0; j < k; j++) {
			if (mask & (1 << j)) {
				++ node;
				sum += c[j];
				
				for (int k1 = 1; k1 <= n; k1++)
					edge[++ m] = {j + n + 1, k1, a[j][k1]};
			}
		}
		
		if (sum > ans) continue;
		for (int j = 1; j <= n + node; j++) fa[j] = j;
		std::sort(edge + 1, edge + m + 1);
		ans = min(ans, Kruskal(node + n, m) + sum);
		m = temp;
	}
	
	write(ans), putchar('\n');
	fclose(stdin), fclose(stdout);
	return 0;
}