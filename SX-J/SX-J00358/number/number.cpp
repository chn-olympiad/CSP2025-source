#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int ans = 0, n = 0;
char b[1000005];

int main() {
	//freopen("number.in", "r", stdin);
	//freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < strlen(s) + 1; i++) {
		if ((s[i] >= '0') && (s[i] <= '9')) {
			b[n] = s[i];
			ans++;
			n++;
		} else {
			continue;
		}
	}
	sort(b, b + ans);
	for (int i = ans - 1; i >= 0; i--) {
		cout << b[i];
	}
	return 0;
}