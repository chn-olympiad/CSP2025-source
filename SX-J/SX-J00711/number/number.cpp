#include <bits/stdc++.h>
using namespace std;
int a[13];
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int tmp;
	int lth = s.length();
	for (int i = 0; i <= lth; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			tmp = (int)s[i] - '0';
			a[tmp]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (a[i] != 0) {
			a[i]--;
			cout << i;
		}
	}
	return 0;
}
