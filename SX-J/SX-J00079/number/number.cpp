#include <bits/stdc++.h>
using namespace std;
char s[1000000];
char a[1010];
char b[1010];
char c[1010];
long long len = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	len = strlen(s);
	for (int i = 0; i <= len; i++) {
		if (s[i] >= '0' && s[i] <= '9' && s[i] != ' ') {
			a[i] = s[i];
		}
	}
	for (int i = 0; i <= len; i++) {
		if (a[i] <= a[i + 1]) {
			c[i] = a[i + 1];
			a[i + 1] = a[i];
			a[i] = c[i];
		}
		cout << a[i];
	}
	return 0;
}