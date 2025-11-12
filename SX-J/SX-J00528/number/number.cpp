#include <bits/stdc++.h>
using namespace std;

bool tfpd(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (tfpd(s[i], s[i + 1]) == false) {
			swap(s[i], s[i + 1]);
		}
	}
	for (int i = 0; i < s.length(); i++) {
		if (tfpd(s[i], s[i + 1]) == false) {
			swap(s[i], s[i + 1]);
		}
	}


	for (int i = 0; i < s.length(); i++) {
		cout << s[i];
	}

	return 0;
}