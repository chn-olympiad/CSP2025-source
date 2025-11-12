#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n, m, k;

struct node {
	int to, nxt;
	long long w;
} e[1000010];

int cnt = 0, head[10010] = {0};

long long c[12], a[12][10005] = {0};

void addE(int u, int v, long long w) {
	cnt++;
	e[cnt].to = v;
	e[cnt].nxt = head[u];
	e[cnt].w = w;
	head[u] = cnt;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	int u, v;
	long long w, ans = 0;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%lld", &u, &v, &w);
		addE(u, v, w);
		addE(v, u, w);
		ans += w;
	}
	if (k == 0 && m == n - 1) {
		printf("%lld", ans);
		return 0;
	}

	for (int i = 1; i <= k; i++) {
		int flag = 1;
		scanf("%lld", &c[i]);
		if (c[i] != 0)
			flag = 0;
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j]);
			if (a[i][j] != 0)
				flag = 0;
		}
		if (flag) {
			printf("0");
			return 0;
		}
	}

	return 0;
}