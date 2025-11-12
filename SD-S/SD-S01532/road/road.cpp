#include <bits/stdc++.h>
using namespace std;

#define il inline
#define ri register int
#define ll long long
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define piii pair<ll,pii>
il ll read();

const int N = 10005;
const int M = 2000005;

int n, m, k, t;
struct node {
	int u, v;
	ll w;
} z[2000005][2];
struct edge {
	int to, nxt;
	ll w;
} e[2000005][2];
int h[N + 100][2], tot[2];
ll c[20], ans, cnt[2];
bool vis[N + 100];
priority_queue <piii, vector<piii>, greater<piii> > q;
int pds[N + 100], rpds[N + 100];
bool pd[20];

il void add(int u, int v, ll w)
{
	e[++tot[t ^ 1]][t ^ 1] = {v, h[u][t ^ 1], w}, h[u][t ^ 1] = tot[t ^ 1];
	e[++tot[t ^ 1]][t ^ 1] = {u, h[v][t ^ 1], w}, h[v][t ^ 1] = tot[t ^ 1];
}
void prime()
{
	q.push({0, {0, 1}});
	while (!q.empty()) {
		int now = q.top().second.second, from = q.top().second.first, ww = q.top().first;
		q.pop();
		if (vis[now]) continue;
		vis[now] = 1;
		if (now != 1) {
			add(from, now, ww);
			z[++cnt[t ^ 1]][t ^ 1].u = from, z[cnt[t ^ 1]][t ^ 1].v = now, z[cnt[t ^ 1]][t ^ 1].w = ww;
			ans += ww;
		}
		for (ri i=h[now][t]; i; i=e[i][t].nxt) {
			int v = e[i][t].to;
			if (!vis[v]) {
				q.push({e[i][t].w, {now, v}});
			}
		}
	}
}
void prime2(int s)
{
	t ^= 1;
	ll res = c[s];
	q.push({0, {0, 1}});
	for (ri i=1; i<=n; i++) {
		rpds[i] = pds[i];
	}
	while (!q.empty()) {
		int now = q.top().second.second, from = q.top().second.first, ww = q.top().first;
		q.pop();
		if (vis[now]) continue;
		vis[now] = 1;
		if (now != 1) {
			add(from, now, ww);
			if (from > n || now > n) {
				rpds[min(from, now)] = s;
			}
			z[++cnt[t ^ 1]][t ^ 1].u = from, z[cnt[t ^ 1]][t ^ 1].v = now, z[cnt[t ^ 1]][t ^ 1].w = ww;
			res += ww;
		}
		for (ri i=h[now][t]; i; i=e[i][t].nxt) {
			int v = e[i][t].to;
			if (!vis[v]) {
				q.push({e[i][t].w, {now, v}});
			}
		}
	}
	if (res < ans) {
		ans = res;
		t ^= 1;
		pd[s] = 1;
		for (ri i=1; i<=n; i++) {
			pds[i] = rpds[i];
		}
	}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (ri i=1; i<=m; i++) {
		ll u = read(), v = read(), w = read();
		add(u, v, w);
	}
	t ^= 1; 
	prime();
	for (ri i=1; i<=k; i++) {
		t ^= 1;
		tot[t ^ 1] = 0;
		cnt[t ^ 1] = 0;
		for (ri j=1; j<=n+i; j++) {
			h[j][t ^ 1] = 0;
			vis[j] = 0;
		}
		for (ri j=1; j<=cnt[t]; j++) {
			add(z[j][t].u, z[j][t].v, z[j][t].w);
		}
		c[i] = read();
		for (ri j=1; j<=n; j++) {
			int x = read();
			add(n + 1, j, x);
		}
		prime2(i);
	}
	for (ri i=1; i<=k; i++) {
		if (pd[i]) {
			bool check = 0;
			for (ri j=1; j<=n; j++) {
				if (pds[j] == i) {
					check = 1;
					break;
				}
			}
			if (!check) {
				ans -= c[i];
				for (ri i=h[i][t]; i; i=e[i][t].nxt) {
					ans -= e[i][t].w;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
il ll read()
{
	ll x = 0, f = 1;
	char c = getchar();
	while (c < '0' || '9' < c) {
		if (c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while ('0' <= c && c <= '9') {
		x = x * 10 + c - 48;
		c = getchar();
	}
	return x * f;
}
