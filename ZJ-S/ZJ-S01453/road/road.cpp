#include <bits/stdc++.h>
#define debug cout << "\n------------debug------------\n"
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef __int128 LLL;
typedef pair <int, int> PII;
typedef pair <LL, int> PLI;
typedef pair <int, LL> PIL;
typedef pair <LL, LL> PLL;

inline LL read() {
	LL x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -f;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + (ch - '0');
		ch = getchar();
	}
	return x * f;
}

inline void write(LL x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}

const LL MAXN = 1e4 + 25;
const LL MAXM = 1e6 + 5;
vector <PLL> G[MAXN];
LL N, M, K, dist[MAXN], cnt, ans, c[15];
bool vis[MAXN];

struct Node{
	LL v, w;
	friend operator < (const Node &a, const Node &b) {
//		if (a.v != b.v)
			return a.w > b.w;
//		else return a.v < b.v;
	}
};
priority_queue <Node> q;

inline void prim() {
	for (int i = 1; i <= N + K; ++i) {
		vis[i] = 0, dist[i] = 1e18;
	}
	dist[1] = 0, vis[1] = 1;
	q.push({1, 0});
	while (!q.empty()) {
//		debug;
		auto u = q.top().v; 
		ans += q.top().w;
		q.pop();
		vis[u] = 1;
		if (u <= N) {
			cnt++;
		}
		if (cnt >= N)
			return;
		for (auto p : G[u]) {
			auto v = p.first, w = p.second;
			if (v > N && vis[v])
				continue;
			if (!vis[v] && dist[v] > w) {
				dist[v] = w;
//				if (v > N)
//					vis[u] = 0;
				q.push({v, dist[v]});
			}
		}
	}
}

int main() {
	//ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	N = read(), M = read(), K = read();
	for (int i = 1; i <= M; ++i) {
		LL u = read(), v = read(), w = read();
		G[u].push_back({v, w}), G[v].push_back({u, w});
	}
//	debug;
	vector <LL> mmin(15, 1e18);
	for (int i = 1; i <= K; ++i) {
//		debug;
		c[i] = read();
		for (int j = 1; j <= N; ++j) {
			LL w = read(); mmin[i] = min(mmin[i], w);
			G[N + i].push_back({j, w}), G[j].push_back({N + i, c[i]});
		}
	}
//	debug;
	prim();
	for (int i = N + 1; i <= N + K; ++i) {
		if (vis[i]) {
			ans += mmin[i - N];
		}
	}
	write(ans);
	return 0;
}
/*
4 4 1
1 4 6
2 3 7
4 2 5
4 3 4
1 3 8 2 2

*/
