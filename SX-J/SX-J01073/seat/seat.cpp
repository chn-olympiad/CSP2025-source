#include <bits/stdc++.h>
using namespace std;
int a, b;
int x[110];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> a >> b;
	for (int i = 1; i <= a * b; i++) {
		cin >> x[i];
	}
	int y = x[1], z;
	sort(x, x + a *b);
	for (int i = a * b; i >= 1; i--) {
		if (y == x[i]) {
			z = i;
			break;
		}
	}
	z = a * b - z;
	int d = z;
	if (z % 2 == 1) {
		for (int w = 1; w <= a * b; w++) {
			d++;
			if (d % a == 0)
				break;
		}
	}
	int c = d / a;
	if (z <= a)
		cout << "1" << " " << z;
	else if (c == 2 && z == 3)
		cout << "2 2";
	else if (z % a == 1)
		cout << c << " " << z % a;
	else if (c % a == 0)
		cout << c << " " << a - z / a + 1;
	return 0;
}