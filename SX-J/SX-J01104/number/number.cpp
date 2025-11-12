#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int a[110] = {0};
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[s[i]]++;
			//cout << s[i];
		}
	}
	for (char  i = '9'; i >= '0'; i--) {
		if (a[i] != 0) {
			for (int j = 0; j < a[i]; j++ ) {
				cout << i;
			}
		}
	}
	return 0;
}