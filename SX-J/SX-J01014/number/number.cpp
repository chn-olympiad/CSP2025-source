#include <bist/stdc++.h>
using namespace std;
string s;
string n;

bool cmp(x1, x2) {
	if (x1 > x2)
		return true;
	else
		return false;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 1; i <= 1010; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= s.size(); i++) {
		if (s[i] >= 0 && s[i] <= 9) {
			n[i].append(s[i]);
		}
	}
	sort(n + 1, n + n.size() + 1, cmp);
	for (int i = 1; i <= n.size(); i++) {
		cout << s[i];
	}
	return 0;
}
