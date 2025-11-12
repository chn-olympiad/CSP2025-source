#include <bits/stdc++.h>
using namespace std;
string s;
long long l, x;
map<int, int> ma;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	l = s.size();
	for (int i = 0; i <= l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			x = s[i] - '0';
			ma[x]++;
		}
	}
	if (ma[9] != 0) {
		while (ma[9]--) {
			cout << 9;
		}
	}
	if (ma[8] != 0) {
		while (ma[8]--) {
			cout << 8;
		}
	}
	if (ma[7] != 0) {
		while (ma[7]--) {
			cout << 7;
		}
	}
	if (ma[6] != 0) {
		while (ma[6]--) {
			cout << 6;
		}
	}
	if (ma[5] != 0) {
		while (ma[5]--) {
			cout << 5;
		}
	}
	if (ma[4] != 0) {
		while (ma[4]--) {
			cout << 4;
		}
	}
	if (ma[3] != 0) {
		while (ma[3]--) {
			cout << 3;
		}
	}
	if (ma[2] != 0) {
		while (ma[2]--) {
			cout << 2;
		}
	}
	if (ma[1] != 0) {
		while (ma[1]--) {
			cout << 1;
		}
	}
	if (ma[0] != 0) {
		while (ma[0]--) {
			cout << 0;
		}
	}
	return 0;
}
