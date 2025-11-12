#include <bits/stdc++.h>
using namespace std;
string s;
int a[1005], maxx = INT_MIN, n, m;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	getline(cin, s);
	for (int i; ; i++) {
		if ((s[i] >= 'a' ) && (s[i] <= 'z')  || (s[i] >= '0' ) && (s[i] <= '9') ) {
			m++;
		} else {
			break;
		}
	}
	for (int i = 1; i <= m; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i];
			n++;
		}
	}
	sort( a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		cout << a[i];
	}
	return 0;
}
