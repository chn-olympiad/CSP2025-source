#include <bits/stdc++.h>
using namespace std;
int s1[1000005], m, u;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			s1[i] = s[i] - '0';
			m++;
		}
		if (s[i] == '0')
			u++;

	}
	sort(s1, s1 + s.size());
	if (u == m) {
		cout << 0;
		return 0;
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		if (m > 0)
			cout << s1[i];
		m--;
	}
	return 0;
}
