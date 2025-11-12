#include <bits/stdc++.h>
using namespace std;
string s;
long long n[1000005], zp = 1;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			n[zp] = s[i] - 48;
			zp++;
		}
	}
	sort(n + 1, n + zp);
	for (int i = zp - 1; i >= 1; i--) {
		cout << n[i];
	}
	return 0;
}
