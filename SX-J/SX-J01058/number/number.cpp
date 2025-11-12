#include <bits/stdc++.h>
using namespace std;
string a;
int b[1000000];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	int n, js = 0, bs = 0;
	for (int i = 0; i <= 1000000; i++) {
		n = a[i];
		if (n > 57) {
			bs -= 1;
			js -= 1;
		} else {
			b[bs] = n - 48;
		}

		bs++;
		if (n == 0 ) {
			break;
		}
		js++;

	}
	int ts;
	for (int i = 0; i < js; i++) {
		for (int j = 0; j < js; j++) {
			if (b[i] > b[j]) {
				ts = b[i];
				b[i] = b[j];
				b[j] = ts;

			}
		}
	}
	for (int i = 0; i < js; i++) {
		cout << b[i];
	}
	return 0;
}