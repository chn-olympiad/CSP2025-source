#include <bits/stdc++.h>
using namespace std;
char a[10005];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int x = 1;
	int t = s.size();
	for (int i = 0; i < t; i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			a[x] = s[i];
			x++;
		}
	}
	sort(a + 1, a + x);
	for (int i = x-1; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}
