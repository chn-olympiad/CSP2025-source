#include <bits/stdc++.h>
using namespace std;
string s;
int a[10];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[int(s[i] - '0')]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		if (a[i] != 0) {
			while (a[i]--) {
				cout << i;
			}
		}
	}
	return 0;
}
