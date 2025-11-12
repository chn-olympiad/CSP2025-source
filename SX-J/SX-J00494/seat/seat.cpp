#include <iostream>
using namespace std;
int b[10000010];

int main() {
	int n, m, c, r, a, chu, yu; //c lie r hang
	cin >> n >> m;
	a = n * m;
	for (int k = 1; k <= a; k++) {
		cin >> b[k];
		if (b[k] > b[1]) {
			b[k] = b[1];
			chu = k / n;
			yu = k % n;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {


				if (chu == 1 && yu == 0) {
					r = n;
					c = 1;
				}
				if (yu < n && yu != 0 && chu % 2 == 1) {
					r = n + 1 - yu; //hang
					c = chu + 1;//lie
				}
				if (yu < n && yu != 0 && chu % 2 == 0) {
					r = yu; //hang
					c = chu + 1;//lie
				}
				if (yu == 0 && chu != 1 && chu % 2 == 0) {
					r = 1;
					c = chu;
				}
				if (yu == 0 && chu != 1 && chu % 2 == 1) {
					r = n;
					c = chu;
				}


			}
		}

	}

	cout << c << " " << r;
	return 0;
}
