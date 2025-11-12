#include <cctype>
#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

int num; bool pn; char ch;
inline int read () {
	num = pn = 0, ch = getchar();
	while (!isdigit(ch)) pn = (ch == '-'), ch = getchar();
	while (isdigit(ch)) {
		num = (num << 3) + (num << 1) + (ch ^ 48);
		ch = getchar();
	}
	return (pn ? -num : num);
}

constexpr int N = 1e4 + 5;
constexpr int M = 1e6 + 5;
int n, m, k;

struct Edge {
	int u, v, w;
	friend inline bool operator < (Edge A, Edge B) {
		return A.w < B.w;
	}
} e[M << 1];
int tote;
int c[N << 1];
bool cu[N << 1];

ll fnl = 1e18;
int used;
int acc;

int fa[N << 1];
int findfa (int x) {
	return (x == fa[x] ? x : fa[x] = findfa(fa[x]));
}
inline bool bcjmerge (int x, int y) {
	x = findfa(x), y = findfa(y);
	if (x == y) return false;
	fa[x] = y;
	return true;
}

inline void deal (ll nowans) {
	if (nowans >= fnl) return;
	used = 0;
	for (int i = 1; i <= n + k; ++ i) fa[i] = i;
	for (int i = 1; i <= tote and used < n + acc - 1; ++ i) {
		if (!cu[e[i].u] or !cu[e[i].v]) continue;
		if (bcjmerge(e[i].u, e[i].v)) {
			nowans += e[i].w;
			if (nowans >= fnl) return;
			used ++;
		}
	}
	if (used == n + acc - 1) fnl = min(fnl, nowans);
}

void dfsk (int cun, ll csd) {
	if (cun == n + k + 1) {
		deal(csd);
		return;
	}
	dfsk(cun + 1, csd);
	cu[cun] = true;
	acc ++;
	dfsk(cun + 1, csd + c[cun]);
	cu[cun] = false;
	acc --;
}

int main () {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; ++ i) {
		e[i].u = read(), e[i].v = read(), e[i].w = read();
	}
	tote = m;
	int tmpl;
	for (int i = n + 1; i <= n + k; ++ i) {
		c[i] = read();
		for (int j = 1; j <= n; ++ j) {
			tmpl = read();
			e[++ tote] = {i, j, tmpl};
		}
	}
	sort(e + 1, e + tote + 1);
	for (int i = 1; i <= n; ++ i) cu[i] = true;
	dfsk(n + 1, 0);
	printf("%lld", fnl);
	return 0;
}