#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3+10;
int n, m, x, y, z;

struct st {
	ll g, zs;
} a[N];

bool cmp(st l, st r) {
	return l.g > r.g;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	cin >> n >> m >> a[1].g;
	a[1].zs = 1;

	for (int i = 2; i <= n * m; i++)
		cin >> a[i].g;

	sort(a + 1, a + n *m + 1, cmp);

	for (int i = 1; i <= n * m; i++) {
		if (a[i].zs != 0) {
			z = i;
			break;
		}
	}

	if (z % n == 0) {
		x = z / n;
		if (x % 2 == 1)
			y = n;
		else
			y = 1;

	} else {
		x = (z / n) + 1;
		if (x % 2 == 1)
			y = z % n;
		else
			y = n - z % n + 1;
	}

	cout << x << " " << y;

	return 0;

}

































