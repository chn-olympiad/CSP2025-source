#include <bits/stdc++.h>
using namespace std;
int a[13];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i <= s.size() - 1; i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			int b = s[i] - '0';
			a[b]++;
		}
	}

	for (int i = 13; i >= 0; i--) {
		if (a[i] == 0) {
			continue;
		} else {
			for (int j = 1; j <= a[i]; j++) {
				cout << i;
			}
		}
	}
	return 0;
}