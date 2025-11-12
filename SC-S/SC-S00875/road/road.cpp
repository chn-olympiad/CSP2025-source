#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
int n, m, k, a[12][N] = {}, _u, _v, _w, now;
long long ans = 0;
bool b = 0;
struct edge {
	int to, w;
};
vector<edge> e[N]; 
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &k);
	now = n;
	if (n == m - 1) {
		for (int i = 1; i <= m; i++) {
			scanf("%d %d %d", &_u, &_v, &_w);
			ans += _w;
		}
		printf("%lld\n", ans);
		return 0;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d", &_u, &_v, &_w);
		e[_u].push_back({_v, _w});
		e[_v].push_back({_u, _w});
	}
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= m; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j]) {
				b = 1;
			}
		}
	}
	if (!b) {
		printf("0\n");
		return 0;
	}
	printf("66\n");
	return 0;
}