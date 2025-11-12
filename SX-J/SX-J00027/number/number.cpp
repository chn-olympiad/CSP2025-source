#include <bits/stdc++.h>
using namespace std;
string s, a;
int b[10];

int main() {
	freopen("number.in", "r", std.in);
	freopen("number.out", "w", std.out);
	cin >> s;
	for (int i = 1; i <= 1000010; i++) {
		if (s[i] <= '9' && s[i] >= '0') {
		} else {
			s[i] = 'a';
		}
	}
	for (int i = 1; i <= 1000010; i++) {
		if (s[i] == '0') {
			b[0]++;
		} else if (s[i] == '1') {
			b[1]++;
		} else if (s[i] == '2') {
			b[2]++;
		} else if (s[i] == '3') {
			b[3]++;
		} else if (s[i] == '4') {
			b[4]++;
		} else if (s[i] == '5') {
			b[5]++;
		} else if (s[i] == '6') {
			b[6]++;
		} else if (s[i] == '7') {
			b[7]++;
		} else if (s[i] == '8') {
			b[8]++;
		} else if (s[i] == '9') {
			b[9]++;
		}
	}
	for (int i = 1; i <= 1000010; i++) {
		if (s[i] == '9') {
			while (b[9]--) {
				cout << 9;
			}
		}
		if (s[i] == '8') {
			while (b[8]--) {
				cout << 8;
			}
		}
		if (s[i] == '7') {
			while (b[7]--) {
				cout << 7;
			}
		}
		if (s[i] == '6') {
			while (b[6]--) {
				cout << 6;
			}
		}
		if (s[i] == '5') {
			while (b[5]--) {
				cout << 5;
			}
		}
		if (s[i] == '4') {
			while (b[4]--) {
				cout << 4;
			}
		}
		if (s[i] == '3') {
			while (b[3]--) {
				cout << 3;
			}
		}
		if (s[i] == '2') {
			while (b[2]--) {
				cout << 2;
			}
		}
		if (s[i] == '1') {
			while (b[1]--) {
				cout << 1;
			}
		}
		if (s[i] == '0') {
			while (b[0]--) {
				cout << 0;
			}
		}
	}
	return 0;
}
