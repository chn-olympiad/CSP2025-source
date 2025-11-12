#include <bits/stdc++.h>
using namespace std;
int a[200];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, k, ans = 1, l, h;
	scanf("%d%d", &n, &m);
	k = n * m;
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
		if (a[i] > a[1])
			ans++;
	}
	if (ans % n == 0)
		l = ans / n;
	else
		l = ans / n + 1;
	printf("%d ", l);
	if (l % 2 == 0) {
		if (ans % n == 0)
			h = 1;
		else
			h = n - ans % n + 1;
	} else {
		if (ans % n == 0)
			h = n;
		else
			h = ans % n;
	}
	printf("%d", h);
	return 0;
}