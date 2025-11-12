#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	if (s.length() == 1) {
		cout << s;
		return 0;
	}
	for (int i = 0; i <= s.length() - 1; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] = -1;
		}
	}
	for (int j = 0; j <= s.length() - 1; j++) {

		for (int i = 0; i <= s.length() - 1; i++) {

			if (s[i] < s[i + 1 ] ) {
				swap(s[i], s[i + 1]);
			}
		}
	}
	cout << s;
	return 0;
}