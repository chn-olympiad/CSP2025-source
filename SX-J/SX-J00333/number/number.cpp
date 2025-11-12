#include <bits/stdc++.h>
using namespace std;
string s;

bool cmp(char x, char y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int l = s.size();
	sort(s.begin(), s.end(), cmp);
	while (!((s[0] - '0') >= 0 && (s[0] - '0') <= 9) ) {
		s.erase(0, 1);
	}
	cout << s;
	return 0;
}