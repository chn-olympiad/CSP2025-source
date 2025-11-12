#include <queue>
#include <cassert>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 10015, M = 1000005;
int milthm() {
	int x = 0, ch;
	do {
		ch = getchar();
	} while ('0' > ch);
	do {
		x = x * 10 + ch - 48;
		ch = getchar();
	} while ('0' <= ch);
	return x;
}
struct Edge {
	int u, v, w;
	void input() {
		u = milthm();
		v = milthm();
		w = milthm();
	}
} G[M], H[10][N];
int c[10];
bool operator < (const Edge & a, const Edge & b) {
	return a.w < b.w;
}
int fa[N];
void init(int n) {
	for (int u = 1; u <= n; u++) {
		fa[u] = u;
	}
}
int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y) {
	fa[find(x)] = find(y);
}
struct Link {
	int u, v, w, id;
	Link(const Edge & e, int id_) {
		u = e.u;
		v = e.v;
		w = e.w;
		id = id_;
	}
};
bool operator < (const Link & a, const Link & b) {
	return a.w > b.w;
}
priority_queue < Link > q;
struct Step {
	Edge * e;
	int p, n, id;
	void go() {
		if (p == n) {
			return;
		}
		q.push(Link(e[p], id));
		p++;
	}
} step[11];
bool tryit(const Link & l) {
	if (find(l.u) != find(l.v)) {
		merge(l.u, l.v);
		return true;
	}
	return false;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	n = milthm();
	m = milthm();
	k = milthm();
	for (int i = 0; i <= k; i++) {
		step[k].id = k;
	}
	for (int i = 0; i < m; i++) {
		G[i].input();
	}
	for (int j = 0; j < k; j++) {
		c[j] = milthm();
		for (int i = 0; i < n; i++) {
			H[j][i].u = j + n + 1;
			H[j][i].v = i + 1;
			H[j][i].w = milthm();
		}
	}
	for (int j = 0; j < k; j++) {
		sort(H[j], H[j] + n);
		step[j].e = H[j];
		step[j].n = n;
		step[j].id = j;
	}
	ll ans = 0;
	sort(G, G + m);
	step[k].e = G;
	step[k].n = m;
	step[k].p = 0;
	step[k].go();
	init(n + k);
	int cnt = 0;
	while (!q.empty()) {
		Link l = q.top();
		q.pop();
		if (tryit(l)) {
			G[cnt] = G[step[k].p - 1];
			cnt++;
			ans += l.w;
		}
		if (cnt == n - 1) {
			break;
		}
		step[k].go();
	}
	while (!q.empty()) {
		q.pop();
	}
	step[k].n = n - 1;
	for (int S = 1; S < (1 << k); S++) {
		init(n + k);
		ll res = 0;
		for (int i = 0; i < k; i++) {
			if (((S >> i) & 1) == 1) {
				step[i].p = 0;
				step[i].go();
				res += c[i];
			}
		}
		step[k].p = 0;
		step[k].go();
		while (!q.empty()) {
			Link l = q.top();
			q.pop();
			if (tryit(l)) {
				res += l.w;
				if (res >= ans) {
					break;
				}
			}
			step[l.id].go();
		}
		while (!q.empty()) {
			q.pop();
		}
		ans = min(ans, res);
	}
	printf("%lld\n", ans);
	return 0;
}
/*
Ren5Jie4Di4Ling5%
时间复杂度: O(2^k n k log k + m log m)
14:46 过小样例, club2 wa.
14:51 过大样例, 预期得分 100.
15:50 加个剪枝跑得飞快.
*/
