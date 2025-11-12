#include <bits/stdc++.h>
using namespace std;

int n, m, a[210], ans;
bool f[20][20];

void A(int i, int j, int k) {
	if (a[k] == ans) {
		printf("%d %d\n", j, i);
		return;
	}
	f[i][j] = true;
	if (i + 1 <= n && f[i + 1][j] == false)
		A(i + 1, j, k + 1);
	else if (i - 1 > 0 && f[i - 1][j] == false)
		A(i - 1, j, k + 1);
	else
		A(i, j + 1, k + 1);
}

bool B(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n * m; i++) {
		scanf("%d", &a[i]);
	}
	ans = a[0];
	sort(a, a + n *m, B);
	A(1, 1, 0);
	return 0;
}
