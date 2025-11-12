#include <bits/stdc++.h>
using namespace std;
int a[300];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	int tot = n * m;
	for (int i = 1; i <= tot; i++) {
		scanf("%d", &a[i]);
	}
	int goal = a[1];
	sort(a + 1, a + tot + 1, cmp);
	bool f = 0;
	int t = 1;
	for (int j = 1; j <= m; j++) {
		if (f == 0) {
			for (int i = 1; i <= n; i++) {
				if (a[t] == goal) {
					printf("%d %d", j, i);
					return 0;
				}
				t++;
			}
			f = 1;
			continue;
		}
		if (f == 1) {
			for (int i = n; i >= 1; i--) {
				if (a[t] == goal) {
					printf("%d %d", j, i);
					return 0;
				}
				t++;
			}
			f = 0;
			continue;
		}
	}
	return 0;
}
