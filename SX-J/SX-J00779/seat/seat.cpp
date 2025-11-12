#include <bits/stdc++.h>
using namespace std;
int a[105];
int n, m, c;

bool cmp (int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin );
	freopen("seat.out", "w", stdout );

	cin >> n >> m ;
	for (int i = 1; i <= n * m; ++i) {
		cin >> a[i];
	}
	int r = a[1];

	sort( a + 1, a + m *n, cmp);

	int ans = 1;
	while (a[ans] != r)
		ans++;
//	printf("%d\n", ans);
	if (ans % n == 0) { //队尾或队首
		int lin = ans / n;
		if (lin % 2 == 1) {
			printf("%d %d", lin, m);
		} else if (lin % 2 == 0) {
			printf("%d 1", lin);
		}

	} else {


		int lin = ans / n + 1;
		if (lin % 2 == 1) {
			printf("%d %d", lin, ans % n);
		} else if (lin % 2 == 0) {
//			printf("A");
			printf("%d %d", lin, n - ans % n + 1);

		}
	}
//	c = ans / m;
//	r = ans % m + 1;
//	printf("%d %d", c, r);
	return 0;
}