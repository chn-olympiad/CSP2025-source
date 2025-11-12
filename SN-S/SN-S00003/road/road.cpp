#include <bits/stdc++.h>
#define il inline

using namespace std;

typedef long long ll;
const int N = 2e4 + 5, M = 1e6 + 5;
const ll Inf = 1e18;
template <typename T> il void chkmin(T &x, T y) {x = min(x, y);}
template <typename T> il void chkmax(T &x, T y) {x = max(x, y);}
bool Beg;
namespace My_Space {
struct IO {
	static const int Size = (1 << 21);
	char buf[Size], *p1, *p2; int st[105], Top;
	~IO() {clear();}
	il void clear() {fwrite(buf, 1, Top, stdout); Top = 0;}
	il char gc() {return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, Size, stdin), p1 == p2) ? EOF : *p1++;}
	il void pc(const char c) {Top == Size && (clear(), 0); buf[Top++] = c;}
	il IO &operator >> (char &c) {while(c = gc(), c == ' ' || c == '\n' || c == '\r'); return *this;}
	template <typename T> il IO &operator >> (T &x) {
		x = 0; int flg = 0; char c = gc();
		while(c < '0' || c > '9') {if(c == '-') flg = 1; c = gc();}
		while(c >= '0' && c <= '9') x = (x << 1) + (x << 3) + (c ^ 48), c = gc();
		flg ? x = -x : 0; return *this;
	}
	il IO &operator << (const char c) {pc(c); return *this;}
	template <typename T> il IO &operator << (T x) {
		if(x < 0) pc('-'), x = -x;
		do st[++st[0]] = x % 10, x /= 10; while(x);
		while(st[0]) pc('0' + st[st[0]--]);
		return *this;
	}
	il IO &operator << (const char *s) {for(int i = 0; s[i]; i++) pc(s[i]); return *this;}
}fin, fout;

int n, m, k, w[N];
struct Edge {
	int u, v, w;
	il bool operator < (const Edge &t) const {
		return w < t.w;
	}
}g[M], e[11][N], p[1 << 10][N], tmp[N];
int len[1 << 10];

int fa[N], siz[N];
il void init() {for(int i = 1; i <= n + k; i++) fa[i] = i, siz[i] = 1;}
il int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
il void link(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return ;
	if(siz[x] > siz[y]) swap(x, y);
	fa[x] = y, siz[y] += siz[x];
}

ll ans;
il void solve(int S) {
	int T = S ^ (S & (-S)), pos = __lg(S & (-S)) + 1;
	merge(e[pos] + 1, e[pos] + n + 1, p[T] + 1, p[T] + len[T] + 1, tmp + 1);
	init(); ll res = 0, cnt = n - 1;
	for(int i = 1; i <= k; i++) {
		if((S >> i - 1) & 1) {
			res += w[i], cnt++;
		}
	}
	len[S] = 0;
	for(int i = 1; i <= len[T] + n; i++) {
		int u = tmp[i].u, v = tmp[i].v;
		if(find(u) == find(v)) continue;
		res += tmp[i].w; cnt--;
		p[S][++len[S]] = tmp[i]; link(u, v);
		if(!cnt) break;
	}
	chkmin(ans, res);
}

il void main() {
	fin >> n >> m >> k;
	for(int i = 1, u, v, w; i <= m; i++) {
		fin >> u >> v >> w;
		g[i] = {u, v, w};
	}
	for(int i = 1; i <= k; i++) {
		fin >> w[i];
		for(int j = 1; j <= n; j++) {
			int c; fin >> c;
			e[i][j] = {j, i + n, c};
		}
		sort(e[i] + 1, e[i] + n + 1);
	}
	sort(g + 1, g + m + 1); init();
	len[0] = 0; ans = 0;
	for(int i = 1; i <= m; i++) {
		int u = g[i].u, v = g[i].v;
		if(find(u) == find(v)) continue;
		ans += g[i].w;
		p[0][++len[0]] = g[i]; link(u, v);
		if(len[0] == n - 1) break;
	}
	for(int S = 1; S < (1 << k); S++) solve(S);
	fout << ans << '\n';
}
}
il void File() {freopen("road.in", "r", stdin); freopen("road.out", "w", stdout);}
bool End;
il void Usd() {cerr << (&Beg - &End) / 1024.0 / 1024.0 << "MB " << (double)clock() * 1000 / CLOCKS_PER_SEC << "ms\n";}
int main() {
	File();
	My_Space::main();
	Usd();
	return 0;
}

