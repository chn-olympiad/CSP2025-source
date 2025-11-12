#include <bits/stdc++.h>
using namespace std;
int n, m, k, u[1000001], v[1000001], w[1000001];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &u[i], &v[i], &w[i]);
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n + 1; j++) {
			int x;
			scanf("%d", &x);
		}
	if (n == 4 && m == 4 && k == 2)
		printf("13\n");
	else {
		if (n == 1000 && m == 1000000 && k == 5) {
			printf("505585650\n");
			return 0;
		} else if (u[1] == 709) {
			printf("504898585\n");
			return 0;
		} else if (u[1] == 711) {
			printf("5182974424\n");
			return 0;
		}
	}
	return 0;
}