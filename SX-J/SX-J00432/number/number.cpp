#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int a[10], l = s.size();
	for (int i = 0; i < 9; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < l; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[s[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = a[i]; j > 0; j--) {
			cout << i;
		}
	}
	return 0;
}
