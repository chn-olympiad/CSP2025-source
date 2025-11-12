#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> a;
int o;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int v = size(s);
	int w, t = 0;
	for (int q = 0; q < v; q++) {
		w = s[q];
		if (w - '0' == 0 || w - '0' == 1 || w - '0' == 2 || w - '0' == 3 || w - '0' == 4 || w - '0' == 5) {
			if ( w - '0' == 6 || w - '0' == 7 || w - '0' == 8 || w - '0' == 9) {
				a[q] = w - '0';
				t = t + 1;
			}
		}
	}
	int y = 10, r = 0;
	o = t;
	for (int q = 0; q < o; q++) {
		if (a[q] < a[q + 1]) {
			swap(a[q], a[q + 1]);
		}
	}
	for (int d = 0; d < o; d++) {
		y = y * 10;
	}
	for (int q = 0; q < t; q++) {
		r = r + a[q] * y;
		y = y / 10;
	}
	cout << r;
	return 0;
}
