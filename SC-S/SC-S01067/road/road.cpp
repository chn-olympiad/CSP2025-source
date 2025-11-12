#include <bits/stdc++.h>
using namespace std;
#define ll long long
template <typename T> inline void read(T &x) {
	x = 0; int f = 1; char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -1;
	for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
	x *= f;
}
const ll N = 1.1e4 + 11, M = 1.1e6 + 11, K = 1.1e5 + 11;
struct node {
	ll nxt, to, val;
}e[M << 1], ed[K << 1];
ll n, m, k, cnt = 1, hd[N], fa[N], ans, rec[N], tot, now, shu, bian;
ll hdd[N], cntd = 1, a[11][N], c[11];
priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > q[1100];
bool flag[11];
void add(ll u, ll v, ll w){e[++cnt].to = v, e[cnt].nxt = hd[u], e[cnt].val = w, hd[u] = cnt;}
void addd(ll u, ll v, ll w){ed[++cntd].to = v, ed[cntd].nxt = hdd[u], ed[cntd].val = w, hdd[u] = cntd;}
ll find(ll x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void kru(ll zhi) {
	while (!q[shu].empty()) {
		ll w = q[shu].top().first, num = q[shu].top().second; q[shu].pop();
		ll u = find(e[num].to), v = find(e[num ^ 1].to);
		if (u != v) fa[u] = v, rec[++tot] = num, now += w, ++bian;
		if (bian == zhi) break;
	}
	++shu;
}
void clearr() {
	cntd = 1, now = 0, bian = 0;
	for (int i = 1; i <= n + k; ++i) fa[i] = i, hdd[i] = 0;
	for (int i = 1; i <= tot; ++i) {
		ll u = e[rec[i]].to, v = e[rec[i] ^ 1].to, w = e[rec[i]].val;
		addd(u, v, w), addd(v, u, w);
		q[shu].push(make_pair(w, cntd));
	}
	for (int i = 1; i <= k; ++i) {
		if (flag[i]) {
			now += c[i];
			for (int j = 1; j <= n; ++j) {
				addd(i + n, j, a[i][j]), addd(j, i + n, a[i][j]);
				q[shu].push(make_pair(a[i][j], cntd));
			}
		}
	}
}
void cal(ll zhi) {
	while (!q[shu].empty()) {
		ll w = q[shu].top().first, num = q[shu].top().second; q[shu].pop();
		ll u = find(ed[num].to), v = find(ed[num ^ 1].to);
		if (u != v) fa[u] = v, now += w, ++bian;
		if (now >= ans || bian == zhi) break;
	}
	++shu;
}
void dfs(ll pos, ll sum) {
	if (!k) return ;
	if (pos == k) {
		clearr(); cal(n + sum - 1);
		ans = min(ans, now);
		return ;
	}
	flag[pos + 1] = 1;
	dfs(pos + 1, sum + 1);
	flag[pos + 1] = 0;
	dfs(pos + 1, sum);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n), read(m), read(k);
	for (int i = 1; i <= n + k; ++i) fa[i] = i;
	for (int i = 1; i <= m; ++i) {
		ll u, v, w; read(u), read(v), read(w);
		add(u, v, w), add(v, u, w);
		q[shu].push(make_pair(w, cnt));
	}
	bool vis = 0;
	for (int i = 1; i <= k; ++i) {
		read(c[i]);
		if (c[i]) vis = 1; 
		for (int j = 1; j <= n; ++j)
			read(a[i][j]);
	}
	if (!vis) {
		for (int i = 1; i <= k; ++i) {
			for (int j = 1; j <= n; ++j) {
				add(i + n, j, a[i][j]), add(j, i + n, a[i][j]);
				q[shu].push(make_pair(a[i][j], cnt));
			}
		}
		kru(n + k - 1);
		return printf("%lld\n", now), 0;
	}
	kru(n - 1);
	ans = now;
	dfs(0, 0);
	printf("%lld\n", ans);
	return 0;
}
/*
3 3 1
1 2 1
2 3 3
1 3 2

4 6 1
1 4 1
1 2 3
1 3 1
4 2 3
4 3 2
3 2 4
*/