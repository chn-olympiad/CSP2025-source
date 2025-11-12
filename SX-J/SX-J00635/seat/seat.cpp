#include <bits/stdc++.h>
using namespace std;
int a[10005];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	//freopen("seat.in", "r", stdin)
	//freopen("seat.out", "w", stdout)
	int  n, m, b, c;
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int q = a[1];


	sort(a + 1, a + 1 + n *m, cmp);

	for (int i = 1; i <= n * m; i++) {

		if (q == a[i]) {
			q = i;
			break;
		}
	}
	int lie, hang;
	if (q <= n) {
		cout << "1" << " " << q;
		return 0;
	}
	if (q % n != 0) {
		if ((q / n + 1) % 2 == 0) {
			lie = q / n + 1;
			hang = n - q % n + 1;
		} else {
			lie = q / n + 1;
			hang = q % n ;
		}

	}
	cout << lie << " " << hang;

	return 0;
}
