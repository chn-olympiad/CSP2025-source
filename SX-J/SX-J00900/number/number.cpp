#include <bits/stdc++.h>
using namespace std;
int b, c, d, e, f, g, h, i, j, k;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 1; i <= s.size(); i++) {
		if (s[i] == '1') {
			c++;
		}
		if (s[i] == '2') {
			d++;
		}
		if (s[i] == '3') {
			e++;
		}
		if (s[i] == '4') {
			f++;
		}
		if (s[i] == '5') {
			g++;
		}
		if (s[i] == '6') {
			h++;
		}
		if (s[i] == '7') {
			i++;
		}
		if (s[i] == '8') {
			j++;
		}
		if (s[i] == '9') {
			k++;
		}
		if (s[i] == '0') {
			b++;
		}
	}
	for (int i = 1; i <= k; i++) {
		cout << 9;
	}
	for (int i = 1; i <= j; i++) {
		cout << 8;
	}
	for (int i = 1; i <= i; i++) {
		cout << 7;
	}
	for (int i = 1; i <= h; i++) {
		cout << 6;
	}
	for (int i = 1; i <= g; i++) {
		cout << 5;
	}
	for (int i = 1; i <= f; i++) {
		cout << 4;
	}
	for (int i = 1; i <= e; i++) {
		cout << 3;
	}
	for (int i = 1; i <= d; i++) {
		cout << 2;
	}
	for (int i = 1; i <= c; i++) {
		cout << 1;
	}
	for (int i = 1; i <= b; i++) {
		cout << 0;
	}
	return 0;
}
