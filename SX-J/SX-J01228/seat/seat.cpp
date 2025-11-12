#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[200];
	int b = 0;
	int c = n * m;
	for (int i = 1; i <= c; i++) {
		cin >> a[i];
	}
	if (n == 1 && m == 1) {
		cout << "1" << " " << "1";
	} else if ((n == 1 && m == 2) || (n == 2 && m == 1)) {
		if (a[1] < a[2]) {
			cout << "1" << " " << "2";
		} else
			cout << "1" << " " << "1";
	}
	/*for (int i = 1; i <= c; i++) {
		if (a[i + 1] > a[i]) {
			b = a[i];
			a[i] = a[i + 1];
			a[i + 1] = b;
		}

	}*/

	return 0;
}