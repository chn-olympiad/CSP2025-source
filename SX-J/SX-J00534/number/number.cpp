#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int t = s.size();
	int a[t];
	if (t == 1) {
		cout << s;
		return 0;
	}
	int o = 0;
	for (int i = 0; i < t; i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' < 10) {
			a[o] = s[i] - '0';
			o++;
		}
	}
	sort(a, a + o);
	for (int i = o - 1; i >= 0; i--) {
		cout << a[i];
	}
	return 0;

}
