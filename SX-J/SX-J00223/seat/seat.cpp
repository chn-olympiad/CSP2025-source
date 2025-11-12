#include <bits/stdc++.h>
using namespace std;
int n, m, need, nh, nl = 1;
int a[1000];
bool p = 0;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
		if (i == 1)
			need = a[i];
	}
	sort(a + 1, a + n *m + 1, cmp);
	for (int i = 1;; i++) {
		if (p == 0)
			nh++;
		else
			nh--;
		if (nh > n) {
			nh--;
			nl++;
			p = 1;
		}
		if (nh < 1) {
			nh++;
			nl++;
			p = 0;
		}
		if (a[i] == need) {
			cout << nl << ' ' << nh;
			break;
		}
	}
	return 0;
}
