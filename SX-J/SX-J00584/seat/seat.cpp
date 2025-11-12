#include <bits/stdc++.h>
using namespace std;
int f[10000];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int a, b, c = 0;
	int o = 1, q = 1, w = 1;
	cin >> a >> b;
	for (int i = 1; i <= a * b; i++) {
		cin >> f[i];
		if (i >= 2) {
			if (f[i] > f[1])
				c++;
		}
	}
	for (int i = 1; i <= c; i++) {
		if ((q == 1 && o % 2 == 0) || (q == a && o % 2 == 1)) {
			o++;
			w++;
			break;
		}
		if (w % 2 == 0)
			q = q - 1;
		//if (w % 2 == 1)
		else
			q++;
	}
	cout << o << " " << q;
	return 0;
}
