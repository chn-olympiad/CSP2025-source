#include <bits/stdc++.h>
using namespace std;
int a[10000], n, m, k, l = 0, y = 0;

int main() {

	freopen("seat.in", 'r', stdin);
	freopen("seat.out", 'w', stdout);
	cin >> n;
	cin >> m;
	k = m * n;


	for (int i = 0; i < k; i++) {

		cin >> a[i];


	}

	for (int i = 0; i < k; i++) {
		if (a[0] < a[i]) {
			l++;
		}

	}
	if ((l + 1) % m == 0) {
		if ((l + 1) / m % 2 == 0) {
			cout << (l + 1) / m << ' ' << "1";
		} else {
			cout << (l + 1) / m << ' ' << m;
		}
	} else {
		if ((int(floor((l + 1) / m)) + 1) % 2 == 0) {
			int c = (int(floor((l + 1) / m)) + 1) * n;

			cout << int(floor((l + 1) / m)) + 1 << ' ' <<  c - l;
		} else {
			int o = (int(floor((l + 1) / m)) + 1) * n;
			cout << int(floor((l + 1) / m)) + 1 << ' ' << n - (o - l) + 1;
		}
	}


	return 0;

}
