#include <bits/stdc++.h>
using namespace std;
string l[1000005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			l[i] = s[i];
		}
	}
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < i + 1; j++) {
			if (l[j] < l[j + 1]) {
				string a = l[j];
				l[j] = l[j + 1];
				l[j + 1] = a;
			}
		}
	}
	for (int i = 0; i < s.size(); i++) {
		cout << l[i];
	}
	return 0;
}
