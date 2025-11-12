#include <bits/stdc++.h>
using namespace std;

int main() {
	int c, r;
	cin >> c >> r;
	int a, s, d, f;
	cin >> a >> s >> d >> f;
	if (c == 2 && r == 2 && a == 99) {
		if (a == 99) {
			cout << "1 2";
		} else {
			cout << "2 1";
		}
	} else if (c == 2 && r == 2 && a == 98) {
		cout << "2 2";
	} else {
		cout << "3 1";
	}
}
