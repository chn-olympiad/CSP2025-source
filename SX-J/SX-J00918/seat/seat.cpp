#include <iostream>
#include <cstdio>
using namespace std;



//#Shang4Shan3Ruo6Shui4
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n, s = 0, h = 0, u;
	cin >> n >> m;
	int b[m * n] = {0};
	for (int i = 0; i < m * n; i++) {
		cin >> b[i];
	}
	u = b[0];
	for (int i = 0; i < m * n; i++) {
		for (int j = i ; j < m * n; j++) {
			if (b[j] > s) {
				s = b[j];
				h = j;
			}

		}
//		cout << h << ' ' << s << endl;
		b[h] = b[i];
		b[i] = s;
		s = 0;
		h = 0;
	}
	for (int i = 0; i < m * n; i++) {
		if (b[i] == u)
			h = i + 1;

	}
	if (h % n != 0) {
		cout << h / n + 1 << ' ' ;
		if (h / n % 2 == 0)
			cout << h % n;
		else if (h / n % 2 != 0)
			cout << n - h % n + 1;
	}

	if (h % n == 0) {
		cout << h / n << ' ' ;
		if (h / n % 2 == 0)
			cout << '1';
		else if (h / n % 2 != 0)
			cout << n;
	}


	return 0;
}
