#include <bits/stdc++.h>
using namespace std;
int fs[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, djm, xm, k = 1;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> fs[i];
	}
	xm = fs[1];
	sort(fs + 1, fs + n *m + 1);
	for (int i = n * m; i >= 1 ; i--) {
		if (fs[i] == xm)
			djm = k;
		k++;
	}
	k = 1;
	while (djm >= n) {
		djm %= n;
		k++;
	}
	k += 1;
	djm = n;
	printf("%d %d", k, djm);
	return 0;
}
