#include <bits/stdc++.h>
using namespace std;
int c[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;

	for (int i = 0 ; i < s.size() ; i++) {
		if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6'
		        || s[i] == '7' || s[i] == '8' || s[i] == '9') {
			c[s[i] - '0']++;
		} else {
			continue;
		}
	}
	for (int i = 9; i >= 0; i--) {
		if (c[i] != 0) {
			for (int j = 0; j < c[i] ; j++) {
				cout << i;
			}
		} else {
			continue;
		}
	}


	return 0;
}
