#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s, t = "";
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			t += s[i];
	}
	for (int i = 0; i < t.size(); i++) {
		for (int j = 0; j < t.size(); j++) {
			if (t[j] - '0' < t[j + 1] - '0')
				swap(t[j], t[j + 1]);
		}
	}
	for (int i = 0; i < t.size(); i++) {
		cout << t[i];
	}
	return 0;
}
