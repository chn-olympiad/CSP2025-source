#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, x, y) for (int i = (x); i <= (y); i++)
#define per(i, x, y) for (int i = (x); i >= (y); i--)
int read() {
	int s = 0, f = 1; char c = getchar();
	while (!isdigit(c)) { if (c == '-') f = -1; c = getchar(); }
	while (isdigit(c)) s = s * 10 + (c ^ 48), c = getchar();
	return s * f;
}
constexpr int N = 1e4 + 5;
#define aii array<int, 2>
priority_queue<aii, vector<aii>, greater<aii>> pq, dq;
void ref() { 
	while (!pq.empty() && !dq.empty() && pq.top() == dq.top()) pq.pop(), dq.pop();
}
int n, m, K, ans0, f[N], c[15], a[15][N], b[15][N], kk[15]; bool vis[N];
array<int, 3> E[N * 100];
vector<aii> e[N];
int find(int x) { return (f[x] == x ? x : f[x] = find(f[x])); }
void kruskal() {
	sort(E + 1, E + m + 1);
	int cnt = 0;
	rep (i, 1, m) {
		int u = E[i][1], v = E[i][2], w = E[i][0];
		if (find(u) == find(v)) continue;
		f[find(u)] = find(v), e[v].push_back({w, u}), e[u].push_back({w, v}), ans0 += w; cnt++;
		if (cnt == n - 1) break;
	}
}
int iii, bp[15];
bool cmp(int x, int y) {
	return a[iii][x] < a[iii][y];
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	n = read(), m = read(), K = read();
	rep (i, 1, n) f[i] = i;
	rep (i, 1, m) {
		int u = read(), v = read(), w = read();
		E[i] = {w, u, v};
	}
	rep (i, 1, K) {
		c[i] = read();
		rep (j, 1, n) a[i][j] = read(), b[i][j] = j;
		iii = i;
		sort(b[i] + 1, b[i] + n + 1, cmp);
	} 
	kruskal();
	int S = (1 << K) - 1, ans = ans0;
	rep (F, 1, S) {
		int res = 0;
		rep (i, 1, n) vis[i] = 0;
		rep (i, 1, K) {
			bp[i] = 1;
			if ((F >> (i - 1)) & 1) res += c[i];
		}
		while (!pq.empty()) pq.pop(); while (!dq.empty()) dq.pop();
		for (auto to : e[1]) pq.push(to); vis[1] = 1;
		rep (i, 1, K) kk[i] = a[i][1];
		rep (T, 2, n) {
			ref();
			int ww = pq.top()[0], pp = pq.top()[1], oo = 0;
			rep (i, 1, K) if ((F >> (i - 1)) & 1) {
				while (vis[b[i][bp[i]]]) bp[i]++;
				int p = b[i][bp[i]];
				if (kk[i] + a[i][p] < ww) ww = kk[i] + a[i][p], pp = p, oo = i;
			}
//			if (oo == 0) pq.pop();
			kk[oo] = 0; vis[pp] = 1;
			rep (i, 1, K) kk[i] = min(kk[i], a[i][pp]);
			for (auto to : e[pp]) 
				if (vis[to[1]]) dq.push({to[0], pp});
				else pq.push(to);
			res += ww;
		}
		ans = min(ans, res);
	}
	cout << ans << '\n';
	return 0;
}
