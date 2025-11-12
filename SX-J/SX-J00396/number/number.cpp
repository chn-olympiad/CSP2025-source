#include <bits/stdc++.h>
using namespace std;
int s[1000000];
string a[100];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int n = 0;
	int c = 0;
	for (int i = 1; i <= 1000000; i++) {
		cin >> s[i];
		n++;
		a[i] = s[i];
		if (a[i] == "\n") {
			continue;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (s[i] < s[i + 1]) {
			c = s[i];
			s[i] = s[i + 1];
			s[i + 1] = c;
		}
		if (s[i] > s[i - 1] && i > 1) {
			c = s[i - 1];
			s[i - 1] = s[i];
			s[i] = c;
		}
	}
	for (int i = 1; i <= 1; i++) {
		c = s[1];
		s[1] = s[2];
		s[2] = c;
	}
	for (int i = 1; i <= n; i++) {
		cout << s[i];
	}
	return 0;
}
