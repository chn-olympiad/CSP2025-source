#include <bits/stdc++.h>
using namespace std;
string s;
int f, q, x[1000010];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			f++;
			x[q] = s[i] - '0';
			q++;
		}
	}
	if (f == 1) {
		cout << x[0];
		return 0;	
	}
	sort(x, x + f);
	for (int i = f - 1; i >= 0; i--) cout << x[i];
	return 0;
}
