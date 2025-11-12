#include <bits/stdc++.h>
using namespace std;

bool com(int a, int b) {
	return a > b;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	int a[110];
	for (int i = 0; i < n * m; i++) {
		scanf("%d", &a[i]);
	}
	int a1 = a[0];
	int c = 0;
	int r = 0;
	int b[12][12];
	sort(a, a + n *m, com);
	for (int i = 0; i < n; i++) {
		for (int j = 0 + i * n; j < m + i * n; j++) {
			b[i][j] = a[j];
			if (b[i][j] == a1) {
				r = i;
				c = j - i * n;
			}
		}
	}
	c++;
	r++;
	printf("%d %d", r, c);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
