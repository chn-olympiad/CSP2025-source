#include <bits/stdc++.h>
using namespace std;
int n, m, a[105];
int optsr, seatr, seatlie, seathang;

bool cmp(int xx, int yy) {
	return xx > yy;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	int mul = n * m;
	for (int i = 1; i <= mul; i++) {
		scanf("%d", &a[i]);
	}
	optsr = a[1];
	sort(a + 1, a + mul + 1, cmp);
	for (int i = 1; i <= mul; i++) {
		if (a[i] == optsr) {
			seatr = i;
			break;
		}
	}
	if (seatr % n == 0)
		seatlie = seatr / n;
	else
		seatlie = seatr / n + 1;
	if (seatlie % 2 == 1)
		seathang = seatr - (seatr / n) * n;
	else
		seathang = n - (seatr - (seatr / n - 1) * n) + 1;
	if (seathang == 0)
		seathang = n;
	printf("%d %d", seatlie, seathang);
	return 0;
}
