#include <bits/stdc++.h>
using namespace std;
int n, m;

struct node {
	int score, id;
} a[200];

bool cmp(node u, node v) {
	return u.score > v.score;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i].score);
		a[i].id = i;
	}
	sort(a + 1, a + n *m + 1, cmp);
	int cnt = 0;
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 0) {
			for (int j = n; j >= 1; j--) {
				if (a[++cnt].id == 1) {
					printf("%d %d", i, j);
					return 0;
				}
			}
		} else {
			for (int j = 1; j <= n; j++) {
				if (a[++cnt].id == 1) {
					printf("%d %d", i, j);
					return 0;
				}
			}
		}
	}
	return 0;
}
