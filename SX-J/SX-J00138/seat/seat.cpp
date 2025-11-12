#include <bits/stdc++.h>
using namespace std;
int n, m, c, k = 0, ansx = 1, ansy = 1;
int a[109];

bool px(int b, int d) {
	return b > d;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {
		cin >> a[i];
	}
	c = a[0];
	sort(a, a + n *m, px);
	while (a[k] != c ) {
		if (ansy % 2 == 0)
			ansx--;
		else
			ansx++;
		k++;
		if (ansx > n || ansx < 1) {
			ansy++;
			if (ansy % 2 == 0)
				ansx = n;
			else
				ansx = 1;
		}
	}
	if (ansx == 0)
		ansx = 1;
	if (ansy == 0)
		ansy = 1;
	cout << ansy << " " << ansx;
	return 0;
}