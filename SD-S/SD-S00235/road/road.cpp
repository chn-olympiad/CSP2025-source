#include <bits/stdc++.h>
#define endl '\n'
#define debug(x) std::cerr << #x << " = " << x << ", LINE " << __LINE__ << endl;
#define split(x) std::cerr << "------------------------------------ SPLIT LINE ------------------------------------" << endl;
typedef long long ll;

struct Edge {
	int u, v;
	ll w;
	friend bool operator <(const Edge a, const Edge b) {
		return a.w < b.w;
	}
};

const int MOD = 1e9 + 7, N = 1e4 + 10;
int n, m, k;
ll c[N], a[12][N];
int fa[N];
std::pair<int, int> lit;
std::vector<std::pair<int, int> > graph[N];
Edge edge[N * N]; 

ll qpow(ll a, ll b) { ll ans = 1; while (b) { if (b & 1) ans = ans * a % MOD; a = a * a % MOD; b >>= 1; } return ans; }

ll read() {
	ll res = 0; short f = 1; char ch = getchar();
	while (!('0' <= ch && ch <= '9')) { if (ch == '-') f = -f; ch = getchar(); }
	while ('0' <= ch && ch <= '9') { res = res * 10 + ch - 48; ch = getchar(); }
	return res * f;
}

std::string readstr() {
	std::string ret; char ch = getchar();
	while (ch <= 32) ch = getchar();
	while (ch > 32) { ret += ch; ch = getchar(); }
	return ret;
}

char readch() {
	char ch = getchar();
	while (ch < 32) ch = getchar();
	return ch;
}

void write(ll x) {
	if (x < 0) { putchar('-'); write(-x); }
	else if (x <= 9) { putchar(x + 48); }
	else { write(x / 10); putchar(x % 10 + 48); }
}

void write(std::string x) {
	for (char ch : x) putchar(ch);
}

void writeln(ll x) { write(x); putchar('\n'); }

void writeln(std::string x) { write(x); putchar('\n'); }

void writes(ll x) { write(x); putchar(' '); }

void writes(std::string x) { write(x); putchar(' '); }

void init() {
	for (int i = 0; i < N; i++) {
		fa[i] = i;
	}
}

int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	x = find(x); y = find(y);
	fa[x] = y; return;
}

bool check(int x, int y) { return find(x) == find(y); }

ll kruskal(int cnt) {
	ll ans = 0;
	std::sort(edge + 1, edge + cnt + 1);
	for (int i = 1; i <= cnt; i++) {
		if (!check(edge[i].u, edge[i].v)) {
			merge(edge[i].u, edge[i].v);
			ans += edge[i].w;
		}
	}
	return ans;
}

void solve() {
	init();
	int cnt = 0, cur = 0;
	n = read(); m = read(); k = read();
	for (int i = 1; i <= m; i++) {
		int u = read(), v = read();
		ll w = read();
		graph[u].emplace_back(v, w);
		graph[v].emplace_back(u, w);
	}
	
	for (int i = 1; i <= k; i++) {
		c[i] = read();
		for (int j = 1; j <= n; j++) {
			a[i][j] = read();
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ll min = 0;
			if (graph[i][std::upper_bound(graph[i].begin(), graph[i].end(),
				std::make_pair(j, -1)) - graph[i].begin()].first != j) {
				min = 0x3f3f3f3f3f3f3f3f;
			} else {
				min = graph[i][std::upper_bound(graph[i].begin(), graph[i].end(),
				std::make_pair(j, -1)) - graph[i].begin()].second;
			}
			for (int l = 1; l <= k; l++) {
				min = std::min(min, c[l] + a[l][i] + a[l][j]);
			}
			edge[++cnt] = (Edge){i, j, min};
//			writes(i); write("->"); writes(j); writeln(min);
		}
	}
	writeln(kruskal(cnt));
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int t = 1;
	// t = read();
	while (t--) {
		solve();
	} return 0;
}

/*

个人认为 T2 比 T1 简单（至少 T2 60 分的性价比比 T1 100 高） 

首先 CCF 给了【图一定连通】这个信息，可能会用到。 

我们发现：k 的范围极小，0 <= k <= 10，所以考虑一个乘 k 的复杂度，不难想到
顶天的 1/2 * n^2 * k + m log m 的思路，结果这样只能拿 80 分。我勒个擦边一等啊

【我猜 21 ~ 25 测试点绝对有至少 3 个不会将 k 拉满】 
【神秘 Intel Core Ultra 9 285K CPU @ 3.70 GHz 一秒能跑 1e9】

知周所众，CCF 的评测机和你谷差【不多】，而 10/31 晚 LG 上有人 O(n^2) 5e4 过了
所以 LG 评测机加上服务器延迟一秒能跑 2.5e9
所以 CCF 评测机一秒能跑 3e9（

而且 CCF 的评测机再也不是老爷机了而是少爷机，应该能过那么一捏捏的点

最终预期分数：85

我勒个看看我电脑上 CCF 大样例多长时间 
 
*/ 
