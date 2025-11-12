#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, scor, a[110], a1, a2;

bool cmp(int x, int y) {
	return x > y;
}
int main(int argv, char **argc) {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	cin >> scor;
	a[1] = scor;

	for (int z = 2; z <= n * m; z++) {
		cin >> a[z];
	}
	sort(a + 1, a + n *m + 1, cmp);

	for (int z = 1; z <= n * m; z++) {
		if (scor == a[z]) {
			a1 = (z + n - 1) / n;
			z %= n;
			if (z == 0)
				z = n;
			if (a1 % 2 == 0) {
				a2 = n + 1 - z;
			} else {
				a2 = z;
			}
			break;
		}
	}
	cout << a1 << ' ' << a2;
	return 0;
}
