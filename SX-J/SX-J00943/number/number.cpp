#include <bits/stdc++.h>
using namespace std;
string s, ss;
char a[1000005];

bool cmp(char x, char y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i];
		}
	}
	sort(a + 0, a + 100000 + 1, cmp);
	for (int i = 0; i <= s.size(); i++) {
		if (a[i] == ' ') {
			break;
		} else {
			ss += a[i];
		}
	}
	cout << ss << endl;
	return 0;
}
