#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n , m , k , fa[10011];
ll c[11] , a[11][10011];
struct Edge {
	int u , v;
	ll w;
}p[1000011];
vector <int> v;
bool b[10011];

inline bool cmp(Edge x , Edge y) {
	return x.w < y.w;
}

inline int findset(int u) {
	if (fa[u] == u) return u;
	return fa[u] = findset(fa[u]);
}

int main () {
	freopen("road.in" , "r" , stdin);
	freopen("road.out" , "w" , stdout);
	scanf ("%d%d%d" , &n , &m , &k);
	for (int i = 1;i <= n;i++) fa[i] = i;
	for (int i = 1;i <= m;i++) scanf ("%d%d%lld" , &p[i].u , &p[i].v , &p[i].w);
	bool ok = 0;
	for (int i = 1;i <= k;i++) {
		scanf ("%lld" , &c[i]);
		if (c[i] != 0) ok |= 1;
		for (int j = 1;j <= n;j++) scanf ("%lld" , &a[i][j]) , ok |= (a[i][j] != 0);
	}
	if (!ok) {
		printf ("0");
		return 0;
	}
	sort (p + 1 , p + m + 1 , cmp);
	ll ans = 0;
	for (int i = 1;i <= m;i++) {
		int fx = findset(p[i].u) , fy = findset(p[i].v);
		if (fx == fy) continue;
		fa[fy] = fx , ans += p[i].w , v.push_back(i);
	}
	for (int i = 0;i < (1 << k);i++) {
		for (int j = 1;j <= n;j++) b[j] = 1;
		ll sum = ans;
		for (int j = 1;j <= k;j++) if ((i >> (j - 1)) & 1) sum += c[j];
		for (auto j : v) {
			ll sm = LLONG_MAX;
			for (int l = 1;l <= k;l++) if ((i >> (l - 1)) & 1) sm = min(sm , a[l][p[j].u] * b[p[j].u] + a[l][p[j].v] * b[p[j].v]);
			if (sm <= p[j].w) {
				b[p[j].u] = 0;
				b[p[j].v] = 0;
			}
			if (sm == LLONG_MAX) sm = p[j].w;
			sum = sum - p[j].w + sm;
		}
		ans = min(ans , sum);
	}
	printf ("%lld\n" , ans);
	return 0;
}