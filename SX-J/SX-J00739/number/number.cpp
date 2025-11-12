#include <bits/stdc++.h>
using namespace std;
int a[100000];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int y = s.size();
	if (s.size() == 1) {
		cout << s;
		return 0;
	}
	int c = 0, m = -11111;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9 && s[i] - '0' > m) {
			a[i] = s[i] - '0';
			c++;
		}
	}
	sort(a, a + y);
	for (int i = c; i > 0; i--) {
		cout << a[i];
	}
	return 0;
}
