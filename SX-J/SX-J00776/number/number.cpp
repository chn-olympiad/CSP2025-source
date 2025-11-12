#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	int a[1010] = {0};
	int ma = 5;
	for (int i = 0; i < s.size(); i ++) {
		cin >> s[i];
	}
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] >= '1' && s[i] <= '9') {
			a[i] == s[i];
			continue;
		}
		s[i] ++;
	}
	for (int i = 0; i < s.size(); i ++) {
		if (ma < s[i]) {
			ma = s[i];
		}
	}
	cout << ma << endl;
	return 0;
}