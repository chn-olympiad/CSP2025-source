#include <bits/stdc++.h>
using namespace std;
string s, s1;

long long cmp(long long a, long long b) {
	if (a < b)
		return b;
	if (a > b)
		return a;
	if (a = b)
		return a;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, s);
	for (int i = sizeof(s); i > 0; --i) {
		if (s[i] == 'a' || s[i] == 'z') {
			s[i] = ' ';
		} else {
			s[i] = s[i];
			cmp(i, i + 1);
			s[i] = s[i];

		}
		cout << s[i];
	}
	return 0;
}
