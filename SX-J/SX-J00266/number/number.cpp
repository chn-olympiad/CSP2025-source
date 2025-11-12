#include <bits/stdc++.h>
using namespace std;
string s;
char c[1000000];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int t = 1;
	for (int i = 0; i <= s.length(); i++) {
		if (s[i] >= 48 && s[i] <= 58) {
			c[t] = s[i];
			t++;
		}
	}
	sort (c + 1, c + t + 1);
	for (int i = t; i >= 1; i--) {
		cout << c[i];
	}
	return 0;
}
