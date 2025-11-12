#include <bits/stdc++.h>
using namespace std;
string s, u;
long long n, ss, a[1000055], c;
bool  b[10000055];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	n = s.size();
	for (int i = 0; i <= n; i++) {
		if ( s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6'
		        || s[i] == '7' || s[i] == '8' || s[i] == '9') {
			u[i] = s[i];
			a[i] = int(s[i]) - 48;
			b[a[i]] = 1;
		}
		if (s[i] == '0' ) {
			c++;
		}
	}
	sort(a, a + n );
	for (int i = n - 1; i >= 0; i--) {
		if (b[a[i]] != 0 ) {
			cout << a[i];
		}
	}
	for (int i = 1; i <= c; i++) {
		cout << 0;
	}
	return 0;
}

