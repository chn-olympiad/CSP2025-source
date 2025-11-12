#include <bits/stdc++.h>
using namespace std;
int t, n, a[100005][4], maxx;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d%d%d", &a[i][1], &a[i][2], &a[i][3]);
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				if (a[1][i] + a[2][j] > maxx && i != j)
					maxx = a[1][i] + a[2][j];
			}
		}
		printf("%d", maxx);
	}
	return 0;
}