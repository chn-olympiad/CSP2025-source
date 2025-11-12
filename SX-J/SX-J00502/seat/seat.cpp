#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int a, o, n, c, f;
	cin >> a >> o;
	n = a * o;
	int b[1000];
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	f = b[1];
	for (int x = 0; x < n - 1; x++) {
		for (int i = 0; i < n ; i++) {
			for (int j = 0; j < n; j++) {

				if (b[i] < b[i + 1]) {
					if (b[i + 1] == 100 && b[i] != 100) {
						c = b[i];
						b[i] = b[i + 1];
						b[i + 1] = c;
					}
					c = b[i];
					b[i] = b[i + 1];
					b[i + 1] = c;
				}
			}
		}
	}
	a = 100 % a;
	o = 100 % o;
	cout << a << o;
	return 0;
}