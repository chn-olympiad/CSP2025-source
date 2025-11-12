#include <bits/stdc++.h>
using namespace std;
string v[19];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, s1;
	long long len;
	cin >> s;
	len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9')
			v[s[i] - '0'] += s[i];
	}
	for (int i = 9; i >= 0; i--) {
		s1 = s1 + v[i];
	}
	cout << s1;
	return 0;
}
