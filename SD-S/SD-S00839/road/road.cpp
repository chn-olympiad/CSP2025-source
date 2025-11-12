//See You, My OIer Life 

#include <bits/stdc++.h>

typedef long long ll;
const ll MAXN = 1e6 + 1005;

ll read() {
	ll x = 0, f = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
	while(c >= '0' && c <= '9') {x = (x << 1) + (x << 3) + c - '0'; c = getchar();}
	return x * f;
}

ll n, m, k, ans = LONG_LONG_MAX, cnt;
ll fa[MAXN], c[15], a[15][MAXN];
bool choose[15];
struct node {
	ll s, e, d;
}ed[MAXN], edge[MAXN];

ll find(ll x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

bool operator< (const node &x, const node &y) {
	return x.d < y.d;
}

void dfs(int now) {
	if(now > k) {
		cnt = m;
		for (int i = 1; i <= m; i++)
			ed[i] = edge[i];
//		for (int i = 1; i <= n; i++)
//			std::cout << ed[i].s << ' ' << ed[i].e << ' ' << ed[i].d << '\n';
//			std::cout << '\n';
		ll num = n, cur = 0;
		for (int i = 1; i <= k; i++) {
			if(choose[i]) {
				cur += c[i];
				++num;
				for (int j = 1; j <= n; j++)
					ed[++cnt].s = num, ed[cnt].e = j, ed[cnt].d = a[i][j];
			}
		}
		std::sort(ed + 1, ed + cnt + 1);
		for (int i = 1; i <= num; i++)
			fa[i] = i;
		ll qwq = 0;
		for (int i = 1; i <= cnt; i++) {
			ll s = ed[i].s, e = ed[i].e, d = ed[i].d;
			if(find(s) != find(e)) {
				fa[find(e)] = find(s);
				cur += d;
				++qwq; 
			}
			if(qwq == num - 1)
				break;
		}
		ans = std::min(ans, cur);
		return ;
	}
	dfs(now + 1);
	choose[now] = 1;
	dfs(now + 1);
	choose[now] = 0;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout); 
	n = read(), m = read(), k = read();
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	if(k == 0) {
		for (int i = 1; i <= n; i++)
			fa[i] = i;
		for (int i = 1; i <= m; i++)
			ed[i].s = read(), ed[i].e = read(), ed[i].d = read();
		std::sort(ed + 1, ed + m + 1);
		ll res = 0;
		for (int i = 1; i <= m; i++) {
			ll s = ed[i].s, e = ed[i].e, d = ed[i].d;
			if(find(s) != find(e)) {
				fa[find(e)] = find(s);
				res += d;
			}
		}
		std::cout << res << '\n';
		return 0;
	}
	ll qwq = 0;
	for (int i = 1; i <= m; i++)
		ed[i].s = read(), ed[i].e = read(), ed[i].d = read();
	for (int i = 1; i <= k; i++) {
		c[i] = read();
		for (int j = 1; j <= n; j++)
			a[i][j] = read();
	}
	std::sort(ed + 1, ed + m + 1);
	ll res = 0;
	for (int i = 1; i <= m; i++) {
		ll s = ed[i].s, e = ed[i].e, d = ed[i].d;
		if(find(s) != find(e)) {
			++qwq;
			edge[qwq] = ed[i];
			fa[find(e)] = find(s);
			res += d;
		}
		if(qwq == n - 1)
			break;
	}
	m = qwq;
	dfs(1);
	std::cout << ans << '\n';
	return 0;
}

