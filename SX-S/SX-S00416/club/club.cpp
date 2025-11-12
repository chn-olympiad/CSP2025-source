#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int a[10001], b[10001], c[10001];
int maxn;
int aa, bb, cc;
long long maxx;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	for (int x = 1; x <= t; x++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d %d %d", &a[i], &b[i], &c[i]);
			maxn = max(max(a[i], b[i]), c[i]);
			maxx += maxn;

		}
		printf("%lld\n", maxx);
		maxx = 0;

	}


	return 0;
}
