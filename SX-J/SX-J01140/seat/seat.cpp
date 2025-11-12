#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000], k, o, l, h;

int cmp(const int &x, const int &y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n * m; i++) {
		scanf("%d", &a[i]);
	}
	k = a[1];
	sort(a + 1, a + 1 + n *m, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i] == k) {
			o = i;
			break;
		}
	}
	l = o / n + 1;
	if (o % n == 0)
		l--;

	h = o % n;
	if (h == 0)
		h = n;
	if (l % 2 == 0) {
		cout << l << " " << n - h + 1;
	} else {

		cout << l << " " << h;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
