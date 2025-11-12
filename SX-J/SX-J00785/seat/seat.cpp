#include <bits/stdc++.h>
using namespace std;
int a[111], s[111][111];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m * n; i++) {
		scanf("%d", &a[i]);
	}
	int x = a[1];
	sort(a + 1, a + (m *n) + 1, cmp);
	int k = 1;
	for (int i = 1; i <= m; i++) {
		if (i % 2 != 0) {
			for (int j = 1; j <= n; j++) {
				s[j][i] = a[k];
				k++;
			}
		} else {
			for (int j = n; j >= 1; j--) {
				s[j][i] = a[k];
				k++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[j][i] == x)
				printf("%d %d", i, j);
		}
	}
	return 0;
}
