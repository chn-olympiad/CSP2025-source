#include <bits/stdc++.h>
using namespace std;
int a[1008678];
int b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, m = 0, j = 0, k = 0;

//394TYWZ
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < sizeof(s); i++) {
		if (s[i] == '0') {
			b++;
		}
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
			m++;
		}
		if (s[i] == '8') {
			j++;
		}
		if (s[i] == '9') {
			k++;
		}
	}
//	cout << b << c << d << e << f << g << h << m << j << k;
	for (int i = 0; i < k; i++) {
		cout << "9";
	}
	for (int i = 0; i < j; i++) {
		cout << "8";
	}
	for (int i = 0; i < m; i++) {
		cout << "7";
	}
	for (int i = 0; i < h; i++) {
		cout << "6";
	}
	for (int i = 0; i < g; i++) {
		cout << "5";
	}
	for (int i = 0; i < f; i++) {
		cout << "4";
	}
	for (int i = 0; i < e; i++) {
		cout << "3";
	}
	for (int i = 0; i < d; i++) {
		cout << "2";
	}
	for (int i = 0; i < c; i++) {
		cout << "1";
	}
	for (int i = 0; i < b; i++) {
		cout << "0";
	}
	return 0;
}