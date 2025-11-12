#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define PI pair<int, int>
using namespace std;
const int maxn = 1e4 + 20, maxm = 1e6 + 10;
inline int read() {
	int res = 0; char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) res = (res << 1) + (res << 3) + (c ^ 48), c = getchar();
	return res;
}
int n, m, k;
int c[maxn], cur[maxn];
struct node{
	int u, v, w;
	bool operator <(const node &b) const {
		return w < b.w;
	}
} e[maxm], a[11][maxn];
struct DSU{
	int fa[maxn];
	void init(int n) {
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
	}
	int get(int x) {
		return x == fa[x] ? x : fa[x] = get(fa[x]);
	}
} T;
priority_queue<PI, vector<PI>, greater<PI> > pq;
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++) {
		e[i].u = read(), e[i].v = read(), e[i].w = read();
	}
	sort(e + 1, e + m + 1);
	T.init(n);
	int cnt = 0;
	long long ans = 0;
	for (int i = 1; i <= m; i++) {
		int u = T.get(e[i].u), v = T.get(e[i].v), w = e[i].w;
		if (u != v) {
			T.fa[u] = v;
			a[0][++cnt] = (node){u, v, w};
			ans += w;
		}
		if (cnt == n - 1) break;
	}
	if (k == 0) {
		printf("%lld", ans);
		return 0;
	}
	for (int i = 1; i <= k; i++) {
		c[i] = read();
		for (int j = 1; j <= n; j++) {
			a[i][j].w = read();
			a[i][j].u = n + i; a[i][j].v = j;
		}
		sort(a[i] + 1, a[i] + n + 1);
	}
	for (int t = 1; t < (1 << k); t++) {
		while (pq.size()) pq.pop();
		pq.push({a[0][1].w, 0});
		cur[0] = 1;
		int s = 0, cnt = 0;
		long long sum = 0;
		for (int i = 1; i <= k; i++) {
			if ((t >> i - 1) & 1) {
				pq.push({a[i][1].w, i});
				cur[i] = 1;
				s++; 
				sum += c[i];
			} 
		}
		T.init(n + k);
		while (cnt < n + s - 1) {
			int w = pq.top().first, id = pq.top().second;
			pq.pop();
			int u = a[id][cur[id]].u, v = a[id][cur[id]].v;
			u = T.get(u), v = T.get(v);
			if (u != v) {
				T.fa[u] = v; 
				sum += a[id][cur[id]].w;
				cnt++;
			}
			cur[id]++;
			if ((id == 0 && cur[id] < n) || (id && cur[id] <= n)) {
				pq.push({a[id][cur[id]].w, id});
			}
		}
		ans = min(ans, sum);
	}
	printf("%lld", ans);
	return 0;
}