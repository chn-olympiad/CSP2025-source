#include <bits/stdc++.h>
using namespace std;
string s, x;
int cnt;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int len = s.size();
	if (len == 1)
		cout << s;
	for (int i = 0; i <= len; i++) {
		if (s[i] < '9')
			x[++cnt] = s[i];
	}
	for (int i = 1; i <= len; i++) {
		cout << x[i];
	}
	return 0;
}
