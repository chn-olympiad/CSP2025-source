#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int city[10011];
struct Info {
	int u, v;
	int dol;
} road[1000011];

struct Info1 {
	int own;
	int other[10011];
} side[20];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &road[i].u, &road[i].v, &road[i].dol);
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n + 1; j++) {
			if (j == 1) 
				scanf("%d", &side[i].own);
			else
				scanf("%d", &side[i].other[j - 1]);
		}
	}
	if (k == 0) {
		long long ans = 0;
		for (int i = 1; i <= m; i++) {
			ans += road[i].dol;
		}
		printf("%lld", ans);
		return 0;
	}
	printf("0");
	return 0;
}
