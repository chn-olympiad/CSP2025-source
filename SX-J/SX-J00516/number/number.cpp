#include <bits/stdc++.h>
using namespace std;
int a[58];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0;; i++) {
		if ((int(s[i])) <= 57) {
			a[int(s[i])]++;
		}
		if (s[i] == '\0') {
			break;
		}
	}
	for (int i = 57; i >= 48; i--) {
		if (a[i] != 0) {
			for (int j = 1; j <= a[i]; j++) {
				cout << i - 48;
			}
		}
	}
	return 0;
}