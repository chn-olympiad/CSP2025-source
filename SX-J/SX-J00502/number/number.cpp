#include <bits/stdc++.h>
using namespace std;
char a[1000005];
string f, d;
char b[1000005];
long long n, v;
char c;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	f = a;
	n = f.size();
	if (n == 1) {
		cout << a;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if ( a[i] == '1' || a[i] == '2' || a[i] == '3') {
			b[i] = a[i];
		} else if (a[i] == '4' || a[i] == '5' || a[i] == '6') {
			b[i] = a[i];
		} else if (a[i] == '7' || a[i] == '8' || a[i] == '9' || a[i] == '0') {
			b[i] = a[i];
		} else {
			b[i] = ' ';
		}
	}

	d = b;
	v = d.size();
	for (int x = 0; x < v - 1; x++) {
		for (int i = 0; i < v ; i++) {
			for (int j = 0; j < v; j++) {
				if (b[i] < b[i + 1]) {
					c = b[i];
					b[i] = b[i + 1];
					b[i + 1] = c;
				}
			}
		}
	}
	cout << b;
	return 0;
}
