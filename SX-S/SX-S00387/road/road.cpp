#include <bits/stdc++.h>
using namespace std;
const int N = 2e4, M = 2e5+5;
int tot, h[N], fa[N];
long long ans;
int n, m, k;
typedef pair<int, int> pii;
int dist[N];

struct edge {
	int sta, e, ne, val;
} ed[M];

void add(int x, int y, int z) {
	ed[tot].sta = x, ed[tot].e = y, ed[tot].val = z, ed[tot].ne = h[x], h[x] = tot++;
}

int find(int x) {
	if (x != fa[x])
		fa[x] = find(fa[x]);
	return fa[x];
}

bool cmp(edge x, edge y) {
	return x.val < y.val;
}

void dj() {
	for (int i = 1; i <= m; i++) {
		int v = ed[i].val, s = ed[i].sta, end = ed[i].e;
		if (fa[s] != fa[end]) {
			ans += v;
			fa[s] = find(fa[end]);
		}
	}
}
typedef pair<int, int> pii;

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	if (k == 0) {
		for (int i = 1; i <= m; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			add(a, b, c), add(b, a, c);
		}
		for (int i = 1; i <= n; i++)
			fa[i] = i;
		sort(ed, ed + m, cmp);
		dj();
		cout << ans << endl;
	} else {
		for (int i = 1; i <= m; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			add(a, b, c), add(b, a, c);
		}
		for (int i = 1; i <= k; i++) {
			int a;
			cin >> a;
			for (int j = 1; j <= n; j++) {
				int p;
				scanf("%d", &p);
				add(a, j, p), add(j, a, p);
			}
		}
		dj();
		cout << ans << endl;
	}
}