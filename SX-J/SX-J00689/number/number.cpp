#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	string str;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			str += s[i];
	}
	sort(str.begin(), str.end());
	for (int i = str.size() - 1; i >= 0; i--) {
		if (str[i] != ' ')
			cout << str[i];
	}
	cout << endl;
	return 0;
}