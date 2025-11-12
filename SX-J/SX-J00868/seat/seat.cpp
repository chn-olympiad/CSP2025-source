#include <bits/stdc++.h>
using namespace std;

int n, m, a[102], b[11][11];

bool cmp(const int &x, const int &y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int x = n * m;
	for (int i = 1; i <= x; i++)
		scanf("%d", &a[i]);
	int xiaor = a[1];
	sort(a + 1, a + x + 1, cmp);
	for (int i = 1; i <= x; i++)
		if (a[i] == xiaor) {
			xiaor = i;
			break;
		}
	int xx = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (i % 2 == 1) {
				++xx;
				b[i][j] = xx;
			} else {
				++xx;
				b[i][n - j + 1] = xx;
			}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (b[i][j] == xiaor)
				printf("%d %d\n", i, j);
	return 0;
}