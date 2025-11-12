#include <bits/stdc++.h>
using namespace std;
int n, m, a[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int num = 0, seat = 1;
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
		if (i == 1)
			num = a[i];
		else {
			if (a[i] > num)
				seat++;
		}
	}
	int x = (seat + n - 1) / n, y = 0;
	y = seat % n;
	if (y == 0)
		y = n;
	if (x % 2 == 0)
		y = n - y + 1;
	printf("%d %d\n", x, y);
	return 0;
}
