#include <bits/stdc++.h>
using namespace std;
string s[10005];
char a[10005];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 0; i <= 10005; i++) {
		cin >> a[i];
	}
	for (int i = 0; i <= 10005; i++) {
		if (a[i] - '0' == 0 || a[i] <= '9') {
			cout << s;
		} else {
			break;
		}
	}
	fcluse(stdin);
	fcluse(stdout);
	return 0;
}
