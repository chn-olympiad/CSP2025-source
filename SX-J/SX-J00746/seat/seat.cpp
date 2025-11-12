#include <bits/stdc++.h>
using namespace std;

int a[101];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, a1, m1, y1;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++)
		cin >> a[i];
	a1 = a[1];
	sort(a + 1, a + 1 + m *n, cmp);
	for (int i = 1; i <= m * n; i++) {
		if (a[i] == a1) {
			m1 = i;
			break;
		}
	}
	if (m1 % n == 0)
		y1 = n;
	else
		y1 = m1 % n;
	if (m1 % n == 0)
		m1 /= n;
	else
		m1 = m1 / n + 1;
	if (m1 % 2 == 1)
		printf("%d %d", m1, y1);
	else
		printf("%d %d", m1, m - y1 + 1);
	return 0;
}