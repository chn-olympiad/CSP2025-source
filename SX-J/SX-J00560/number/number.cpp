#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i <= s.length(); i++) {
		if (s[i] == '0') {
			cout << 0;
		}
		if (s[i] == '1') {
			cout << 1;
		}
		if (s[i] == '2') {
			cout << 2;
		}
		if (s[i] == '3') {
			cout << 3;
		}
		if (s[i] == '4') {
			cout << 4;
		}
		if (s[i] == '5') {
			cout << 5;
		}
		if (s[i] == '6') {
			cout << 6;
		}
		if (s[i] == '7') {
			cout << 7;
		}
		if (s[i] == '8') {
			cout << 8;
		}
		if (s[i] == '9') {
			cout << 9;
		}
		return 0;
	}
}