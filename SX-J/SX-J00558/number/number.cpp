#include <bits/stdc++.h>
using namespace std;

long long a[15] = {};

string s, b = {};

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i <= s.size() - 1; i++) {
		if (s[i] == '1')
			a[1]++;
		if (s[i] == '2')
			a[2]++;
		if (s[i] == '0')
			a[0]++;
		if (s[i] == '3')
			a[3]++;
		if (s[i] == '4')
			a[4]++;
		if (s[i] == '5')
			a[5]++;
		if (s[i] == '6')
			a[6]++;
		if (s[i] == '7')
			a[7]++;
		if (s[i] == '8')
			a[8]++;
		if (s[i] == '9')
			a[9]++;
	}
	for (int i = 1; i <= 1000000; i++) {
		if (a[9] > 0) {
			a[9]--;
			b += "9";
		} else
			break;
	}
	for (int i = 1; i <= 1000000; i++) {
		if (a[8] > 0) {
			b += "8";
			a[8]--;
		} else
			break;
	}
	for (int i = 1; i <= 1000000; i++) {
		if (a[7] > 0) {
			a[7]--;
			b += "7";
		} else
			break;
	}
	for (int i = 1; i <= 1000000; i++) {
		if (a[6] > 0) {
			a[6]--;
			b += "6";
		} else
			break;
	}
	for (int i = 1; i <= 1000000; i++) {
		if (a[5] > 0) {
			a[5]--;
			b += "5";
		} else
			break;
	}
	for (int i = 1; i <= 1000000; i++) {
		if (a[4] > 0) {
			a[4]--;
			b += "4";
		} else
			break;
	}
	for (int i = 1; i <= 1000000; i++) {
		if (a[3] > 0) {
			a[3]--;
			b += "3";
		} else
			break;
	}
	for (int i = 1; i <= 1000000; i++) {
		if (a[2] > 0) {
			a[2]--;
			b += "2";
		} else
			break;
	}
	for (int i = 1; i <= 1000000; i++) {
		if (a[1] > 0) {
			a[1]--;
			b += "1";
		} else
			break;
	}
	for (int i = 1; i <= 1000000; i++) {
		if (a[0] > 0) {
			a[0]--;
			b += "0";
		} else
			break;
	}
	cout << b;
	return 0;
}
