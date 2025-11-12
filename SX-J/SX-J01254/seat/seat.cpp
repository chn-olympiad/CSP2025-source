#include <bits/stdc++.h>
using namespace std;
int a[10100];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	int zs = n * m, cj;
	for (int i = 1; i <= zs; ++i) {
		scanf("%d", &a[i]);
		if (i == 1)
			cj = a[i];
	}
	int pm = 0;
	sort(a + 1, a + zs + 1, cmp);
	for (int i = 1; i <= zs; ++i) {
		//	printf("%d ", a[i]);
		if (a[i] == cj) {
			pm = i;
		}
	}

	int n1, m1;
	//printf("\n%d\n%d\n", pm, pm / n);
	if (pm <= n)
		n1 = pm / n;
	else
		n1 = pm / n + 1;
	if (n1 % 2 == 0) {
		m1 = n - pm % n + 1;
	} else {
		if (pm % n == 0)
			m1 = n;
		else
			m1 = pm % n;
	}
	printf("%d %d", n1, m1);
	return 0;
}