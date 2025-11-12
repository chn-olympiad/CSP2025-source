#include <bits/stdc++.h>
using namespace std;
int n, a[1000010], x;
int c;
string s;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i <= s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			c++;
			a[c] = s[i] - '0';
		}
	}
	sort(a + 1, a + c + 1);
	for (int i = c; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}