#include <bits/stdc++.h>
using namespace std;
long long ans;

struct point {
	int u;
	int v;
	int w;
};
point edge[2000010];
int fa[1000100];
int n, m, k;

int cmp(point x, point y) {
	return x.w < y.w;
}

int fin(int x) {
	if (x == fa[x]) {
		return x;
	}
	fa[x] = fin(fa[x]);
	return fa[x];
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int s, t, w, len, c;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n + 50; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
	}
	len = m;
	for (int i = 1; i <= k; i++) {
		scanf("%d", &c);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &w);
			len++;
			edge[len].u = i + n;
			edge[len].v = j;
			edge[len].w = w;
		}
	}
	sort(edge + 1, edge + len + 1, cmp);
	int fx, fy, cnt = 0;
	for (int i = 1; i <= len; i++) {
		fx = fin(edge[i].u);
		fy = fin(edge[i].v);
		//cout << fx << " " << fy << " " << edge[i].w << endl;
		if (fx != fy) {
			ans += edge[i].w;
			fa[fx] = fy;
			cnt++;
			if (cnt == k + n - 1) {
				break;
			}
		}
	}
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}