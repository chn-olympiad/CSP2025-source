#include <bits/stdc++.h>
using namespace std;
string s;
int t[11], c = 10;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if ('0' <= s[i] && s[i] <= '9')
			t[s[i] - '0']++;
	}
	while (c--) {
		while (t[c]--)
			cout << c;
	}
	return 0;
}
