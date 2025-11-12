#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c[10];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			c[(int)(s[i] - '0')]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= c[i]; j++) {
			cout << i;
		}
	}
	return 0;
}
