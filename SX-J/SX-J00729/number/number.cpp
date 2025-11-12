#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, a = "";
	int sum = 0;
	cin >> s;
	for (int i = 0; i <= s.size(); i++) {
		if (int(s[i]) >= 97 && int(s[i]) <= 123) {
			continue;
		} else {
			a += s[i];
			sum++;
		}
	}
	for (char i = 58; i >= 48; i--) {
		for (int j = 0; j <= sum; j++) {
			if (int(a[j]) == i) {
				cout << a[j];
			}
		}
	}
	return 0;
}