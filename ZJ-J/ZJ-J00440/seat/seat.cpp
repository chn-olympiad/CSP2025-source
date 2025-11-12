#include<bits/stdc++.h>
using namespace std;

int n, m;
struct Node {
	int s, r;
} a[101];

inline bool cmp(Node const &x, Node const &y) {
	return x.s > y.s;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i].s);
		a[i].r = i;
	}
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[(i-1) * n + j].r == 1) {
				if (i & 1)
					printf("%d %d\n", i, j);
				else
					printf("%d %d\n", i, n - j + 1);
				return 0;
			}
		}
	}
	return 0;
}
