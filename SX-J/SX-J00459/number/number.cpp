#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[10];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int b;
	for (int i = 0; i < long(s.size()); i++) {
		b = s[i] - '0';
		if (s[i] >= '0' && s[i] <= '9') {
			a[b]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		while (a[i]--) {
			cout << i;
		}
	}
	return 0;
}
