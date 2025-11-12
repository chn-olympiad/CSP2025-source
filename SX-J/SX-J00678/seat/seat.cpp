#include <bits/stdc++.h>
using namespace std;
int a[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, sum = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 2; i <= n * m; i++) {
		if (a[i] > a[1]) {
			sum++;
		}
	}
	int x = sum / n + 1;
	int y = sum % n;
	if (x % 2 == 0) {
		printf("%d %d", x, n - y);
	} else {
		printf("%d %d", x, y + 1);
	}
	return 0;
}