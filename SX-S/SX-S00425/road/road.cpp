#include <bits/stdc++.h>
using namespace std;
long long fa[1000005], n, m, k, ans;

struct node {
	long long to, nex, w;
} e[2000005];

bool cmp(node a, node b) {
	return a.w < b.w;
}

long long find(int x) {
	return (fa[x] = ((fa[x] == x) ? x : find(fa[x])));
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		scanf("%lld %lld %lld", &e[i].nex, &e[i].to, &e[i].w);
	}
//	for (int i = 0; i < k; i++) {
//		long long l, len;
//		scanf("%lld", &l);
//		cin >> l;
//		for (int j = 1; j <= n; j++) {
//			scanf("%lld", &len);
//			long long x = m + (i *k) + j;
//			e[x].to = i;
//			e[x].nex = j;
//			e[x].w = len + l;
//		}
//	}
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		long long x = e[i].nex, y = e[i].to;
		if (find(x) != find(y))
			fa[find(x)] = fa[find(y)], ans += e[i].w;
	}
	cout << ans;
	return 0;
}/*
4 4 0
1 4 4
2 3 8
4 2 2
4 3 1
*/