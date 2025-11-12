#include <bits/stdc++.h>
using namespace std;

bool cmp(char a, char b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, m;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			m += s[i];
	}
	sort(m.begin(), m.end(), cmp);
	cout << m;
	return 0;
}