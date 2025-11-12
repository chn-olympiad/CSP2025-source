#include <bits/stdc++.h>
using namespace std;
int a[9999900], b;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> b;
	while (b) {
		if (b % 10 == 0)
			a[1]++;
		if (b % 10 == 1)
			a[2]++;
		if (b % 10 == 2)
			a[3]++;
		if (b % 10 == 3)
			a[4]++;
		if (b % 10 == 4)
			a[5]++;
		if (b % 10 == 5)
			a[6]++;
		if (b % 10 == 6)
			a[7]++;
		if (b % 10 == 7)
			a[8]++;
		if (b % 10 == 8)
			a[9]++;
		if (b % 10 == 9)
			a[10]++;
		b = b / 10;
	}
	for (int i = 1; i <= a[10]; i++) {
		cout << 9;
	}
	for (int i = 1; i <= a[9]; i++) {
		cout << 8;
	}
	for (int i = 1; i <= a[8]; i++) {
		cout << 7;
	}
	for (int i = 1; i <= a[7]; i++) {
		cout << 6;
	}
	for (int i = 1; i <= a[6]; i++) {
		cout << 5;
	}
	for (int i = 1; i <= a[5]; i++) {
		cout << 4;
	}
	for (int i = 1; i <= a[4]; i++) {
		cout << 3;
	}
	for (int i = 1; i <= a[3]; i++) {
		cout << 2;
	}
	for (int i = 1; i <= a[2]; i++) {
		cout << 1;
	}
	for (int i = 1; i <= a[1]; i++) {
		cout << 0;
	}
}
