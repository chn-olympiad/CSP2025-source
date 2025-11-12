#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int a, b, e, f = 0, g;
	string c;
	cin >> a >> b;
	cin >> c;
	int d[100], h[100];

	for (int i = 0; i <= a - 1; i++) {

		cin >> d[i];
		h[i] = d[i];
	}

	for (int q = 0; q <= a * (a - 1); q++) {

		for (int i = 0; i <= c.size() - 1; i++) {

			for (int j = 0; j <= a; i++) {

				if (c[i] != 0 && d[j] > 0) {
					e++;
				}
			}

			for (int j = 0; j <= a; j++) {

				d[j]--;
			}
		}

		if (e >= b) {
			f++;
		}

		d[q - a] = h[q - 1 - a];
		d[q - a - 1] = d[q - a];
	}

	cout << f;

	fclose(stdin);
	fclose(stdout);
	return 0;
}