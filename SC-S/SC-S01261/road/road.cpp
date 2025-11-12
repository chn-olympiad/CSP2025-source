// 输入量大记得快读，无向边记得开两倍。 
// n^2k被卡了。 
#include <bits/stdc++.h>
#define int long long
namespace FASTIO {
	static int ostk[33];
	char buf[1 << 23], *p1, *p2;
	#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 23, stdin), p1 == p2) ? EOF : *p1++)
	
	template <typename T>
	inline void read(T &x) {
		x = 0;
		T f = 1;
		char ch = getchar();
		while (!isdigit(ch)) {
			f = ch == '-' ? -1 : 1;
			ch = getchar();
		}
		while (isdigit(ch)) {
			x = (x << 1) + (x << 3) + (ch ^ 48);
			ch = getchar();
		}
		x *= f;
	}
	
	template <typename T, typename ...Args>
	inline void read(T &x, Args &...args) {
		read(x);
		read(args...);
	}
	
	template <typename T>
	inline void write(T x) {
		int top = 0;
		(x < 0) && (x = -x, putchar('-'));
		do { ostk[top++] = x % 10, x /= 10; } while(x);
		while(top) putchar(ostk[--top] | 48);
	}
}
using namespace std;
using namespace FASTIO;
const int maxn = 1e5 + 10;
const int maxm = 1e6 + 10;
int n, m, k, a[15][maxn], idx, ans, fa[maxn], cnt;
bool vis[15], flag;
struct Edges {
	int u, v, w, opt, k;
	Edges(int u = 0, int v = 0, int w = 0, int opt = -1, int k = 0):u(u), v(v), w(w), opt(opt), k(k){};
	bool operator < (const Edges &h) const {
		return (w == h.w) ? (opt > h.opt) : (w < h.w);
	}
} edge[maxm * 20];

int find(int x) {
	return (fa[x] == x) ? x : (fa[x] = find(fa[x]));
}

void kruskal() {
	sort(edge + 1, edge + idx + 1);
	for (int i = 1; i <= n; i++) {
		fa[i] = i; 
	}
	for (int i = 1; i <= idx; i++) {
		if (cnt == n - 1) {
			break;
		}
		Edges t = edge[i];
		int fu = find(t.u), fv = find(t.v);
		if (!t.opt) {
			if (fu != fv) {
				fa[fv] = fu;
				cnt++;
				ans += t.w;
			}
		}
		else {
			if (fu != fv) {
				fa[fv] = fu;
				cnt++;
				if (!vis[t.k]) {
					vis[t.k] = true;
					ans += t.w;
				}
				else {
					ans += t.w - a[t.k][0];
				}
			}
		}
	}
}

void specialA() {
	
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n, m, k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		read(u, v, w);
		edge[++idx] = Edges(u, v, w, 0, 0);
	}
	flag = true;
	for (int i = 1; i <= k; i++) {
		read(a[i][0]);
		flag &= (a[i][0] == 0);
		bool _flag = false;
		for (int j = 1; j <= n; j++) {
			read(a[i][j]);
			_flag |= (a[i][j] == 0);
		}
		flag &= _flag;
	}
	if (flag) {
		specialA();
		putchar('\n');
		return 0;
	} // Special A
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			for (int j = 1; j <= k; j++) {
				edge[++idx] = Edges(u, v, a[j][0] + a[j][u] + a[j][v], 1, j);
			}
		}
	}
	kruskal();
	write(ans);
	putchar('\n');
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
 */