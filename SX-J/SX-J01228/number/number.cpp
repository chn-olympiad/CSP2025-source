#include <bits/stdc++.h>
using namespace std;

int main() {
	//freopen("number.in", "r", stdin);
	//freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	string a;
	int b = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] <= '9' && s[i] >= 0) {
			a += s[i];
		}
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i + 1] > a[i]) {
			b = a[i];
			a[i] = a[i + 1];
			a[i + 1] = b;
			b = 0;
		}
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i + 1] > a[i]) {
			b = a[i];
			a[i] = a[i + 1];
			a[i + 1] = b;
			b = 0;
			continue;
		}
		break;
	}

	cout << a;
	return 0;
}
