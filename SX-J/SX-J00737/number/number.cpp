#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+1;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int a = 1, b = 1, c = 1, d = 1, e = 1, f = 1, g = 1, h = 1, x = 1, y = 1;
	string s;
	int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0,
	    a7 = 0,
	    a8 = 0, a9 = 0,
	    a0 = 0;
	cin >> s;
	for (int i = 0; i <= s.size() - 1; i++) {
		if (s[i] == '1' ) {
			a = 1;
			a1++;
		}
		if (s[i] == '2' ) {
			b = 2;
			a2++;
		}
		if (s[i] == '3' ) {
			c = 3;
			a3++;
		}
		if (s[i] == '4' ) {
			d = 4;
			a4++;
		}
		if (s[i] == '5' ) {
			e = 5;
			a5++;
		}
		if (s[i] == '6' ) {
			f = 6;
			a6++;
		}
		if (s[i] == '7' ) {
			g = 7;
			a7++;
		}
		if (s[i] == '8' ) {
			h = 8;
			a8++;
		}
		if (s[i] == '9' ) {
			x = 9;
			a9++;
		}
		if (s[i] == '0' ) {
			y = 0;
			a0++;
		}
	}
//	cout << a << b << c << d << e << f << g << h << x << y << endl;
//	cout << a1 << " " << a2 << " " << a3 << " " << a4 << " " << a5 << " " << a6 << " " << a7 << " " << a8 << " " << a9 <<
//	     " " << a0 << endl;
	for (int i = 1; i <= a9; i++) {
		cout << x;
	}
	for (int i = 1; i <= a8; i++) {
		cout << h;
	}
	for (int i = 1; i <= a7; i++) {
		cout << g;
	}
	for (int i = 1; i <= a6; i++) {
		cout << f;
	}
	for (int i = 1; i <= a5; i++) {
		cout << e;
	}
	for (int i = 1; i <= a4; i++) {
		cout << d;
	}
	for (int i = 1; i <= a3; i++) {
		cout << c;
	}
	for (int i = 1; i <= a2; i++) {
		cout << b;
	}
	for (int i = 1; i <= a1; i++) {
		cout << a;
	}
	for (int i = 1; i <= a0; i++) {
		cout << y;
	}
	return 0;
}