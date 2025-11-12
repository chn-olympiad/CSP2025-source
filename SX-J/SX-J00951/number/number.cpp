#include <bits/stdc++.h>
using namespace std;
string s, a[1000005];
int  len;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	cin >> s;
	len = s.size();
	for (int i = 0; i < len; i++) {
		if (s[i] > 47 && s[i] < 58) {
			a[i] = s[i];
		}
	}
	sort(a, a + len + 1 );
	for (int i = len + 1; i > 1; i--) {
		cout << a[i];
	}
	return 0;
}
