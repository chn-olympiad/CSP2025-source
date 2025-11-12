#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	char s[100099];
	for (int i = 0 ; i < 100001 ; i++) {
		cin >> s[i];

	}
	for (int i = 9 ; i >= 0; i-- ) {
		for (int j = 1 ; j < 100001; j++ ) {
			if (s[j] == i + '0' - 1) {
				cout << s[j];
			}
		}
	}
	return 0;
}