#include <bits/stdc++.h>
using namespace std;
string  s;
int len = 0, i = 0, j = 0, m = 0, n = 0, h = 0, x = 0, l, sum = 0, y;
int a[10000];

int main() {
	freopen("number.in", "r", stdin);
	freopen("numbre.out", "w", stdout);
	cin >> s;
	len = s.size();
	for (i = 0; i < len; i++) {
		if ('1' <= s[i] && s[i] <= '9') {
			if (s[i] == '1') {
				a[j] = 1;
			}
			if (s[i] == '2') {
				a[j] = 2;
			}
			if (s[i] == '3') {
				a[j] = 3;
			}
			if (s[i] == '4') {
				a[j] = 4;
			}
			if (s[i] == '5') {
				a[j] = 5;
			}
			if (s[i] == '6') {
				a[j] = 6;
			}
			if (s[i] == '7') {
				a[j] = 7;
			}
			if (s[i] == '8') {
				a[j] = 8;
			}
			if (s[i] == '9') {
				a[j] = 9;
			}
			j++;
		}

	}

	for (m = 0; m < j; m++) {
		for (n = 0; n < j; n++) {
			if (a[m] > a[n]) {
				h = a[m];
				a[m] = a[n];
				a[n] = h;
			}
		}
	}

	for (x = 0; x < j; x++) {
		for (y = j; y > 1; y--) {
			sum = sum + a[x] * 10;
		}
	}
	cout << sum << endl;
	return 0;
}
