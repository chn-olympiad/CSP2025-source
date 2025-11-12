#include <bits/stdc++.h>

bool stmb;

using namespace std;

const int N = 10010;
const int M = 1000010;
const int K = 20;

int n, m, k;
int c[K];
int a[K][N];
long long ans;
struct edge {
	int u, v, w;
	bool operator < (const edge &Other) const {return w < Other.w;}
} e[M + K * N];
struct DSU {
	int fa[N + K];
	int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
	void init() {for (int i = 1; i <= n; i++) fa[i] = i;}
	void merge(int x, int y) {fa[find(x)] = find(y);}
} F;

template <typename type>
void read(type &res) {
	type x = 0, f = 1;
	char c = getchar();
	for (; c < 48 || c > 57; c = getchar()) f = (c == '-') ? -f : f;
	for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c ^ 48);
	res = f * x;
}

template <typename type, typename ...Args>
void read(type &x, Args &...args) {read(x), read(args...);}

void FileIO() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
}

namespace Subtask1 {
	bool check() {return k == 0;}
	void Kruskal() {
		F.init();
		sort(e + 1, e + 1 + m);
		for (int i = 1; i <= m; i++) {
			if (F.find(e[i].u) == F.find(e[i].v)) continue;
			F.merge(e[i].u, e[i].v);
			ans += e[i].w;
		}
	}
	void solve() {
		Kruskal();
		printf("%lld", ans);
	}
}

namespace Subtask2 {
	bool check() {
		for (int i = 1; i <= k; i++) {
			if (c[i]) return false;
			bool ok = 0;
			for (int j = 1; j <= n; j++)
				if (!a[i][j]) {
					ok = 1;
					break;
				}
			if (!ok) return false;
		}
		return true;
	}
	void Kruskal() {
		F.init();
		sort(e + 1, e + 1 + m);
		for (int i = 1; i <= m; i++) {
			if (F.find(e[i].u) == F.find(e[i].v)) continue;
			F.merge(e[i].u, e[i].v);
			ans += e[i].w;
		}
	}
	void solve() {
		for (int i = 1; i <= k; i++) 
			for (int j = 1; j <= n; j++) 
				e[++m] = {n + i, j, a[i][j]};
		n += k;
		Kruskal();
		printf("%lld", ans);
	}
}

bool edmb;

int main() {
//	cerr << (&stmb - &edmb) / 1024.0 / 1024.0 << '\n';
	FileIO();
	read(n, m, k);
	for (int i = 1; i <= m; i++) read(e[i].u, e[i].v, e[i].w);
	for (int i = 1; i <= k; i++) {
		read(c[i]);
		for (int j = 1; j <= n; j++) 
			read(a[i][j]);
	}
	if (Subtask1::check()) Subtask1::solve();
	else if (Subtask2::check()) Subtask2::solve();
	return 0;
}

