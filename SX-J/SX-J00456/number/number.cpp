#include <bits/stdc++.h>
using namespace std;
string a;
int num0, num1, num2, num3, num4, num5, num6, num7, num8, num9;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;

	cin >> s;
	for (int i = 0; i <= s.length(); i++) {
		if ((s[i] >= '0') && (s[i] <= '9')) {
			a += s[i];
		}

	}
	for (int i = 0; i <= a.length(); i++) {
		if (a[i] == '0') {
			num0++;
		} else if (a[i] == '1') {
			num1++;
		} else if (a[i] == '2') {
			num2++;
		} else if (a[i] == '3') {
			num3++;
		} else if (a[i] == '4') {
			num4++;
		} else if (a[i] == '5') {
			num5++;
		} else if (a[i] == '6') {
			num6++;
		} else if (a[i] == '7') {
			num7++;
		} else if (a[i] == '8') {
			num8++;
		} else if (a[i] == '9') {
			num9++;
		}
	}
	for (int i = 0; i < num9; i++) {
		cout << '9';
	}
	for (int i = 0; i < num8; i++) {
		cout << '8';
	}
	for (int i = 0; i < num7; i++) {
		cout << '7';
	}
	for (int i = 0; i < num6; i++) {
		cout << '6';
	}
	for (int i = 0; i < num5; i++) {
		cout << '5';
	}
	for (int i = 0; i < num4; i++) {
		cout << '4';
	}
	for (int i = 0; i < num3; i++) {
		cout << '3';
	}
	for (int i = 0; i < num2; i++) {
		cout << '2';
	}
	for (int i = 0; i < num1; i++) {
		cout << '1';
	}
	for (int i = 0; i < num0; i++) {
		cout << '0';
	}

	return 0;
}