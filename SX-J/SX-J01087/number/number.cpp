#include <bits/stdc++.h>
using namespace std;
string s;
char c;
map<char, int> m;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' and s[i] <= '9') {
			m[s[i]]++;
		}
	}
	for (int i = 57; i >= 48; i--) {
		if (m[char(i)] != 0) {
			for (int j = 1; j <= m[char(i)]; j++) {
				cout << i - '0';
			}
		}
	}
	return 0;
}
