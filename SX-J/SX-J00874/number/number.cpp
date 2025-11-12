#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int n, l[9], e;
	cin >> s;
	for (int i = 1; i <= s.size; i++) {
		
		if (s[i] >= '0' && s[i] <= '9') {
			l[s[i]] += s[i];
		}
	}
	for (int i = 9; i >= 0; i--) {
		e = n[i] / i;
		while (e > 0) {
			e--;
			n = (n + l[i]) * 10;
		}
	}
	cout << n;
	return 0;
}
