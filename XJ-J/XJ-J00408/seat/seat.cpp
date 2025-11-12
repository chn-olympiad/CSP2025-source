#include <bits/stdc++.h>

using namespace std;

int n, m, a[111], ans[11][11];

inline bool cmp(const int &x, const int &y) {
	return x > y;
}

int main() {
    freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		scanf("%d", &a[i]);
	int p = a[1];
	sort(a + 1, a + (n * m) + 1, cmp);
	int top = 1;
	for (int i = 1; i <= m; i++) {
		if (i & 1)
			for (int j = 1; j <= n; j++)
				ans[j][i] = a[top++];
		else
			for (int j = n; j; j--)
				ans[j][i] = a[top++];
	}
	int c = 0, r = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (ans[i][j] == p) {
				c = i, r = j;
				break;
			}
	printf("%d %d\n", r, c);
	return 0;
}
