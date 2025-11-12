#include <bits/stdc++.h>
using namespace std;
string s;
int n[1001000], m = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			n[m] = s[i] - 48;
			m++;
		}
	}
	sort(n, n + m);
	for (int i = m - 1; i >= 0; i--) {
		cout << n[i];
	}
	return 0;
}
