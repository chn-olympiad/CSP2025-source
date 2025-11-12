#include<bits/stdc++.h>

#define int long long

namespace IO {
	inline int read() {
		int ret = 0, f = 1;char ch = getchar();
		while (ch < '0' || ch > '9') {
			if (ch == '-') f = -f;
			ch = getchar();
		}
		while (ch >= '0' && ch <= '9') {
			ret = (ret << 1) + (ret << 3) + (ch ^ 48);
			ch = getchar();
		}
		return ret * f;
	}
	void write(int x) {
		if (x < 0) putchar('-'), x = -x;
		if (x > 9) write(x / 10);
		putchar(x % 10 + '0');
	}
}

using namespace IO;
using namespace std;

const int maxn = 1e5 + 5;
const int maxm = 2e6 + 5;
const int maxk = 10 + 5;
const int INF = 1e18;

struct Edge {
	int u, v, c;
	
	bool operator < (const Edge & x) const {
		return c < x.c;
	}
}e[maxm], E[maxm], ee[maxm];

int n, m, k, ANS;
int t[maxk][maxn];
int c[maxk];
int fa[maxn];

int Find(int x) {
	return fa[x] == x ? fa[x] : fa[x] = Find(fa[x]);
}

vector<int> use;

int GET(int x) {
	int Ans = 0, now = 1;
	
	while (x) {
		if (x & 1) Ans++, use.push_back(now);
		x >>= 1;now++;
	}
	
	return Ans;
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	n = read(), m = read(), k = read();
	
	int CNT = 0;
	for (int i = 1;i <= m;i++) {
		int x = read(), y = read(), c = read();
		ee[++CNT] = {x, y, c};
		ee[++CNT] = {y, x, c};
	}
	for (int i = 1;i <= k;i++) {
		c[i] = read();
		for (int j = 1;j <= n;j++) t[i][j] = read();
	}
	
	ANS = INF;
	
	sort(ee + 1, ee + 1 + CNT);
	iota(fa + 1, fa + 1 + n + k, 1);
	
	int Cnt = 0, ANs = 0, count = 0, Max = -INF;
	for (int i = 1;i <= CNT;i++) if (count < n) {
		int x = ee[i].u, y = ee[i].v, fx = Find(x), fy = Find(y);
		
		if (fx == fy) continue;
		
		fa[fx] = fy;
		ANs += ee[i].c;count++;
		E[++Cnt] = {ee[i].u, ee[i].v, ee[i].c};E[++Cnt] = {ee[i].v, ee[i].u, ee[i].c};
		Max = ee[i].c;
	}
	
	ANS = min(ANS, ANs);
	
	
	for (int i = 0;i < (1 << k);i++) {
		use.clear();use.shrink_to_fit();
		int cnt = GET(i) + n, tot = 0, ans = 0;
		
		for (int i = 1;i <= Cnt;i++) e[++tot] = E[i];
		
		
		iota(fa + 1, fa + 1 + n + k, 1);
		
		
		for (auto j : use) {
			ans += c[j];
			for (int l = 1;l <= n;l++) {
				if (t[j][l] < Max) e[++tot] = {l, j + n, t[j][l]};
				if (t[j][l] < Max) e[++tot] = {j + n, l, t[j][l]};
			}
		}
		
		sort(e + 1, e + 1 + tot);
		
		
		int count = 0;
		for (int j = 1;j <= tot;j++) if (count < cnt) {
			int x = e[j].u, y = e[j].v, fx = Find(x), fy = Find(y);
			
			if (fx == fy) continue;
			
			fa[fx] = fy;
			ans += e[j].c;count++;
		}
		
		ANS = min(ANS, ans);
	}
	
	write(ANS), putchar(10);
	
	return 0;
}
