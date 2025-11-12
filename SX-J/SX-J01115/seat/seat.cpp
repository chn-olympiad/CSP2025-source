

#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, i, j, tmp, a, x = 1, y = 1, o = 1;
	cin >> n >> m;
	int num[n * m];
	for (i = 0; i < n * m; i++) {
		cin >> num[i];
	}
	a = num[0];
	for (i = 0; i < n * m; i++) {
		for (j = i; j < n * m; j++) {
			if (num[i] < num[j]) {
				tmp = num[i];
				num[i] = num[j];
				num[j] = tmp;
			}
		}
	}

	for (i = 0; i < n * m; i++) {
		if (num[i] == a) {
			cout << x << " " << y;
			break;
		}
		y += o;
		if (y > n) {
			x++;
			y--;
			o = -1;

		} else if (y <= 0) {
			x++;
			y = 1;
			o = 1;
		}

	}


	return 0;
}




