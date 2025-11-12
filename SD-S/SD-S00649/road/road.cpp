#include<bits/stdc++.h>
using namespace std;

int n, m, nn, k, rt[10111], cnt;
long long ans;

struct edge {
	int x, y, val;
} e[2000011];

int find (int t) {
	if (rt[t] == t)
		return t;
	rt[t] = find(rt[t]);
	return rt[t];
}

bool cmp (edge u, edge v) {
	return u.val < v.val;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
		scanf ("%d%d%d", &e[i].x, &e[i].y, &e[i].val);
	for (int i = 1; i <= n; i++)
		rt[i] = i;
	for (int i = 1; i <= k; i++) {
		int c, a;
		scanf ("%d", &c);
		for (int j = 1; j <= n; j++) {
			scanf ("%d", &a);
			m++;
			e[m].x = n + i;
			e[m].y = j;
			e[m].val = a;
		}
		rt[n + i] = n + i;
	}
	n += k;
	sort (e + 1, e + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int rx = find(e[i].x), ry = find(e[i].y);
		if (rx != ry) {
			rt[rx] = ry;
			ans += e[i].val;
			cnt++;
			if (cnt == n - 1)
				break;
		}
	}
	printf ("%lld\n", ans);
	return 0;
}

