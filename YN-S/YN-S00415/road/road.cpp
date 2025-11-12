#include <cstdio>
#include <algorithm>
using namespace std;

//Basic declaration
long long read() {
	long long s = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
		ch = getchar();
	while (ch >= '0' && ch <= '9') {
		s = (s << 3) + (s << 1) + (ch ^ 48);
		ch = getchar();
	}
	return s;
}
int n, m, k;
int val[11];


//ChainStar
//struct ChainStar {
//	int to, nex, v;
//	ChainStar(): to(0), nex(0), v(0) {}
//	ChainStar(const int &a, const int &b, const int &c): to(a), nex(b), v(c) {}
//	bool operator <(const ChainStar &x)const{
//		return this->v<x.v;
//	}
//} e[1000010];
//int head[10010], cnt = 0;
//
//inline void add_edge(const int &u, const int &v, const int &w) {
//	e[++cnt] = ChainStar(v, head[u], w);
//	head[u] = cnt;
//}

//edge
struct Edge {
	int u, v, w;
	bool operator <(const Edge &x)const {
		return this->w < x.w;
	}
} e[2000010];
//opt
long long ans = 0;
int f[10100], si[10100];

int find(int u) {
	if (!f[u])
		return u;
	return f[u] = find(f[u]);
}

bool join(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v)
		return false;
	if (si[u] > si[v]) {
		f[v] = u;
		si[u] += si[v];
	} else {
		f[u] = v;
		si[v] += si[u];
	}
	return true;
}

void kruskal() {
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		si[i] = 1;
	sort(e + 1, e + m + 1);
	for (int i = 1; i <= m; ++i) {
		if (cnt >= n)
			break;
		if (join(e[i].u, e[i].v)) {
			++cnt;
			ans += e[i].w;
		}
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read();
	m = read();
	k = read();
	for (int i = 1; i <= m; ++i) {
		e[i].u = read();
		e[i].v = read();
		e[i].w = read();
	}
	for (int i = 1; i <= k; ++i)
		val[i] = read();
	for (int i = 1; i <= k; ++i) {
		int p = n + i;
		for (int j = 1; j <= n; ++j) {
			++m;
			e[m].u = p;
			e[m].v = j;
			e[m].w = read();
		}
	}
	n += k;
	kruskal();
	printf("%d\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}