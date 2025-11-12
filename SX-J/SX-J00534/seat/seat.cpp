#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;;
	cin >> n >> m;
	int a[100];
	cin >> a[0];
	int	bj = a[0];
	for (int i = 1; i < n * m; i++) {
		cin >> a[i];

	}
	sort(a, a + n *m);
	int o;
	for (int i = 0; i < n * m; i++) {
		if (a[i] == bj) {
			o = i + 1;
			break;
		}
	}
	o = m * n + 1 - o;
	cout << o << endl;
	int hang, lie;
	if (o % n != 0) {
		lie = o / n + 1;
		hang = o % n;
	} else {
		lie = o / n;
		hang = n;
	}
	if (lie % 2 == 0) {
		hang = n + 1 - hang;
	}
	cout << lie << " " << hang;

	return 0;

}
