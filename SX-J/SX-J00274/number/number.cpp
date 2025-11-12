#include <bits/stdc++.h>
using namespace std;
int sz[20];

int main() {

	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] - '0' >= 1 && s[i] - '0' <= 9) {
			sz[s[i] - '0']++;
		}
		if (s[i] == '0')
			sz[0]++;
	}
	for (int i = 9; i >= 0; i--) {
		if (sz[i] != 0)
			for (int j = 1; j <= sz[i]; j++) {
				cout << i;
			}
	}
	return 0;
}
