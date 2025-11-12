#include <bits/stdc++.h>
using namespace std;
int t[11];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			t[s[i] - '0']++;
			//cout << s[i] - '0' << endl;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < t[i]; j++)
			cout << i;
	}
}
