#include <bits/stdc++.h>
using namespace std;
string s, s1;

bool cmp(char xx, char xy) {
	if (xx > xy)
		return true;
	else
		return false;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int t = s.size();
	for (int i = 0; i < t; i++) {
		if (isdigit(s[i]) != 0) {
			s1 += s[i];
		}
	}
	sort(s1.begin(), s1.end(), cmp);
	cout << s1;
	return 0;
}
